/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:00:35 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 11:59:47 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void doTests(int argc, const char* argv[]) {
  for (int i = 0; i < argc; i++) {
    if (argc > 1) {
      std::cout << "===== " << i + 1 << ": \"" << argv[i] << "\" ====="<<std::endl;
    }
    try {
      ScalarConverter::convert(argv[i]);
    } catch (std::exception& e) {
      std::cout << "ERROR: " << e.what() << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    doTests(argc - 1, (const char **)(argv + 1));
  } else {
    const char* tests[] = {
      "a",
      "z",
      "0",
      "9",
      "42",
      "-42",
      "2147483647",
      "-2147483648",
      "2147483648",
      "-2147483649",
      "4.2f",
      "-4.2f",
      "4.2",
      "-4.2",
      "nan",
      "nanf",
      "+inf",
      "-inf",
      "+inff",
      "-inff",
      "non-numeric",
      "!",
      "340282346638528878701170114963097780224.0f",
      "340282346638528878701170114963097780225.0f",
      "340282346638528878701170114963097780225.0",
    };
    int len = sizeof(tests) / sizeof(tests[0]);
    doTests(len, tests);
  }
}
