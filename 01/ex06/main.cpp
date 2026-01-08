/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:47:47 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 14:09:17 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Harl.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
    return (1);
  }

  Harl harl;

  harl.complain(argv[1]);
}
