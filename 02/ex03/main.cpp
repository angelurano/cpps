/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:03:57 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/09 17:00:40 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

#define RESET "\033[0m"
#define RED  "\033[1;31m"
#define GREEN  "\033[1;32m"
#define CYAN  "\033[1;36m"
#define YELLOW  "\033[1;33m"

static std::string getStr(bool val) {
  return val ? "INSIDE" : "OUTSIDE";
}

static void test(const Point& v1, const Point& v2, const Point& v3, const Point& p, bool expected) {
  std::cout << CYAN << "[ TEST ] " << RESET << "Triangle: {" << v1 << ", " << v2 << ", " << v3 << "} "
            << "- Point: " << p << std::endl;

  bool res = bsp(v1, v2, v3, p);

  if (res == expected) {
      std::cout << GREEN << " [ OK ] " << RESET << "Result: "
                << YELLOW << getStr(res) << RESET
                << " | Expected: "
                << YELLOW << getStr(expected) << RESET
                << std::endl;
  } else {
      std::cout << RED << " [ KO ] " << RESET << "Result: "
                << YELLOW << getStr(res) << RESET
                << " | Expected: "
                << YELLOW << getStr(expected) << RESET
                << std::endl;
  }
}

int main() {
  test(Point(2, 0), Point(0, 0), Point(0, 2), Point(0.5, 0.5), true);
  test(Point(2, 0), Point(0, 0), Point(0, 2), Point(0.9, 1), true);
  test(Point(2, 0), Point(0, 0), Point(0, 2), Point(1, 1), false);
  test(Point(2, 0), Point(0, 0), Point(0, 2), Point(2, 2), false);
  test(Point(2, 0), Point(0, 0), Point(0, 2), Point(0.01, 0.333), true);

  test(Point(-1, -1), Point(1, -1), Point(0, 1), Point(0.25, 0), true);
  test(Point(-1, -1), Point(1, -1), Point(0, 1), Point(0, -0.5), true);
  test(Point(-1, -1), Point(1, -1), Point(0, 1), Point(0, -1), false);
  test(Point(-1, -1), Point(1, -1), Point(0, 1), Point(-0.5, 0), false);
  test(Point(-1, -1), Point(1, -1), Point(0, 1), Point(0, 1), false);

}
