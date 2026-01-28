/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:07:57 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 16:29:31 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

template <typename T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
const T& min(const T& a, const T& b) {
  if (a < b)
    return a;
  return b;
}

template <typename T>
const T& max(const T& a, const T& b) {
  if (a > b)
    return a;
  return b;
}

#endif
