/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:44:22 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:45:13 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("Character") {
  for (int i = 0; i < 4; i++)
    inventory_[i] = NULL;
  std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name_(name) {
  for (int i = 0; i < 4; i++)
    inventory_[i] = NULL;
  std::cout << "Character name constructor called" << std::endl;
}

Character::Character(const Character& src) {
  for (int i = 0; i < 4; i++)
    inventory_[i] = NULL;
  *this = src;
  std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& src) {
  if (this != &src) {
    for (int i = 0; i < 4; i++) {
      delete inventory_[i];
      inventory_[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
      if (src.inventory_[i] != NULL) {
        inventory_[i] = src.inventory_[i]->clone();
      }
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    delete inventory_[i];
  }
  std::cout << "Character destructor called" << std::endl;
}

const std::string& Character::getName() const {
  return name_;
}

void Character::equip(AMateria* m) {
  if (m == NULL) return;

  for (int i = 0; i < 4; i++) {
    if (inventory_[i] == NULL) {
      inventory_[i] = m;
      return;
    }
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= 4) return;
  if (inventory_[idx] == NULL) return;
  inventory_[idx]->use(target);
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4) return;
  inventory_[idx] = NULL;
}
