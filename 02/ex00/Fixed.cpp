/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:59:09 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 17:47:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits_ = 8;

Fixed::Fixed() : rawBits_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& from) {
  std::cout << "Copy constructor called" << std::endl;
  *this = from;
}

Fixed& Fixed::operator=(const Fixed& from) {
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &from) {
    this->rawBits_ = from.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return rawBits_;
}

void Fixed::setRawBits(const int rawBits) {
  std::cout << "setRawBits member function called" << std::endl;
  rawBits_ = rawBits;
}
