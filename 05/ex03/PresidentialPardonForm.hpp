/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:55:37 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:42 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP_
# define PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    const std::string target_;

    PresidentialPardonForm();

  protected:
    void executeAction() const;

  public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);

    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

    ~PresidentialPardonForm();
};

#endif
