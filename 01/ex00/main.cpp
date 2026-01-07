/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:46:30 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 14:15:00 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main() {
  Zombie *allocated;

  allocated = newZombie("Not chump");
  allocated->announce();

  randomChump("Chump");

  delete allocated;
}
