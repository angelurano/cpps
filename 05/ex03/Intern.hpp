/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 21:46:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 22:44:40 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP_
# define INTERN_HPP_

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# include <exception>

class Intern {
  private:
    AForm* makeShrubberyCreation(const std::string& target) const;
    AForm* makeRobotomyRequest(const std::string& target) const;
    AForm* makePresidentialPardon(const std::string& target) const;

  public:
    Intern();
    Intern(const Intern& src);

    Intern& operator=(const Intern& src);

    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target) const;

    class NotFoundException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif
