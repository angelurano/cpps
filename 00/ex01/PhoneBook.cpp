/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 03:08:58 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/06 17:11:11 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
    : current_index_(0), total_contacts_(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
  contacts_[current_index_] = contact;
  current_index_ = (current_index_ + 1) % 8;
  if (total_contacts_ < 8) {
    total_contacts_++;
  } else {
    std::cout << "PhoneBook is full. Overwriting oldest contact." << std::endl;
  }
}

void PhoneBook::printColumn(const std::string& str) const {
  if (str.length() > 10) {
    std::cout << "|" << str.substr(0, 9) << ".";
  } else {
    int padding = 10 - str.length();
    std::cout << "|" << std::string(padding, ' ') << str;
  }
}

void PhoneBook::displayAllContacts() const {
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (int i = 0; i < total_contacts_; i++) {
    std::string index_str(1, i + '0');
    printColumn(index_str);
    printColumn(contacts_[i].getFirstName());
    printColumn(contacts_[i].getLastName());
    printColumn(contacts_[i].getNickname());
    std::cout << "|" << std::endl;
  }
  std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::displayContact(const std::string& index_str) const {
  if (index_str.length() != 1 || index_str[0] < '0' || index_str[0] >= '0' + total_contacts_) {
    std::cout << "Invalid index." << std::endl;
    return;
  }
  int index = index_str[0] - '0';
  const Contact& contact = contacts_[index];
  std::cout << "First Name: " << contact.getFirstName() << std::endl;
  std::cout << "Last Name: " << contact.getLastName() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
