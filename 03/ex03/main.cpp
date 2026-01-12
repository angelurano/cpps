/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:56:08 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 15:27:05 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main() {
  DiamondTrap diamond("Diamondy");

  std::cout << std::endl;

  // Basic attacks and actions
  diamond.attack("Target1");
  diamond.takeDamage(30);
  diamond.beRepaired(20);
  diamond.whoAmI();

  // ScavTrap specific action
  diamond.guardGate();

  // FragTrap specific action
  diamond.highFivesGuys();

  // Energy depletion
  diamond.setEnergyPoints(1);
  diamond.attack("Target2");

  diamond.attack("Target3");
  diamond.beRepaired(10);
  diamond.whoAmI(); // Should print

  // Taking lethal damage
  diamond.takeDamage(1000);
  diamond.attack("Target4");
  diamond.beRepaired(10);
  diamond.whoAmI();

  std::cout << std::endl;
}
