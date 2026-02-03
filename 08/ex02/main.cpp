/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:46:28 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/03 17:42:04 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  {
    std::cout << "=== Test básico del subject ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "-- > " << s.size() << std::endl;
  }
  {
    std::cout << "=== Test básico con std::list para comparar ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    // "top"
    std::cout << lst.back() << std::endl;

    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    ++it;
    --it;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  {
    std::cout << "=== Test iterator y const_iterator ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);

    std::cout << "-- Const iterator --" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();

    while (cit != cite) {
      // *cit = *cit + 1;
      std::cout << *cit << std::endl;
      ++cit;
    }

    std::cout << "-- Non-const iterator --" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
      *it = *it + 1;
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "-- Iterators as original stack iterators --" << std::endl;
    std::stack<int>::container_type::iterator copy_it = mstack.begin();
    std::cout << *copy_it << std::endl;
    std::stack<int>::container_type::const_iterator copy_cit = mstack.begin();
    std::cout << *copy_cit << std::endl;
  }
  {
    std::cout << "=== Test con reverse_iterator y const_reverse_iterator ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);

    std::cout << "-- Const reverse iterator --" << std::endl;
    MutantStack<int>::const_reverse_iterator cit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator cite = mstack.rend();

    while (cit != cite) {
      // *cit = *cit + 1;
      std::cout << *cit << std::endl;
      ++cit;
    }

    std::cout << "-- Non-const reverse iterator --" << std::endl;
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();

    while (it != ite) {
      *it = *it + 1;
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "-- Reverse iterators as original stack iterators --" << std::endl;
    std::stack<int>::container_type::reverse_iterator copy_it = mstack.rbegin();
    std::cout << *copy_it << std::endl;
    std::stack<int>::container_type::const_reverse_iterator copy_cit = mstack.rbegin();
    std::cout << *copy_cit << std::endl;
  }
  {
    std::cout << "=== stack methods work as expected ===" << std::endl;
    MutantStack<std::string> mstack;
    mstack.push("Hello");
    mstack.push("World");
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    std::cout << "Top element after pop: " << mstack.top() << std::endl;
    mstack.push("C++");
    std::cout << "New top element: " << mstack.top() << std::endl;
    std::cout << "Final size: " << mstack.size() << std::endl;

    for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
      std::cout << "Element: " << *it << std::endl;
    }

    mstack.pop();
    mstack.pop();
    std::cout << "Size after popping all elements: " << mstack.size() << std::endl;
  }
}
