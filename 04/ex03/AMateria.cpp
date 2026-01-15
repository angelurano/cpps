/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:38:11 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 20:46:29 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
  std::cout << CONSTRUCTOR << "AMateria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& src) : type_(src.type_) {
  std::cout << CONSTRUCTOR << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria::AMateria(const std::string& type) : type_(type) {
  std::cout << CONSTRUCTOR << "AMateria type constructor called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
  (void)src;
  return *this;
}

AMateria::~AMateria() {
  std::cout << DESTRUCTOR << "AMateria destructor called" << RESET << std::endl;
}

const std::string& AMateria::getType() const {
  return type_;
}

void AMateria::use(ICharacter& target) {
  std::cout << ACTION << " * default attack " << type_ << " to " << target.getName() << " *" << RESET << std::endl;
}
