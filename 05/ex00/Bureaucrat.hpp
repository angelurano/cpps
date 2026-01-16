/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:39:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 18:36:08 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <exception>
# include <string>
# include <iostream>

class Bureaucrat {
  private:
    const std::string name_;
    int grade_;

    Bureaucrat();

  public:
    Bureaucrat(const Bureaucrat& src);

    Bureaucrat(const std::string &name, int grade);

    Bureaucrat& operator=(const Bureaucrat& src);

    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
      public:
        // throw() is noexcept in recent versions
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& ostrm, const Bureaucrat& bureaucrat);

#endif
