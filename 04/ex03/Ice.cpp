/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:59:48 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 20:47:53 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << CONSTRUCTOR << "Ice default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src) {
  std::cout << CONSTRUCTOR << "Ice copy constructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
  (void)src;
  return *this;
}

Ice::~Ice() {
  std::cout << DESTRUCTOR << "Ice destructor called" << RESET << std::endl;
}

AMateria* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout << ACTION << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
