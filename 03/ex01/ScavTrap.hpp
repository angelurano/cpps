/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:14:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 19:34:10 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include "ClapTrap.hpp"

# include <string>
# include <iostream>

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& from);

    ScavTrap& operator=(const ScavTrap& from);

    ~ScavTrap();

    void attack(const std::string& target);

    void guardGate() const;
};

#endif
