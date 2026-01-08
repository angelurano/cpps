/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:58:58 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 18:59:12 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>
# include <cmath>

class Fixed {
  private:
    static const int fracBits_;
    int rawBits_;

  public:
    Fixed();
    Fixed(const Fixed& from);
    Fixed& operator=(const Fixed& from);
    ~Fixed();

    Fixed(const int value);
    Fixed(const float value);

    int getRawBits() const;
    void setRawBits(const int rawBits);

    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& ostrm, const Fixed& fixed);

#endif
