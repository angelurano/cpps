/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:21:31 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:25:32 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

const int FragTrap::defaultHitPoints_ = 100;
const int FragTrap::defaultEnergyPoints_ = 100;
const int FragTrap::defaultAttackDamage_ = 30;

FragTrap::FragTrap() : ClapTrap() {
  hitPoints_ = defaultHitPoints_;
  energyPoints_ = defaultEnergyPoints_;
  attackDamage_ = defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "Default FragTrap created" << RESET <<  std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  hitPoints_ = defaultHitPoints_;
  energyPoints_ = defaultEnergyPoints_;
  attackDamage_ = defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "FragTrap " << name_ << " created" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& from) : ClapTrap(from) {
  std::cout << ITALIC << GRAY << "FragTrap copy created" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& from) {
  if (this != &from) {
    ClapTrap::operator=(from);
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << ITALIC << GRAY << "FragTrap " << name_ << " destroyed" << RESET << std::endl;
}

void FragTrap::highFivesGuys() const {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "FragTrap " << name_ << " is dead and cannot request a high five :(" << RESET << std::endl;
    return;
  }
  std::cout << ITALIC << GREEN << "FragTrap " << name_ << " is requesting a high five!" << RESET << std::endl;
}
