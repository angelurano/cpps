/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:38:11 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:30:18 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& src) : type_(src.type_) {
  std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : type_(type) {
  std::cout << "AMateria type constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
  (void)src;
  return *this;
}

AMateria::~AMateria() {
  std::cout << "AMateria destructor called" << std::endl;
}

const std::string& AMateria::getType() const {
  return type_;
}

void AMateria::use(ICharacter& target) {
  std::cout << " * default attack " << type_ << " to " << target.getName() << " *" << std::endl;
}
