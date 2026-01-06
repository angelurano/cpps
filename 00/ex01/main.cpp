/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 03:09:54 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/06 16:47:35 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

#define PROMPT "Enter command (ADD, SEARCH, EXIT): "

int getInput(const std::string& prompt, std::string& input) {
  do {
    std::cout << prompt;
    if (!std::getline(std::cin, input)) return 0;
    if (input.empty()) {
      std::cout << "Input cannot be empty. Try again." << std::endl;
    }
  } while (input.empty());
  return 1;
}

int main() {
  PhoneBook phone_book;

  std::string input;
  std::cout << PROMPT;
  while (std::getline(std::cin, input)) {
    if (input == "EXIT") break;
    else if (input == "ADD") {
      Contact new_contact;

      if (!getInput("Enter first name: ", input)) break;
      new_contact.setFirstName(input);

      if (!getInput("Enter last name: ", input)) break;
      new_contact.setLastName(input);

      if (!getInput("Enter nickname: ", input)) break;
      new_contact.setNickname(input);

      if (!getInput("Enter phone number: ", input)) break;
      new_contact.setPhoneNumber(input);

      if (!getInput("Enter darkest secret: ", input)) break;
      new_contact.setDarkestSecret(input);

      phone_book.addContact(new_contact);
    } else if (input == "SEARCH") {
      phone_book.displayAllContacts();
      std::cout << "Enter index to view details: ";
      std::string index_str;
      if (!std::getline(std::cin, index_str)) break;
      phone_book.displayContact(index_str);
    }
    std::cout << PROMPT;
  }
}
