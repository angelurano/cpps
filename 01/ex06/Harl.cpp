/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:44:42 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 14:12:25 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  const std::string levels[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
  };
  int i;
  for (i = 0; i < 4; i++)
    if (level == levels[i]) break;

  switch (i) {
    case 0:
      debug();
      // fallthrough
    case 1:
      info();
      // fallthrough
    case 2:
      warning();
      // fallthrough
    case 3:
      error();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
      break;
  }
}

void Harl::debug() {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
  std::cout << std::endl;
}

void Harl::info() {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
  std::cout << std::endl;
}

void Harl::warning() {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
  std::cout << std::endl;
}

void Harl::error() {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
  std::cout << std::endl;
}
