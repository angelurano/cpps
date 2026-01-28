/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:27:11 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 18:28:43 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <string>
#include <iostream>

void printlnStdout(const std::string& str) {
  std::cout << str << std::endl;
}

void uppercaseStr(std::string& str) {
  for (size_t i = 0; i < str.length(); i++) {
    str[i] = toupper(str[i]);
  }
}

void lowercaseStr(std::string& str) {
  for (size_t i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
}

int main() {
  std::string arr[] = {"Hello", "World", "iter", "template", "function", "in", "C++"};
  const size_t length = sizeof(arr) / sizeof(arr[0]);

  iter(arr, length, printlnStdout);
  std::cout << "----" << std::endl;
  iter(arr, length, uppercaseStr);
  iter(arr, length, printlnStdout);
  std::cout << "----" << std::endl;
  iter(arr, length, lowercaseStr);
  iter(arr, length, printlnStdout);
}
