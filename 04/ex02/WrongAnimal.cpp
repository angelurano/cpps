/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:53:43 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 20:27:16 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("") {
  std::cout << "WrongAnimal basic constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type_(type) {
  std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
  if (this != &src) {
    type_ = src.type_;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string& WrongAnimal::getType() const {
  return type_;
}

void WrongAnimal::setType(const std::string& type) {
  type_ = type;
}

void WrongAnimal::makeSound() const {
  std::cout << "*wrong animal silence*" << std::endl;
}
