/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:58:58 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 17:43:31 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>

class Fixed {
  private:
    static const int fracBits_;
    int rawBits_;

  public:
    Fixed();
    Fixed(const Fixed& from);
    Fixed& operator=(const Fixed& from);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(const int rawBits);
};

#endif
