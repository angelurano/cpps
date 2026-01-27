/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:28:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/27 19:52:36 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate() {
  int random = std::rand() % 3;

  switch (random) {
  case 0:
    return new A();
    break;

  case 1:
    return new B();
    break;

  default:
    return new C();
    break;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}

void identify(Base& p) {
  try {
    A& refA = dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    (void)refA;
    return;
  } catch (...) {} // const std::bad_cast&

  try {
    B& refB = dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    (void)refB;
    return;
  } catch (...) {}

  try {
    C& refC = dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    (void)refC;
    return;
  } catch (...) {}
}

int main() {
  std::srand(std::time(0));
  std::cout << "===== TEST GENERATE =====" << std::endl;
  {
    Base* basePtr = generate();

    std::cout << "Identify from pointer: ";
    identify(basePtr);

    std::cout << "Identify from reference: ";
    identify(*basePtr);

    delete basePtr;
  }
  std::cout << "====== TEST A ======" << std::endl;
  {
    Base* baseA = new A();

    std::cout << "Identify from pointer: ";
    identify(baseA);

    std::cout << "Identify from reference: ";
    identify(*baseA);

    delete baseA;
  }
  std::cout << "====== TEST B ======" << std::endl;
  {
    Base* baseB = new B();

    std::cout << "Identify from pointer: ";
    identify(baseB);

    std::cout << "Identify from reference: ";
    identify(*baseB);

    delete baseB;
  }
  std::cout << "====== TEST C ======" << std::endl;
  {
    Base* baseC = new C();

    std::cout << "Identify from pointer: ";
    identify(baseC);

    std::cout << "Identify from reference: ";
    identify(*baseC);

    delete baseC;
  }
}
