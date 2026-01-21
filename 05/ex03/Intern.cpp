/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:45:59 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 23:46:39 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
  (void)src;
}

Intern& Intern::operator=(const Intern& src) {
  (void)src;
  return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubberyCreation(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequest(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardon(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
  const std::string names[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon",
  };
  AForm* (Intern::*makers[3])(const std::string&) const = {
    &Intern::makeShrubberyCreation,
    &Intern::makeRobotomyRequest,
    &Intern::makePresidentialPardon
  };

  for (int i = 0; i < 3; i++) {
    if (names[i] == name) {
      std::cout << "Intern creates " << names[i] << std::endl;
      return ((this)->*makers[i])(target);
    }
  }
  std::cout << "Intern cannot create " << name << std::endl;
  throw NotFoundException();
}

const char* Intern::NotFoundException::what() const throw() {
  return "Form name not found";
}
