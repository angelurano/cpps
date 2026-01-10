/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:42:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:24:08 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << ITALIC << GRAY << "Default ClapTrap created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << ITALIC << GRAY << "ClapTrap " << name_ << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& from) {
  std::cout << ITALIC << GRAY << "ClapTrap copy created" << RESET << std::endl;
  *this = from;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& from) {
  if(this != &from) {
    name_ = from.name_;
    hitPoints_ = from.hitPoints_;
    energyPoints_ = from.energyPoints_;
    attackDamage_ = from.attackDamage_;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << ITALIC << GRAY << "ClapTrap " << name_ << " destroyed" << RESET << std::endl;
}

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
  std::cout << "Claptrap " << name_ << " attacks " << target << ", causing " << RED << attackDamage_ << RESET << " points of damage! " << ITALIC << "[Energy Points: " << energyPoints_ << "]" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "Claptrap " << name_ << " is already dead" << RESET << std::endl;
    return;
  }
  setHitPoints(hitPoints_ - static_cast<int>(amount));
  std::cout << "Claptrap " << name_ << " takes " << RED << amount << RESET << " points of damage! " << ITALIC << "[Hit Points: " << hitPoints_ << "]" << RESET << std::endl;
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
  std::cout << "Claptrap " << name_ << " is repaired by " << GREEN << amount << RESET << " points! " << ITALIC << "[Hit Points: " << hitPoints_ << ", Energy Points: " << energyPoints_ << "]" << RESET << std::endl;
}
