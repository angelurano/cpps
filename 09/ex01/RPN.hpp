/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:04:00 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/10 18:21:49 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP_
# define RPN_HPP_

# include <stack>
# include <string>
# include <stdexcept>
# include <iostream>

class RPN {
  private:
    std::stack<int> rpnStack_;

    void addition();
    void subtraction();
    void multiplication();
    void division();

  public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& rhs);
    ~RPN();

    void evaluate(const std::string& expression);
};

#endif
