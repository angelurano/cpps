/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:11:19 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/02 15:50:27 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat basic constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
  if (this != &src) {
    Animal::operator=(src);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "meow =^._.^=" << std::endl;
}
