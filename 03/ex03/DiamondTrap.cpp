/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:54:45 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:28:40 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("_clap_name"), FragTrap(), ScavTrap(), name_("") {
  hitPoints_ = FragTrap::defaultHitPoints_;
  energyPoints_ = ScavTrap::defaultEnergyPoints_;
  attackDamage_ = FragTrap::defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "Default DiamondTrap created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name_(name) {
  hitPoints_ = FragTrap::defaultHitPoints_;
  energyPoints_ = ScavTrap::defaultEnergyPoints_;
  attackDamage_ = FragTrap::defaultAttackDamage_;
  std::cout << ITALIC << GRAY << "DiamondTrap " << name_ << " created" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src), FragTrap(src), ScavTrap(src) {
  name_ = src.name_;
  std::cout << ITALIC << GRAY << "DiamondTrap copy created" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
  if (this != &src) {
    ScavTrap::operator=(src);
    FragTrap::operator=(src);
    name_ = src.name_;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << ITALIC << GRAY << "DiamondTrap " << name_ << " destroyed" << RESET << std::endl;
}

void DiamondTrap::setName(const std::string& name) {
  name_ = name;
  ClapTrap::setName(name + "_clap_name");
}

const std::string& DiamondTrap::getName() const {
  return name_;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
  if (hitPoints_ <= 0) {
    std::cout << ITALIC << YELLOW << "DiamondTrap " << name_ << " is dead and cannot reveal its identity." << RESET << std::endl;
    return;
  }
  std::cout << ITALIC << CYAN << "DiamondTrap name: " << name_ << ", ClapTrap name: " << ClapTrap::getName() << RESET << std::endl;
}
