/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:38:12 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:50:13 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index_(0) {
  for (int i = 0; i < 4; i++)
    learned_[i] = NULL;
  std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) : index_(0) {
  for (int i = 0; i < 4; i++)
    learned_[i] = NULL;
  *this = src;
  std::cout << "MateriaSource copy constructor called" << std::endl;
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
  for (int i = 0; i < index_; i++) {
    delete learned_[i];
  }
  std::cout << "MateriaSource destructor called" << std::endl;
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
