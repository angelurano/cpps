/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:03:53 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/11 13:34:56 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) : rpnStack_(src.rpnStack_) {}

RPN& RPN::operator=(const RPN& src) {
  if (this != &src) {
    rpnStack_ = src.rpnStack_;
  }
  return *this;
}

RPN::~RPN() {}

void RPN::addition() {
  if (rpnStack_.size() < 2) {
    throw std::runtime_error("Not enough operands for addition");
  }
  int b = rpnStack_.top();
  rpnStack_.pop();
  int a = rpnStack_.top();
  rpnStack_.pop();
  rpnStack_.push(a + b);
}

void RPN::subtraction() {
  if (rpnStack_.size() < 2) {
    throw std::runtime_error("Not enough operands for subtraction");
  }
  int b = rpnStack_.top();
  rpnStack_.pop();
  int a = rpnStack_.top();
  rpnStack_.pop();
  rpnStack_.push(a - b);
}

void RPN::multiplication() {
  if (rpnStack_.size() < 2) {
    throw std::runtime_error("Not enough operands for multiplication");
  }
  int b = rpnStack_.top();
  rpnStack_.pop();
  int a = rpnStack_.top();
  rpnStack_.pop();
  rpnStack_.push(a * b);
}

void RPN::division() {
  if (rpnStack_.size() < 2) {
    throw std::runtime_error("Not enough operands for division");
  }
  int b = rpnStack_.top();
  rpnStack_.pop();
  if (b == 0) {
    throw std::runtime_error("Division by zero");
  }
  int a = rpnStack_.top();
  rpnStack_.pop();
  rpnStack_.push(a / b);
}

void RPN::evaluate(const std::string& expression) {
  bool needSpace = false;
  for (size_t i = 0; i < expression.length(); i++) {
    char token = expression[i];
    if (std::isspace(token)) {
      needSpace = false;
      continue;
    } else if (needSpace) {
      throw std::runtime_error("Invalid expression: tokens must be separated by spaces");
    }

    if (std::isdigit(token)) {
      rpnStack_.push(token - '0');
    } else {
      switch (token) {
        case '+':
          addition();
          break;
        case '-':
          subtraction();
          break;
        case '*':
          multiplication();
          break;
        case '/':
          division();
          break;
        default:
          throw std::runtime_error(std::string("Invalid token: ") + token);
          break;
      }
    }
    needSpace = true;
  }
  if (rpnStack_.size() > 1) {
    throw std::runtime_error("Invalid expression: leftover operands");
  } else if (rpnStack_.empty()) {
    rpnStack_.push(0);
  }
  std::cout << rpnStack_.top() << std::endl;
  rpnStack_.pop();
}
