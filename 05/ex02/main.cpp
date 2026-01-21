/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 21:43:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

int main() {
  std::srand(std::time(0));

  std::cout << BOLD << CYAN << "=== Basic Behaviour tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 130);
      ShrubberyCreationForm shrub("home");

      std::cout << bureaucrat << std::endl;
      std::cout << shrub;

      bureaucrat.signForm(shrub);
      bureaucrat.executeForm(shrub);
      std::cout << GREEN << "SUCCESS: " << RESET << shrub << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 40);
      RobotomyRequestForm robot("R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << robot;

      bureaucrat.signForm(robot);

      std::cout << MAGENTA << "Testing 50%:" << RESET << std::endl;

      std::cout << BLUE << " Test 1." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 2." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 3." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 4." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 5." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 6." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 7." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << BLUE << " Test 8." << RESET << std::endl;
      bureaucrat.executeForm(robot);

      std::cout << std::endl << GREEN << "SUCCESS: " << RESET << robot << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 5);
      PresidentialPardonForm pardon("Ross Ulbricht");

      std::cout << bureaucrat << std::endl;
      std::cout << pardon;

      bureaucrat.signForm(pardon);
      bureaucrat.executeForm(pardon);
      std::cout << GREEN << "SUCCESS: " << RESET << pardon << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Not Signed Error Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 130);
      ShrubberyCreationForm shrub("home");

      std::cout << bureaucrat << std::endl;
      std::cout << shrub;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(shrub);
      std::cout << shrub << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 40);
      RobotomyRequestForm robot("R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << robot;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(robot);
      std::cout << robot << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 5);
      PresidentialPardonForm pardon("Ross Ulbricht");

      std::cout << bureaucrat << std::endl;
      std::cout << pardon;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(pardon);
      std::cout << pardon << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Grade Too Low to Execute Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat signer("Signer", 140);
      Bureaucrat executor("Executor", 140);
      ShrubberyCreationForm shrub("park");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << shrub;

      signer.signForm(shrub);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(shrub);
      std::cout << shrub << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat signer("Signer", 70);
      Bureaucrat executor("Executor", 50);
      RobotomyRequestForm robot("Android");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << robot;

      signer.signForm(robot);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(robot);
      std::cout << robot << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat signer("Signer", 20);
      Bureaucrat executor("Executor", 10);
      PresidentialPardonForm pardon("Convict");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << pardon;

      signer.signForm(pardon);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(pardon);
      std::cout << pardon << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Grade Too Low to Sign Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 150);
      ShrubberyCreationForm shrub("home");

      std::cout << bureaucrat << std::endl;
      std::cout << shrub;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(shrub);
      std::cout << shrub << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 100);
      RobotomyRequestForm robot("R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << robot;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(robot);
      std::cout << robot << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 50);
      PresidentialPardonForm pardon("Criminal");

      std::cout << bureaucrat << std::endl;
      std::cout << pardon;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(pardon);
      std::cout << pardon << std::endl;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
}
