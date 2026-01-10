/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:42:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 18:10:30 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : hitPoints_(10), energyPoints_(10), attackDamage_(0) {}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {}

ClapTrap::ClapTrap(const ClapTrap& from) {
  *this = from;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& from) {
  if(this != &from) {
    this->name_ = from.getName();
    this->hitPoints_ = from.getHitPoints();
    this->energyPoints_ = from.getEnergyPoints();
    this->attackDamage_ = from.getAttackDamage();
  }
  return *this;
}

ClapTrap::~ClapTrap() {}

const std::string& ClapTrap::getName() const {
  return name_;
}

int ClapTrap::getHitPoints() const {
  return hitPoints_;
}

int ClapTrap::getEnergyPoints() const {
  return energyPoints_;
}

int ClapTrap::getAttackDamage() const {
  return attackDamage_;
}

void ClapTrap::setName(const std::string& name) {
  name_ = name;
}

void ClapTrap::setHitPoints(const int hitPoints) {
  if (hitPoints < 0) {
    hitPoints_ = 0;
    return;
  }
  hitPoints_ = hitPoints;
}

void ClapTrap::setEnergyPoints(const int energyPoints) {
  energyPoints_ = energyPoints;
}

void ClapTrap::setAttackDamage(const int attackDamage) {
  attackDamage_ = attackDamage;
}

void ClapTrap::attack(const std::string& target) {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is dead and cannot attack " << target << RESET << std::endl;
    return;
  } else if (energyPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is out of energy points and cannot attack " << target << RESET << std::endl;
    return;
  }
  energyPoints_--;
  std::cout << "Claptrap " << name_ << " attacks " << target << ", causing " << RED << attackDamage_ << RESET << " points of damage! " << ITALIC << GRAY << "[Energy Points: " << energyPoints_ << "]" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is already dead" << RESET << std::endl;
    return;
  }
  setHitPoints(hitPoints_ - static_cast<int>(amount));
  std::cout << "Claptrap " << name_ << " takes " << RED << amount << RESET << " points of damage! " << ITALIC << GRAY << "[Hit Points: " << hitPoints_ << "]" << RESET << std::endl;
  if (hitPoints_ <= 0) {
    std::cout << std::endl << RED << "Claptrap " << name_ << " is dead!" << RESET << std::endl << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is dead and cannot be repaired" << RESET << std::endl;
    return;
  } else if (energyPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is out of energy points and cannot be repaired" << RESET << std::endl;
    return;
  }
  setHitPoints(hitPoints_ + static_cast<int>(amount));
  energyPoints_--;
  std::cout << "Claptrap " << name_ << " is repaired by " << GREEN << amount << RESET << " points! " << ITALIC << GRAY << "[Hit Points: " << hitPoints_ << ", Energy Points: " << energyPoints_ << "]" << RESET << std::endl;
}
