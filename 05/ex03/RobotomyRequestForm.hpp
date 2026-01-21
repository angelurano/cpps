/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:55:13 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:47 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_

# include <cstdlib>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    const std::string target_;

    RobotomyRequestForm();

  protected:
    void executeAction() const;

  public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);

    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

    ~RobotomyRequestForm();
};

#endif
