/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:44:42 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 13:12:32 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  void (Harl::*levelsPtrs[])() = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };

  const std::string levels[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
  };

  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
      (this->*levelsPtrs[i])();
      return;
    }
  }
}

void Harl::debug() {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
