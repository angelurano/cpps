/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:33:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/30 21:36:43 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
  // TODO: add tests to addNumber with iterators, and exception handling on full span and span with less than 2 elements
  Span sp(5);

  sp.addNumber(1);
  sp.addNumber(3);
  sp.addNumber(33);
  sp.addNumber(32);
  sp.addNumber(100);

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}
