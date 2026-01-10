/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:42:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 17:53:22 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <string>
# include <iostream>

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define GRAY "\033[1;30m"
# define ITALIC "\033[3m"
# define RESET "\033[0m"

class ClapTrap {
  private:
    std::string name_;
    int hitPoints_;
    int energyPoints_;
    int attackDamage_;

  public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& from);

    ClapTrap& operator=(const ClapTrap& from);

    ~ClapTrap();

    const std::string& getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;

    void setName(const std::string& name);
    void setHitPoints(const int hitPoints);
    void setEnergyPoints(const int energyPoints);
    void setAttackDamage(const int attackDamage);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
