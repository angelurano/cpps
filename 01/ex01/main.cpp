/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:49:46 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 15:43:54 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  Zombie *zombies;

  int kN = 5;
  std::cout << "Creating " << kN << " zombies:" << std::endl;

  zombies = zombieHorde(kN, "juan");
  for (int i = 0; i < kN; i++) {
    std::cout << "\tZombie index " << i << ": ";
    zombies[i].announce();
  }
  delete[] zombies;
}
