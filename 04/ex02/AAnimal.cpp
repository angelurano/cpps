/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:28:53 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 23:27:21 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("") {
  std::cout << "Animal basic constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type_(type) {
  std::cout << "Animal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
  if (this != &src) {
    type_ = src.type_;
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << "Animal destructor called" << std::endl;
}

const std::string& AAnimal::getType() const {
  return type_;
}

void AAnimal::setType(const std::string& type) {
  type_ = type;
}
