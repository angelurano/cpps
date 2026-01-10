/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:23:21 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:21:41 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

int main() {
  FragTrap frag("Fraggy");

  std::cout << std::endl;

  // Simple examples
  frag.attack("Created");
  frag.takeDamage(50);
  frag.beRepaired(20);
  frag.highFivesGuys();

  // No energy points
  frag.setEnergyPoints(0);
  frag.attack("Created");
  frag.beRepaired(20);
  frag.highFivesGuys();

  // Manually killed FragTrap
  frag.setHitPoints(0);

  frag.attack("Created");
  frag.takeDamage(50);
  frag.beRepaired(20);
  frag.highFivesGuys();

  std::cout << std::endl;
}
