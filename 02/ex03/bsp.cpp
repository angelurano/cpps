/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:36:57 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/09 18:10:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getSide(Point const& first, Point const& second, Point const& point) {
  return (point.getX().toFloat() - second.getX().toFloat())
    * (first.getY().toFloat() - second.getY().toFloat())
    - (first.getX().toFloat() - second.getX().toFloat())
    * (point.getY().toFloat() - second.getY().toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed side1 = getSide(a, b, point);
  Fixed side2 = getSide(b, c, point);
  Fixed side3 = getSide(c, a, point);

  return (
    (side1 > 0 && side2 > 0 && side3 > 0)
    || (side1 < 0 && side2 < 0 && side3 < 0)
  );
}
