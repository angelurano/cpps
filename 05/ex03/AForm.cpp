/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:21 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 20:57:16 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : isSigned_(false), gradeSign_(150), gradeExecute_(150) {}

AForm::AForm(const AForm& src)
    : isSigned_(false),
      name_(src.name_),
      gradeSign_(src.gradeSign_),
      gradeExecute_(src.gradeExecute_) {}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute)
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

AForm& AForm::operator=(const AForm& src) {
  if (this != &src) {
    isSigned_ = src.isSigned_;
  }
  return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
  return name_;
}

bool AForm::getIsSigned() const {
  return isSigned_;
}

int AForm::getGradeSign() const {
  return gradeSign_;
}

int AForm::getGradeExecute() const {
  return gradeExecute_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > gradeSign_) {
    throw GradeTooLowException();
  }
  isSigned_ = true;
}

void AForm::execute(const Bureaucrat& executor) const {
  if (!isSigned_) {
    throw NotSignedException();
  } else if (executor.getGrade() > gradeExecute_) {
    throw GradeTooLowException();
  }
  executeAction();
}

std::ostream& operator<<(std::ostream& ostrm, const AForm& form) {
  ostrm << "[Form] name=" << form.getName()
    << ", isSigned=" << (form.getIsSigned() ? "true" : "false")
    << ", gradeSign=" << form.getGradeSign()
    << ", gradeExecute=" << form.getGradeExecute()
    << std::endl;
  return ostrm;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high for the form";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low for the form";
}

const char* AForm::NotSignedException::what() const throw() {
  return "Form is not signed";
}
