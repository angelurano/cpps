/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:04:40 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/09 14:32:13 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP_
# define POINT_HPP_

# include "Fixed.hpp"
# include <iostream>

class Point {
  private:
    Fixed x_;
    Fixed y_;

  public:
    Point();
    Point(const float x, const float y);
    Point(const Point& from);

    Point& operator=(const Point& from);

    ~Point();

    void setX(const Fixed& x);
    void setY(const Fixed& y);
    const Fixed& getX() const;
    const Fixed& getY() const;
};

std::ostream& operator<<(std::ostream &ostrm, const Point& p);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
