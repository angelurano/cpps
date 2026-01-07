/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:32 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 19:02:01 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
  : name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
