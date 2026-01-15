/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:11:19 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 21:04:28 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain_(NULL) {
  brain_ = new Brain();
  std::cout << "Cat basic constructor called" << std::endl;
}

Cat::Cat(const Cat& src) : AAnimal(src), brain_(NULL) {
  brain_ = new Brain(*src.brain_);
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
  if (this == &src) {
    AAnimal::operator=(src);
    if (brain_ != NULL) {
      delete brain_;
    }
    brain_ = new Brain(*src.brain_);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  if (brain_ != NULL) {
    delete brain_;
  }
}

const Brain* Cat::getBrain() const {
  return brain_;
}

void Cat::setBrain(const Brain& brain) {
  if (brain_ == NULL) {
    brain_ = new Brain(brain);
  } else {
    *brain_ = brain;
  }
}

void Cat::makeSound() const {
  std::cout << "meow =^._.^=" << std::endl;
}
