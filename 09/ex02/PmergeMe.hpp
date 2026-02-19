/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:39:23 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/19 11:42:29 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <iostream>

class PmergeMe {
  private:
    std::vector<size_t> jacobsthal_;

    template <typename C>
    void mergeInsertionSort(C &stl);

    void generateJacobsthal(size_t n);

  public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    void prechargeJacobsthal(size_t n);

    void sortVector(std::vector<int> &vec);
    void sortDeque(std::deque<int> &deq);
};

template <typename C>
void PmergeMe::mergeInsertionSort(C &stl) {
  if (stl.size() <= 1)
    return;

  bool isOdd = stl.size() % 2 != 0;
  int straggler = 0;
  if (isOdd) {
    straggler = stl.back();
    stl.pop_back();
  }

  // first -> smaller (b), second -> bigger (a)
  typedef std::pair<int, int> Pair;
  std::vector<Pair> pairs;
  for (typename C::iterator it = stl.begin(); it != stl.end(); ++it) {
    int first = *it;
    ++it;
    int second = *it;
    if (first > second)
      pairs.push_back(std::make_pair(second, first));
    else
      pairs.push_back(std::make_pair(first, second));
  }

  C mainChain;
  for (size_t i = 0; i < pairs.size(); i++)
    mainChain.push_back(pairs[i].second);

  mergeInsertionSort(mainChain);

  C pendChain;
  std::vector<bool> used(pairs.size(), false);
  for (typename C::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
    for (size_t i = 0; i < pairs.size(); i++) {
      if (!used[i] && *it == pairs[i].second) {
        pendChain.push_back(pairs[i].first);
        used[i] = true;
        break;
      }
    }
  }

  if (isOdd)
    pendChain.push_back(straggler);

  if (pendChain.size() == 0) {
    stl = mainChain;
    return;
  }

  mainChain.insert(mainChain.begin(), pendChain[0]);

  std::vector<size_t> aPos(pairs.size());
  for (size_t i = 0; i < pairs.size(); i++)
    aPos[i] = i + 1;

  generateJacobsthal(pendChain.size());

  size_t prevJacobVal = 1; // 0, 1, [1], 3 ... <-- start from this 1 (b1)
  size_t jacobIdx = 3;

  while (prevJacobVal < pendChain.size()) {
    size_t jacobVal;
    if (jacobIdx < jacobsthal_.size())
      jacobVal = jacobsthal_[jacobIdx];
    else
      jacobVal = pendChain.size();
    if (jacobVal > pendChain.size())
      jacobVal = pendChain.size();

    for (size_t i = jacobVal - 1; i >= prevJacobVal; i--) {
      int valueToInsert = pendChain[i];

      typename C::iterator searchEnd;
      if (i < aPos.size()) {
        searchEnd = mainChain.begin();
        std::advance(searchEnd, aPos[i]);
      } else {
        searchEnd = mainChain.end();
      }

      typename C::iterator pos = std::lower_bound(mainChain.begin(), searchEnd, valueToInsert);
      size_t insertIdx = static_cast<size_t>(std::distance(mainChain.begin(), pos));
      mainChain.insert(pos, valueToInsert);

      for (size_t j = 0; j < aPos.size(); j++) {
        if (aPos[j] >= insertIdx)
          aPos[j]++;
      }
    }

    prevJacobVal = jacobVal;
    jacobIdx++;
  }

  stl = mainChain;
}

#endif
