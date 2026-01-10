/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:41:57 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:22:06 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main() {
  ClapTrap clap1("Juan");
  ClapTrap clap2("Carlos");

  std::cout << std::endl;

  // Basic interaction
  clap1.setAttackDamage(5);
  clap2.setAttackDamage(3);

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());

  clap2.attack(clap1.getName());
  clap1.takeDamage(clap2.getAttackDamage());

  clap1.beRepaired(3);
  clap2.beRepaired(2);

  // Kill clap2
  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());

  // Check clap2 after being dead
  clap2.attack(clap1.getName());
  clap2.beRepaired(5);

  clap1.attack(clap2.getName());
  clap2.takeDamage(clap1.getAttackDamage());

  // Deplete clap1 energy points
  while (clap1.getEnergyPoints() > 0) {
    clap1.beRepaired(1);
  }

  // Try to act without energy points
  clap1.attack(clap2.getName());
  clap1.beRepaired(1);

  std::cout << std::endl;
}

