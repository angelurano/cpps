/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:26 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 20:55:14 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP_
# define AFORM_HPP_

# include <exception>
# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  private:
    bool isSigned_;
    const std::string name_;
    const int gradeSign_;
    const int gradeExecute_;

    AForm();

  protected:
    virtual void executeAction() const = 0;

  public:
    AForm(const AForm& src);
    AForm(const std::string& name, int gradeSign, int gradeExecute);

    AForm& operator=(const AForm& src);

    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeSign() const;
    int getGradeExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& ostrm, const AForm& form);

#endif
