/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:30:13 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/29 11:41:09 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
  Array<int> arrInt(5);
  for (unsigned int i = 0; i < arrInt.size(); i++) {
    arrInt[i] = i * 10;
  }

  for (unsigned int i = 0; i < arrInt.size(); i++) {
    std::cout << "arrInt[" << i << "] = " << arrInt[i] << std::endl;
  }

  try {
    std::cout << arrInt[10] << std::endl;  // This should throw an exception
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  Array<std::string> arrStr(3);
  arrStr[0] = "Hello";
  arrStr[1] = "World";
  arrStr[2] = "!";
  for (unsigned int i = 0; i < arrStr.size(); i++) {
    std::cout << "arrStr[" << i << "] = " << arrStr[i] << std::endl;
  }

  try {
    std::cout << arrStr[5] << std::endl;
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}
