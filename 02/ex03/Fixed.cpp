/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:59:09 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/09 11:53:54 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits_ = 8;

Fixed::Fixed() : rawBits_(0) { }

Fixed::Fixed(const Fixed& from) {
  *this = from;
}

Fixed::Fixed(const int value) {
  rawBits_ = value << fracBits_;
}

Fixed::Fixed(const float value) {
  rawBits_ = roundf(value * (1 << fracBits_));
}

Fixed& Fixed::operator=(const Fixed& from) {
  if(this != &from) {
    rawBits_ = from.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
  return rawBits_;
}

void Fixed::setRawBits(const int rawBits) {
  rawBits_ = rawBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(rawBits_) / (1 << fracBits_);
}

int Fixed::toInt() const {
  return rawBits_ >> fracBits_;
}

bool Fixed::operator>(const Fixed& comp) const {
  return getRawBits() > comp.getRawBits();
}

bool Fixed::operator<(const Fixed& comp) const {
  return getRawBits() < comp.getRawBits();
}

bool Fixed::operator>=(const Fixed& comp) const {
  return !(*this < comp);
}

bool Fixed::operator<=(const Fixed& comp) const {
  return !(*this > comp);
}

bool Fixed::operator==(const Fixed& comp) const {
  return getRawBits() == comp.getRawBits();
}

bool Fixed::operator!=(const Fixed& comp) const {
  return !(*this == comp);
}

Fixed Fixed::operator+(const Fixed& comp) const {
  Fixed res;
  res.setRawBits(getRawBits() + comp.getRawBits());
  return res;
}

Fixed Fixed::operator-(const Fixed& comp) const {
  Fixed res;
  res.setRawBits(getRawBits() - comp.getRawBits());
  return res;
}

Fixed Fixed::operator*(const Fixed& comp) const {
  Fixed res(toFloat() * comp.toFloat());
  return res;
}

Fixed Fixed::operator/(const Fixed& comp) const {
  if (comp.toFloat() == .0f) { // Safe Hardcode
    Fixed res;
    return res;
  }
  Fixed res(toFloat() / comp.toFloat());
  return (res);
}

Fixed& Fixed::operator--() {
  rawBits_--;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed cpy = *this;
  rawBits_--;
  return (cpy);
}

Fixed& Fixed::operator++() {
  rawBits_++;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed cpy = *this;
  rawBits_++;
  return (cpy);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
  return f1 <= f2 ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
  return f1 <= f2 ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
  return f1 >= f2 ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
  return f1 >= f2 ? f1 : f2;
}

std::ostream& operator<<(std::ostream& ostrm, const Fixed& fixed) {
  ostrm << fixed.toFloat();
  return ostrm;
}
