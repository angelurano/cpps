/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:02:46 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/09 13:42:28 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  BitcoinExchange btc;
  try {
    btc.loadExchangeRates();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);
  if (!inputFile.is_open()) {
    std::cerr << "Error: Couldn't open file " << argv[1] << std::endl;
    return 1;
  }

  std::string line;
  bool headerRead = false;
  bool emptyFile = true;
  while (std::getline(inputFile, line)) {
    if (line.empty())
      continue;
    emptyFile = false;
    if (!headerRead) {
      headerRead = true;
      if (line == "date | value") {
        continue;
      }
      std::cout << "Error: Expected header 'date | value', using line '" << line << "' as input" << std::endl;
    }
    try {
      btc.processInputLine(line);
    } catch (const std::exception& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  if (emptyFile) {
    std::cout << "Error: Input file is empty" << std::endl;
    return 1;
  }
}
