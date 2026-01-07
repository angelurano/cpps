/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:26 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 19:01:43 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
# define HUMANA_HPP_

# include <string>
# include <iostream>

# include "Weapon.hpp"

class HumanA {
  private:
    std::string name_;
    Weapon& weapon_;

  public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();

    void attack();

};

#endif
