/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:23:21 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 19:50:10 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

int main() {
  ClapTrap clap("Clappy");
  ScavTrap scav("Scavvy");
  FragTrap frag("Fraggy");

  // Functionality demonstration (FragTrap)
  frag.attack("Clappy");
  clap.takeDamage(frag.getAttackDamage());

  scav.attack("Fraggy");
  frag.takeDamage(scav.getAttackDamage());

  frag.highFivesGuys();
}
