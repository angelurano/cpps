/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:30:27 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/03 18:09:41 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
// #include <array>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  int arrWithout42[] = {30, 11, 20, 21, 32, 11};

  std::srand(std::time(0));
  size_t len = sizeof(arrWithout42) / sizeof(arrWithout42[0]);
  int* arr = arrWithout42;

  std::cout << "Data (" << len << " elements):";
  for (size_t i = 0; i < len; i++)
    std::cout << " " << arr[i];
  std::cout << std::endl;

  {
    std::cout << std::endl << "=== Vector examples ===" << std::endl;
    std::vector<int> stl(arr, arr + len);
    testWithStruct(stl, arr);
  }

  {
    std::cout << std::endl << "=== List examples ===" << std::endl;
    std::list<int> stl(arr, arr + len);
    testWithStruct(stl, arr);
  }

  {
    std::cout << std::endl << "=== Deque examples ===" << std::endl;
    std::deque<int> stl(arr, arr + len);
    testWithStruct(stl, arr);
  }
}
