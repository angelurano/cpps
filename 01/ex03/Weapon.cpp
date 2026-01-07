/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:06 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 16:43:28 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
  return type_;
}

void Weapon::setType(const std::string& type) {
  type_ = type;
}
