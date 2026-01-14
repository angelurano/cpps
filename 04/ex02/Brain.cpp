/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:17:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 22:36:33 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

const std::string Brain::nfound = "Idea not found";

Brain::Brain() {
  std::cout << "Brain basic constructor called" << std::endl;
}

Brain::Brain(const Brain& src) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = src;
}

Brain& Brain::operator=(const Brain& src) {
  if (this != &src) {
    for (int i = 0; i < 100; i++) {
      _ideas[i] = src._ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const {
  if (index < 0 || index >= 100) {
    std::cout << "index " << index << " out of ideas range";
    return nfound;
  }
  return _ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
  if (index < 0 || index >= 100) {
    return;
  }
  _ideas[index] = idea;
}
