/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:13:43 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 19:46:34 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

int main() {
  ScavTrap scav("ScavPedro");
  ClapTrap clap("ClapLuis");

  // Basic interaction
  clap.setAttackDamage(3);

  clap.attack(scav.getName());
  scav.takeDamage(clap.getAttackDamage());

  // Kill clap
  scav.attack(clap.getName());
  clap.takeDamage(scav.getAttackDamage());

  scav.beRepaired(3);

  // Check clap after being dead
  scav.attack(clap.getName());
  clap.takeDamage(scav.getAttackDamage());

  // Deplete scav energy points
  scav.setEnergyPoints(1);
  scav.beRepaired(1);

  // Try to act without energy points
  scav.attack(clap.getName());
  scav.beRepaired(1);

  // Activate guard gate mode
  scav.guardGate();

  return 0;
}
