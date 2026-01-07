/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:47:01 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 15:38:21 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
  std::cout << "Empty Zombie created" << std::endl;
}

Zombie::Zombie(const std::string& name) : name_(name) {
  std::cout << "Zombie " << name_ << " created" << std::endl;
}

Zombie::~Zombie() {
  std::cout << "Zombie " << name_ << " called destructor" << std::endl;
}

void Zombie::announce() const {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
  name_ = name;
}

std::string Zombie::getName() const {
  return name_;
}
