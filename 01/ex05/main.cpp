/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:44:28 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 13:24:38 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int main() {
  Harl harl;

  std::cout << "Tests:" << std::endl;

  std::cout << std::endl << "Harl use of \"DEBUG\" (debug private member):" << std::endl;
  harl.complain("DEBUG");

  std::cout << std::endl << "Harl use of \"INFO\" (info private member):" << std::endl;
  harl.complain("INFO");

  std::cout << std::endl << "Harl use of \"WARNING\" (warning private member):" << std::endl;
  harl.complain("WARNING");

  std::cout << std::endl << "Harl use of \"ERROR\" (error private member):" << std::endl;
  harl.complain("ERROR");
}
