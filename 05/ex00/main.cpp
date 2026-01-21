/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:37:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 21:40:23 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    std::cout << BOLD << CYAN << "=== Bureaucrat basic behaviour ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 75);
      std::cout << bureaucrat << std::endl;

      bureaucrat.incrementGrade();
      std::cout << bureaucrat << std::endl;

      bureaucrat.decrementGrade();
      std::cout << bureaucrat << std::endl;

      Bureaucrat bureaucrat2 = bureaucrat;
      std::cout << "Copy name " << bureaucrat2.getName() << ", grade "
        << bureaucrat2.getGrade() << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << BOLD << CYAN << "=== Bureaucrat increment throw error ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 0);
      bureaucrat.incrementGrade();
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << BOLD << CYAN << "=== Bureaucrat decrement throw error ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 150);
      bureaucrat.decrementGrade();
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << BOLD << CYAN << "=== Bureaucrat creation throw errors ===" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 151);
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
    try {
      Bureaucrat bureaucrat("Juan", -1);
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

}
