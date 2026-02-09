/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:03:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/09 13:44:09 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): exchangeRates_(src.exchangeRates_) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
  if (this != &src) {
    exchangeRates_ = src.exchangeRates_;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isValidDate(const std::string& date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
    return false;
  }

  std::string yearStr = date.substr(0, 4);
  if (!std::isdigit(yearStr[0]) || !std::isdigit(yearStr[1]) || !std::isdigit(yearStr[2]) || !std::isdigit(yearStr[3])) {
    return false;
  }

  std::string monthStr = date.substr(5, 2);
  if (!std::isdigit(monthStr[0]) || !std::isdigit(monthStr[1])) {
    return false;
  }

  std::string dayStr = date.substr(8, 2);
  if (!std::isdigit(dayStr[0]) || !std::isdigit(dayStr[1])) {
    return false;
  }

  int year = std::atoi(yearStr.c_str());
  int month = std::atoi(monthStr.c_str());
  int day = std::atoi(dayStr.c_str());

  if (year < 0) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1) return false;

  if (month == 2) {
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > (isLeap ? 29 : 28)) return false;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) return false;
  } else {
    if (day > 31) return false;
  }

  return true;
}

static bool isValidValue(const std::string& valueStr, double& value) {
  char* endPtr;
  value = std::strtod(valueStr.c_str(), &endPtr);
  while (std::isspace(*endPtr)) {
    endPtr++;
  }
  if (*endPtr != '\0') {
    return false;
  }

  if (value < 0 || value > 1000) {
    return false;
  }

  return true;
}

bool BitcoinExchange::isDateInRange(const std::string& date) const {
  if (exchangeRates_.empty()) {
    return false;
  }
  return date >= exchangeRates_.begin()->first;
}


void BitcoinExchange::loadExchangeRates() {
  std::ifstream file(DATABASE_FILE);
  if (!file.is_open()) {
    throw std::runtime_error("Couldn't open database file " DATABASE_FILE);
  }

  std::string line;
  std::getline(file, line);
  if (line != "date,exchange_rate") {
    throw std::runtime_error("Expected header 'date,exchange_rate' in database file");
  }
  while (std::getline(file, line)) {
    if (line.empty())
      continue;
    // TODO: Should I validate the date and value in the database file?
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos) {
      throw std::runtime_error("Invalid line in database file: '" + line + "'");
    }
    std::string date = line.substr(0, commaPos);
    std::string rateStr = line.substr(commaPos + 1);
    double value = std::atof(rateStr.c_str());
    exchangeRates_[date] = value;
  }
}

float BitcoinExchange::processInputLine(const std::string& line) const {
  std::string delimiter = " | ";

  size_t delimPos = line.find(delimiter);
  if (delimPos == std::string::npos) {
    throw std::runtime_error("Missing delimiter ' | ' in line => '" + line + "'");
  }

  std::string date = line.substr(0, delimPos);
  if (!isValidDate(date)) {
    throw std::runtime_error("Invalid date format in line => '" + line + "'");
  }

  if (!isDateInRange(date)) {
    throw std::runtime_error("No exchange rate available for line => '" + line + "'");
  }

  std::string valueStr = line.substr(delimPos + delimiter.length());
  double value;
  if (!isValidValue(valueStr, value)) {
    throw std::runtime_error("Invalid value in line => '" + line + "'");
  }

  std::map<std::string, float>::const_iterator it = exchangeRates_.lower_bound(date);

  if (it == exchangeRates_.end() || it->first != date) {
    --it;
  }

  float result = value * it->second;
  std::cout << date << " => " << value << " = " << result << std::endl;
  return result;
}
