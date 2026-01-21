/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:55:30 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 22:01:50 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("presidential pardon", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), target_(src.target_) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
  if (this != &src) {
    AForm::operator=(src);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const {
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

