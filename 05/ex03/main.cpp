/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 23:37:21 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
  Intern intern;

  std::cout << BOLD << CYAN << "=== Intern Form Creation Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      AForm* form = intern.makeForm("shrubbery creation", "home");
      std::cout << GREEN << "SUCCESS: " << RESET << *form << std::endl;
      delete form;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      AForm* form = intern.makeForm("robotomy request", "R2D2");
      std::cout << GREEN << "SUCCESS: " << RESET << *form << std::endl;
      delete form;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      AForm* form = intern.makeForm("presidential pardon", "Ross Ulbricht");
      std::cout << GREEN << "SUCCESS: " << RESET << *form << std::endl;
      delete form;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- Unknown Form (error) -" << RESET << std::endl;
    try {
      AForm* form = intern.makeForm("unknown form", "target");
      std::cout << *form << std::endl;
      delete form;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Full Workflow Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 130);
      AForm* shrub = intern.makeForm("shrubbery creation", "garden");

      std::cout << bureaucrat << std::endl;
      std::cout << *shrub;

      bureaucrat.signForm(*shrub);
      bureaucrat.executeForm(*shrub);
      std::cout << GREEN << "SUCCESS: " << RESET << *shrub << std::endl;
      delete shrub;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 40);
      AForm* robot = intern.makeForm("robotomy request", "R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << *robot;

      bureaucrat.signForm(*robot);

      std::cout << MAGENTA << "Testing 50%:" << RESET << std::endl;

      std::cout << BLUE << " Test 1." << RESET << std::endl;
      bureaucrat.executeForm(*robot);

      std::cout << BLUE << " Test 2." << RESET << std::endl;
      bureaucrat.executeForm(*robot);

      std::cout << BLUE << " Test 3." << RESET << std::endl;
      bureaucrat.executeForm(*robot);

      std::cout << BLUE << " Test 4." << RESET << std::endl;
      bureaucrat.executeForm(*robot);

      std::cout << std::endl << GREEN << "SUCCESS: " << RESET << *robot << std::endl;
      delete robot;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 5);
      AForm* pardon = intern.makeForm("presidential pardon", "Ross Ulbricht");

      std::cout << bureaucrat << std::endl;
      std::cout << *pardon;

      bureaucrat.signForm(*pardon);
      bureaucrat.executeForm(*pardon);
      std::cout << GREEN << "SUCCESS: " << RESET << *pardon << std::endl;
      delete pardon;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Not Signed Error Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 130);
      AForm* shrub = intern.makeForm("shrubbery creation", "home");

      std::cout << bureaucrat << std::endl;
      std::cout << *shrub;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(*shrub);
      delete shrub;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 40);
      AForm* robot = intern.makeForm("robotomy request", "R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << *robot;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(*robot);
      delete robot;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 5);
      AForm* pardon = intern.makeForm("presidential pardon", "Criminal");

      std::cout << bureaucrat << std::endl;
      std::cout << *pardon;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.executeForm(*pardon);
      delete pardon;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }

  std::cout << std::endl << BOLD << CYAN << "=== Grade Too Low to Sign Tests ===" << RESET << std::endl;
  {
    std::cout << YELLOW << "- ShrubberyCreationForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 150);
      AForm* shrub = intern.makeForm("shrubbery creation", "home");

      std::cout << bureaucrat << std::endl;
      std::cout << *shrub;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(*shrub);
      delete shrub;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 100);
      AForm* robot = intern.makeForm("robotomy request", "R2D2");

      std::cout << bureaucrat << std::endl;
      std::cout << *robot;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(*robot);
      delete robot;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat bureaucrat("Bob", 50);
      AForm* pardon = intern.makeForm("presidential pardon", "Criminal");

      std::cout << bureaucrat << std::endl;
      std::cout << *pardon;

      std::cout << RED << "HANDLED: " << RESET;
      bureaucrat.signForm(*pardon);
      delete pardon;
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
      AForm* shrub = intern.makeForm("shrubbery creation", "park");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << *shrub;

      signer.signForm(*shrub);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(*shrub);
      delete shrub;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- RobotomyRequestForm -" << RESET << std::endl;
    try {
      Bureaucrat signer("Signer", 70);
      Bureaucrat executor("Executor", 50);
      AForm* robot = intern.makeForm("robotomy request", "Android");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << *robot;

      signer.signForm(*robot);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(*robot);
      delete robot;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
  {
    std::cout << YELLOW << "- PresidentialPardonForm -" << RESET << std::endl;
    try {
      Bureaucrat signer("Signer", 20);
      Bureaucrat executor("Executor", 10);
      AForm* pardon = intern.makeForm("presidential pardon", "Convict");

      std::cout << signer << std::endl;
      std::cout << executor << std::endl;
      std::cout << *pardon;

      signer.signForm(*pardon);

      std::cout << RED << "HANDLED: " << RESET;
      executor.executeForm(*pardon);
      delete pardon;
    } catch (std::exception& e) {
      std::cout << RED << "ERROR: " << RESET << e.what() << std::endl;
    }
  }
}
