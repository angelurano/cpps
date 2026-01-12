/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:54:33 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 15:24:09 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# include <string>
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
    std::string name_;

  public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& src);

    DiamondTrap& operator=(const DiamondTrap& src);

    ~DiamondTrap();

    void setName(const std::string& name);
    const std::string& getName() const;

    void attack(const std::string& target);

    void whoAmI() const;
};

#endif
