/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:46 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:26:04 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

const int ScavTrap::defaultHitPoints_ = 100;
const int ScavTrap::defaultEnergyPoints_ = 50;
const int ScavTrap::defaultAttackDamage_ = 20;

ScavTrap::ScavTrap() : ClapTrap() {
  hitPoints_ = defaultHitPoints_;
  energyPoints_ = defaultEnergyPoints_;
  attackDamage_ = defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "Default ScavTrap created" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  hitPoints_ = defaultHitPoints_;
  energyPoints_ = defaultEnergyPoints_;
  attackDamage_ = defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "ScavTrap " << name << " created" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& from) : ClapTrap(from) {
  std::cout << ITALIC << GRAY << "ScavTrap copy created" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& from) {
  if (this != &from) {
    ClapTrap::operator=(from);
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << ITALIC << GRAY << "ScavTrap " << name_ << " destroyed" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "ScavTrap " << name_ << " is dead and cannot attack " << target << RESET << std::endl;
    return;
  } else if (energyPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "ScavTrap " << name_ << " is out of energy points and cannot attack " << target << RESET << std::endl;
    return;
  }
  energyPoints_--;
  std::cout << "ScavTrap "<< ITALIC << CYAN << "(type of ClapTrap) " << RESET << name_ << " attacks " << target << ", causing " << RED << attackDamage_ << RESET << " points of damage! " << ITALIC << "[Energy Points: " << energyPoints_ << "]" << RESET << std::endl;
}

void ScavTrap::guardGate() const {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "ScavTrap " << name_ << " is dead and cannot enter Gate Keeper mode." << RESET << std::endl;
    return;
  }
  std::cout << ITALIC << GREEN << "ScavTrap " << name_ << " is now in Gate Keeper mode." << RESET << std::endl;
}
