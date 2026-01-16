/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:21 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 20:49:43 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : isSigned_(false), gradeSign_(150), gradeExecute_(150) {}

Form::Form(const Form& src)
    : isSigned_(false),
      name_(src.name_),
      gradeSign_(src.gradeSign_),
      gradeExecute_(src.gradeExecute_) {}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
    : isSigned_(false),
      name_(name),
      gradeSign_(gradeSign),
      gradeExecute_(gradeExecute) {
  if (gradeSign_ < 1 || gradeExecute_ < 1) {
    throw GradeTooHighException();
  } else if (gradeSign_ > 150 || gradeExecute_ > 150) {
    throw GradeTooLowException();
  }
}

Form& Form::operator=(const Form& src) {
  if (this != &src) {
    isSigned_ = src.isSigned_;
  }
  return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
  return name_;
}

bool Form::getIsSigned() const {
  return isSigned_;
}

int Form::getGradeSign() const {
  return gradeSign_;
}

int Form::getGradeExecute() const {
  return gradeExecute_;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeSign_) {
    throw GradeTooLowException();
  }
  isSigned_ = true;
}

std::ostream& operator<<(std::ostream& ostrm, const Form& form) {
  ostrm << "[Form] name=" << form.getName()
    << ", isSigned=" << (form.getIsSigned() ? "true" : "false")
    << ", gradeSign=" << form.getGradeSign()
    << ", gradeExecute=" << form.getGradeExecute()
    << std::endl;
  return ostrm;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high for the form";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low for the form";
}
