/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:42:14 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/10 21:06:01 by migugar2         ###   ########.fr       */
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
# define CYAN "\033[1;36m"
# define ITALIC "\033[3m"
# define RESET "\033[0m"

class ClapTrap {
  protected:
    static const int defaultHitPoints_;
    static const int defaultEnergyPoints_;
    static const int defaultAttackDamage_;

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

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
