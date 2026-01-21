/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 21:40:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

int main() {
  {
    std::cout << BOLD << CYAN << "=== Form basic behaviour ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Ana", 50);
      Form form("TaxForm", 75, 100);
      std::cout << bureaucrat << std::endl;
      std::cout << form << std::endl; // extra line

      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << BOLD << CYAN << "=== Form signing throw error ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Ana", 100);
      Form form("TaxForm", 75, 100);
      std::cout << bureaucrat << std::endl;
      std::cout << form << std::endl;

      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << BOLD << CYAN << "=== Form creation throw errors ===" << RESET << std::endl;
    try {
      Form form("TaxForm", 0, 100);
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
    try {
      Form form("TaxForm", 75, 151);
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
}
