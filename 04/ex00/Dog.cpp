/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:40:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 19:15:46 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog basic constructor called" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
  if (this != &src) {
    Animal::operator=(src);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}
