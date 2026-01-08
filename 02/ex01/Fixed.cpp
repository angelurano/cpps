/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:59:09 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 19:15:11 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const int value) {
  std::cout << "int constructor called" << std::endl;
  rawBits_ = value << fracBits_;
}

Fixed::Fixed(const float value) {
  std::cout << "float constructor called" << std::endl;
  rawBits_ = roundf(value * (1 << fracBits_));
}

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << fracBits_);
}

int Fixed::toInt() const {
  return rawBits_ >> fracBits_;
}

std::ostream& operator<<(std::ostream& ostrm, const Fixed& fixed) {
  ostrm << fixed.toFloat();
  return ostrm;
}

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
