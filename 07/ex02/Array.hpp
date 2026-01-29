/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:30:02 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 19:57:45 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
# define ARRAY_HPP_

#include <cstddef>
#include <exception>

template <typename T>
class Array {
  private:
    T* ptr_;
    unsigned int size_;

  public:
    Array();
    Array(const unsigned int size);
    Array(const Array<T>& other);

    Array<T>& operator=(const Array<T>& src);

    virtual ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;

    class IndexOutOfBoundsException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

# include "Array.tpp"

#endif
