/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:54:57 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:32 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"

# include <fstream>

class ShrubberyCreationForm : public AForm {
  private:
    const std::string target_;

    ShrubberyCreationForm();

  protected:
    void executeAction() const;

  public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

    ~ShrubberyCreationForm();

    class FileOpenException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif
