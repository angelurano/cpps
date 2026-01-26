/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:53:40 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/26 21:17:56 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_

# include <string>
# include <exception>
# include <iostream>
# include <limits.h>
# include <cmath>
# include <float.h>

class ScalarConverter {
  public:
    enum Type {
      kChar = 0,
      kInt,
      kFloat,
      kDouble,
      kLiteral
    };

    static void convert(const std::string& input);

    class NotValidInputException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();
};

#endif
