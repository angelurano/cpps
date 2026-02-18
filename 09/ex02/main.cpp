/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:39:53 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/16 23:38:32 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
    return 1;
  }

  std::vector<int> vec;
  std::deque<int> deq;

  for (int i = 1; i < argc; i++) {
    int num = std::atoi(argv[i]);
    vec.push_back(num);
    deq.push_back(num);
  }
  for (size_t i = 0; i < vec.size(); i++) {
    for (size_t j = i + 1; j < vec.size(); j++) {
      if (vec[i] == vec[j]) {
        std::cerr << "Error: Duplicate number " << vec[i] << " found." << std::endl;
        return 1;
      }
    }
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
    elapsedVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
  }
  {
    clock_t start = clock();
    sorter.sortDeque(deq);
    clock_t end = clock();
    elapsedDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
  }

  std::cout << "After:";
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << " " << vec[i];
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << elapsedVector << " us" << std::endl;
  std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << elapsedDeque << " us" << std::endl;
}
