/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:33:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/02 14:32:59 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(NULL));

  std::cout << "=== Test básico del subject ===" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;

  std::cout << std::endl << "=== Test de diferencia 0 ===" << std::endl;
  Span spEqual = Span(3);
  spEqual.addNumber(42);
  spEqual.addNumber(42);
  spEqual.addNumber(42);
  std::cout << "Shortest span: " << spEqual.shortestSpan() << std::endl;
  std::cout << "Longest span: " << spEqual.longestSpan() << std::endl;

  std::cout << std::endl << "=== Test excepciones ===" << std::endl;
  try {
    sp.addNumber(42);
  } catch (const std::overflow_error& e) {
    std::cout << "Overflow exception: " << e.what() << std::endl;
  }

  Span empty(5);
  try {
    empty.shortestSpan();
  } catch (const std::length_error& e) {
    std::cout << "Length exception (empty): " << e.what() << std::endl;
  }

  Span one(5);
  one.addNumber(42);
  try {
    one.longestSpan();
  } catch (const std::length_error& e) {
    std::cout << "Length exception (1 element): " << e.what() << std::endl;
  }

  std::cout << std::endl << "=== Test con iteradores ===" << std::endl;
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(50);

  Span sp2(5);
  sp2.addNumber(vec.begin(), vec.end());
  std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

  std::cout << std::endl << "=== Test con 10,000 números aleatorios ===" << std::endl;
  Span sp3(10000);
  std::vector<int> randomNumbers;
  for (unsigned int i = 0; i < 10000; ++i) {
    int number = std::rand();
    // std::cout << (i == 0 ? "" : ", ") << number;
    randomNumbers.push_back(number);
  }
  sp3.addNumber(randomNumbers.begin(), randomNumbers.end());
  std::cout << std::endl;
  std::cout << "Numbers added: " << randomNumbers.size() << std::endl;
  std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
}
