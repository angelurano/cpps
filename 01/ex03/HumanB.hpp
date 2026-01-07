/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:42 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 18:54:19 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanB {
  private:
    std::string name_;
    Weapon* weapon_;

  public:
    HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(Weapon& weapon);

    void attack();

};

#endif
