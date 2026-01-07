/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:47:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 14:12:33 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string& name) : name_(name) {}

Zombie::~Zombie() {
  std::cout << "Zombie " << name_ << " called destructor" << std::endl;
}

void Zombie::announce( void ) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

