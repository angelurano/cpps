/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:32:56 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/30 21:34:55 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize_(0), realSize_(0) {}

Span::Span(unsigned int maxSize) : maxSize_(maxSize), realSize_(0) {}

Span::Span(const Span& src)
    : numbers_(src.numbers_),
      maxSize_(src.maxSize_),
      realSize_(src.realSize_) {}

Span& Span::operator=(const Span& src) {
  if (this != &src) {
    numbers_ = src.numbers_;
    maxSize_ = src.maxSize_;
    realSize_ = src.realSize_;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (realSize_ >= maxSize_) {
    throw std::overflow_error(SPAN_OVERFLOW_ERROR);
  }
  numbers_.insert(n);
  realSize_++;
}

size_t Span::shortestSpan() const {
  if (realSize_ < 2) {
    throw std::length_error(SPAN_LENGTH_ERROR);
  }

  if (realSize_ > numbers_.size()) {
    return 0;
  }

  size_t minSpan = SIZE_MAX;
  std::set<int>::iterator it = numbers_.begin();
  std::set<int>::iterator bef = it;
  ++it;
  for(; it != numbers_.end(); ++it, ++bef) {
    size_t diff = (*it) - (*bef);
    if (diff < minSpan) minSpan = diff;
  }

  return minSpan;
}

size_t Span::longestSpan() const {
  if (realSize_ < 2) {
    throw std::length_error(SPAN_LENGTH_ERROR);
  }

  return static_cast<size_t>(*numbers_.rbegin() - *numbers_.begin());
}
