/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:28:53 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 19:10:32 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("") {
  std::cout << "Animal basic constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type_(type) {
  std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal& src) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = src;
}

Animal& Animal::operator=(const Animal& src) {
  if (this != &src) {
    type_ = src.type_;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

const std::string& Animal::getType() const {
  return type_;
}

void Animal::setType(const std::string& type) {
  type_ = type;
}

void Animal::makeSound() const {
  std::cout << "*Silence*" << std::endl;
}
