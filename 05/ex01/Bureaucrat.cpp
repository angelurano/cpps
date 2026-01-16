/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:39:11 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 20:09:22 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade_(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name_(src.name_), grade_(src.grade_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
  if (this != &src) {
    // can't override a const
    grade_ = src.grade_;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
  return name_;
}

int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < 1) {
    throw GradeTooHighException();
  }
  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ + 1 > 150) {
    throw GradeTooLowException();
  }
  grade_++;
}

void Bureaucrat::signForm(Form& form) const {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
  }
}

std::ostream& operator<<(std::ostream& ostrm, const Bureaucrat& bureaucrat) {
  ostrm << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return ostrm;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}
