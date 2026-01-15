/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:40:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 21:04:34 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain_(NULL) {
  brain_ = new Brain();
  std::cout << "Dog basic constructor called" << std::endl;
}

Dog::Dog(const Dog& src): AAnimal(src), brain_(NULL) {
  brain_ = new Brain(*src.brain_);
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
  if (this != &src) {
    AAnimal::operator=(src);
    if (brain_ != NULL) {
      delete brain_;
    }
    brain_ = new Brain(*src.brain_);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  if (brain_ != NULL) {
    delete brain_;
  }
}

const Brain* Dog::getBrain() const {
  return brain_;
}

void Dog::setBrain(const Brain& brain) {
  if (brain_ == NULL) {
    brain_ = new Brain(brain);
  } else {
    *brain_ = brain;
  }
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}

