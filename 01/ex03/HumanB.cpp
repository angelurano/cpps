/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:50 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 18:52:46 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
  weapon_ = &weapon;
}

void HumanB::attack() {
  std::cout << name_;
  if (weapon_ != NULL) {
    std::cout << " attacks with their " << weapon_->getType();
  } else {
    std::cout << " has no weapon";
  }
  std::cout << std::endl;
}
