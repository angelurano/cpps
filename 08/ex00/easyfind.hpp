/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:28:45 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/29 14:25:33 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <algorithm>
# include <exception>
# include <memory>
# include <iostream>

template <typename T>
typename T::const_iterator easyfind(const T& stl, int n);

class NotFoundException : public std::exception {
  public:
    virtual const char* what() const throw();
};

template <typename T>
void testWithStruct(const T& stl, int* arr);

# include "easyfind.tpp"

#endif
