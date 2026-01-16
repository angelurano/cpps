/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:26 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 20:45:57 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_

# include <exception>
# include <string>
# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    bool isSigned_;
    const std::string name_;
    const int gradeSign_;
    const int gradeExecute_;

    Form();

  public:
    Form(const Form& src);
    Form(const std::string& name, int gradeSign, int gradeExecute);

    Form& operator=(const Form& src);

    ~Form();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeSign() const;
    int getGradeExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& ostrm, const Form& form);

#endif
