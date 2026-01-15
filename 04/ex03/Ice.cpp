/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:59:48 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:02:25 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src) {
  std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
  (void)src;
  return *this;
}

Ice::~Ice() {
  std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
