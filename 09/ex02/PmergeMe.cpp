/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:39:16 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/17 13:56:31 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
    : jacobsthal_(src.jacobsthal_) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
  if (this != &src) {
    jacobsthal_ = src.jacobsthal_;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::generateJacobsthal(size_t n) {
  if (jacobsthal_.empty()) {
    jacobsthal_.push_back(0);
    jacobsthal_.push_back(1);
  }
  size_t last = jacobsthal_.back();
  while (last < n) {
    size_t size = jacobsthal_.size();

    last = jacobsthal_[size - 1] + 2 * jacobsthal_[size - 2];
    jacobsthal_.push_back(last);
  }
}

void PmergeMe::prechargeJacobsthal(size_t n) {
  generateJacobsthal(n);
}

void PmergeMe::sortVector(std::vector<int>& vec) {
  mergeInsertionSort(vec);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
  mergeInsertionSort(deq);
}
