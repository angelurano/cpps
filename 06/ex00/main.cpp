/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:00:35 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/26 21:44:03 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      std::cout << "===== " << i << ": " << argv[i] << " ====="<< std::endl;
      try {
        ScalarConverter::convert(argv[i]);
      } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
      }
    }
  } else {
    // TODO: Add examples
  }
}
