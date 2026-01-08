/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:58:58 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 19:57:50 by migugar2         ###   ########.fr       */
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
    Fixed(const int value);
    Fixed(const float value);

    Fixed& operator=(const Fixed& from);

    ~Fixed();

    int getRawBits() const;
    void setRawBits(const int rawBits);

    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed& comp) const;
    bool operator<(const Fixed& comp) const;
    bool operator>=(const Fixed& comp) const;
    bool operator<=(const Fixed& comp) const;
    bool operator==(const Fixed& comp) const;
    bool operator!=(const Fixed& comp) const;

    Fixed operator+(const Fixed& comp) const;
    Fixed operator-(const Fixed& comp) const;
    Fixed operator*(const Fixed& comp) const;
    Fixed operator/(const Fixed& comp) const;

    Fixed& operator--();
    Fixed operator--(int);
    Fixed& operator++();
    Fixed operator++(int);

    static Fixed& min(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);

    static Fixed& max(Fixed& f1, Fixed& f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& ostrm, const Fixed& fixed);

#endif
