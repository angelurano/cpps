/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 03:09:35 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/06 17:15:34 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const {
  return this->first_name_;
}

std::string Contact::getLastName() const {
  return this->last_name_;
}

std::string Contact::getNickname() const {
  return this->nickname_;
}

std::string Contact::getPhoneNumber() const {
  return this->phone_number_;
}

std::string Contact::getDarkestSecret() const {
  return darkest_secret_;
}

void Contact::setFirstName(const std::string& first_name) {
  first_name_ = first_name;
}

void Contact::setLastName(const std::string& last_name) {
  last_name_ = last_name;
}

void Contact::setNickname(const std::string& nickname) {
  nickname_ = nickname;
}

void Contact::setPhoneNumber(const std::string& phone_number) {
  phone_number_ = phone_number;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
  darkest_secret_ = darkest_secret;
}
