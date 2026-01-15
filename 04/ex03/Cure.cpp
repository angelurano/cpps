/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:43 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 20:47:20 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << CONSTRUCTOR << "Cure default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src) {
  std::cout << CONSTRUCTOR << "Cure copy constructor called" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& src) {
  (void)src;
  return *this;
}

Cure::~Cure() {
  std::cout << DESTRUCTOR << "Cure destructor called" << RESET << std::endl;
}

AMateria* Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
  std::cout << ACTION << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
