/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:27:02 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/28 17:33:30 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
# define ITER_HPP_

# include <cstdlib>

template <typename T, typename F>
void iter(T* arr, const size_t length, F f) {
  if (arr == NULL) return;

  for (size_t i = 0; i < length; i++) {
    f(arr[i]);
  }
}

#endif
