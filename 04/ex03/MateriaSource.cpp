/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:38:12 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 21:00:58 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index_(0) {
  for (int i = 0; i < 4; i++)
    learned_[i] = NULL;
  std::cout << CONSTRUCTOR << "MateriaSource default constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) : index_(0) {
  for (int i = 0; i < 4; i++)
    learned_[i] = NULL;
  *this = src;
  std::cout << CONSTRUCTOR << "MateriaSource copy constructor called" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
  if (this != &src) {
    index_ = src.index_;
    for (int i = 0; i < 4; i++) {
      delete learned_[i];
      learned_[i] = NULL;
    }
    for (int i = 0; i < index_; i++) {
      learned_[i] = src.learned_[i]->clone();
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << DESTRUCTOR << "MateriaSource destructor called" << RESET << std::endl;
  for (int i = 0; i < index_; i++) {
    delete learned_[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == NULL) return;

  if (index_ < 4) {
    learned_[index_] = m;
    index_++;
  }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
  for (int i = 0; i < index_; i++) {
    if (learned_[i] && type == learned_[i]->getType()) {
      return learned_[i]->clone();
    }
  }
  return NULL;
}
