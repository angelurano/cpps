/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:39:53 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/19 11:42:48 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <climits>

void parseData(int argc, char* argv[], std::vector<int> &vec, std::deque<int> &deq) {
  if (argc < 2) {
    throw std::invalid_argument("Invalid number of arguments.");
  }

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '\0') {
      throw std::invalid_argument("Empty string input found.");
    }
    char *endptr;
    long vall = std::strtol(argv[i], &endptr, 10);
    if (*endptr != '\0') {
      throw std::invalid_argument("Non-numeric input found.");
    }
    if (vall < 0 || vall > INT_MAX) {
      throw std::invalid_argument("Input value out of valid range.");
    }
    int num = static_cast<int>(vall);
    for (size_t j = 0; j < vec.size(); j++) {
      if (vec[j] == num) {
        throw std::invalid_argument("Duplicate value found.");
      }
    }
    vec.push_back(num);
    deq.push_back(num);
  }
}

double getElapsedMicroseconds(clock_t start, clock_t end) {
  return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

int main(int argc, char* argv[]) {
  std::vector<int> vec;
  std::deque<int> deq;

  try {
    parseData(argc, argv, vec, deq);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  std::cout << "Before:";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << " " << vec[i];
  }
  std::cout << std::endl;

  PmergeMe sorter;
  sorter.prechargeJacobsthal(static_cast<size_t>(argc - 1));

  double elapsedVector, elapsedDeque;
  {
    clock_t start = clock();
    sorter.sortVector(vec);
    clock_t end = clock();
    elapsedVector = getElapsedMicroseconds(start, end);
  }
  {
    clock_t start = clock();
    sorter.sortDeque(deq);
    clock_t end = clock();
    elapsedDeque = getElapsedMicroseconds(start, end);
  }

  std::cout << "After:";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << " " << vec[i];
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << elapsedVector << " us" << std::endl;
  std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << elapsedDeque << " us" << std::endl;
}
