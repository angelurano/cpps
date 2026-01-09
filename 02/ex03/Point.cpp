/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:04:45 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/09 14:33:58 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point& from) {
  *this = from;
}

Point& Point::operator=(const Point& from) {
  if (this != &from) {
    x_ = from.getX();
    y_ = from.getY();
  }
  return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const {
  return x_;
}

const Fixed& Point::getY() const {
  return y_;
}

void Point::setX(const Fixed& x) {
  x_ = x;
}

void Point::setY(const Fixed& y) {
  y_ = y;
}

std::ostream& operator<<(std::ostream& ostrm, const Point& p) {
  ostrm << "(" << p.getX() << ", " << p.getY() << ")";
  return ostrm;
}
