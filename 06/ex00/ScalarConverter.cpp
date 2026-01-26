/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:53:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/26 21:39:50 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isInf(double val) {
  return val == HUGE_VAL || val == -HUGE_VAL;
}

static bool isNaN(double val) {
  return val != val;
}

static bool converterLiteral(const std::string& input) {
  if (input == "nan" || input == "nanf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf\n" << std::endl;
    std::cout << "double: nan\n" << std::endl;
  } else if (input == "+inf" || input == "+inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (input == "-inf" || input == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else
    return false;
  return true;
}

static bool converterInt(const std::string& input, double &val) {
  if (input[input.size() - 1] == 'f') return false;
  size_t i = 0;
  if (input[i] == '+' || input[i] == '-') i++;
  for (i = i; i < input.size(); i++) {
    if (!isdigit(input[i])) return false;
  }
  long vall = strtol(input.c_str(), NULL, 10);
  if (vall < INT_MIN || vall > INT_MAX) {
    return false;
  }
  val = static_cast<double>(vall);
  return true;
}

static bool converterChar(const std::string& input, double &val) {
  if (input.size() != 1) return false;
  val = static_cast<double>(input[0]);
  return true;
}

static bool converterFloat(const std::string& input, double &val) {
  if (input[input.size() - 1] != 'f') return false;
  size_t i = 0;
  if (input[i] == '+' || input[i] == '-') i++;
  bool seenPoint = false;
  for (i = i; i < input.size() - 1; i++) {
    if (input[i] == '.') {
      if (seenPoint) return false;
      seenPoint = true;
    } else if (!isdigit(input[i]))
      return false;
  }
  if (!seenPoint) return false;
  val = strtod(input.c_str(), NULL);
  if (!isInf(val)) {
    if (val > FLT_MAX) {
      val = HUGE_VAL;
    } else if (val < -FLT_MAX) {
      val = -HUGE_VAL;
    }
  }
  return true;
}

static bool converterDouble(const std::string& input, double &val) {
  size_t i = 0;
  if (input[i] == '+' || input[i] == '-') i++;
  bool seenPoint = false;
  for (i = i; i < input.size() - 1; i++) {
    if (input[i] == '.') {
      if (seenPoint) return false;
      seenPoint = true;
    } else if (!isdigit(input[i]))
      return false;
  }
  if (!seenPoint) return false;
  val = strtod(input.c_str(), NULL);
  return true;
}

static void printChar(double val) {
  std::cout << "char: ";
  if (isNaN(val) || isInf(val) || val < CHAR_MIN || val > CHAR_MAX) {
    std::cout << "impossible" << std::endl;
  } else {
    char c = static_cast<char>(val);
    if (!std::isprint(c)) {
      std::cout << "Non displayable" << std::endl;
    } else {
      std::cout << c << std::endl;
    }
  }
}

static void printInt(double val) {
  std::cout << "int: ";
  if (isNaN(val) || isInf(val) || val < INT_MIN || val > INT_MAX) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(val) << std::endl;
  }
}

static void printFloat(double val) {
  std::cout << "float: ";
  if (isNaN(val)) {
    std::cout << "nanf" << std::endl;
  } else if (isInf(val)) {
    std::cout << (val > 0 ? "+inff" : "-inff") << std::endl;
  } else {
    float f = static_cast<float>(val);
    std::cout << f;
    if (f - static_cast<int>(f) == 0 && val > -1e6 && val < 1e6) {
      std::cout << ".0";
    }
    std::cout << "f" << std::endl;
  }
}

static void printDouble(double val) {
  std::cout << "double: ";
  if (val != val) {
    std::cout << "nan" << std::endl;
  } else if (isInf(val)) {
    std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
  } else {
    std::cout << val;
    if (val - static_cast<int>(val) == 0 && val > -1e6 && val < 1e6) {
      std::cout << ".0";
    }
    std::cout << std::endl;
  }
}

void ScalarConverter::convert(const std::string& input) {
  double val = 0;
  if (converterLiteral(input)) return;
  else if (converterInt(input, val)) {}
  else if (converterChar(input, val)) {}
  else if (converterFloat(input, val)) {}
  else if (converterDouble(input, val)) {}
  else throw NotValidInputException();

  printChar(val);
  printInt(val);
  printFloat(val);
  printDouble(val);
}

const char* ScalarConverter::NotValidInputException::what() const throw() {
  return "Input not valid: invalid type or input out of bounds";
}

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
  (void)src;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
  (void)src;
  return *this;
}

ScalarConverter::~ScalarConverter() {}
