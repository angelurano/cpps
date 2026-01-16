/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:37:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 18:55:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  {
    std::cout << "= Bureaucrat basic behaviour =" << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 75);
      std::cout << bureaucrat << std::endl;

      bureaucrat.incrementGrade();
      std::cout << bureaucrat << std::endl;

      bureaucrat.decrementGrade();
      std::cout << bureaucrat << std::endl;

      Bureaucrat bureaucrat2 = bureaucrat;
      std::cout << "Copy name " << bureaucrat2.getName() << ", grade "
        << bureaucrat2.getGrade() << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "= Bureaucrat increment throw error =" << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 0);
      bureaucrat.incrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "= Bureaucrat decrement throw error =" << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 150);
      bureaucrat.decrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "= Bureaucrat creation throw errors =" << std::endl;
    try {
      Bureaucrat bureaucrat("Juan", 151);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      Bureaucrat bureaucrat("Juan", -1);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

}
