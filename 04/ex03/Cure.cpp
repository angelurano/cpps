/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:43 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 18:59:39 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src) {
  std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& src) {
  (void)src;
  return *this;
}

Cure::~Cure() {
  std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
