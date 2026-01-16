/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:02:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 20:51:59 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  {
    std::cout << "= Form basic behaviour =" << std::endl;
    try {
      Bureaucrat bureaucrat("Ana", 50);
      Form form("TaxForm", 75, 100);
      std::cout << bureaucrat << std::endl;
      std::cout << form << std::endl; // extra line

      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "= Form signing throw error =" << std::endl;
    try {
      Bureaucrat bureaucrat("Ana", 100);
      Form form("TaxForm", 75, 100);
      std::cout << bureaucrat << std::endl;
      std::cout << form << std::endl;

      bureaucrat.signForm(form);
      std::cout << form << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "= Form creation throw errors =" << std::endl;
    try {
      Form form("TaxForm", 0, 100);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      Form form("TaxForm", 75, 151);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}
