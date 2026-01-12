/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:18:39 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:13:16 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

# include "ClapTrap.hpp"

# include <string>
# include <iostream>

class FragTrap : virtual public ClapTrap {
  protected:
    static const int defaultHitPoints_;
    static const int defaultEnergyPoints_;
    static const int defaultAttackDamage_;

  public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& from);

    FragTrap& operator=(const FragTrap& from);

    ~FragTrap();

    void highFivesGuys() const;
};

#endif
