/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:46:50 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 15:38:08 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <iostream>

class Zombie {

  private:
    std::string name_;

  public:
    Zombie();
    Zombie(const std::string& name);
    ~Zombie();

    void setName(const std::string& name);
    std::string getName() const;

    void announce() const;

};

Zombie *zombieHorde(int N, std::string name);

#endif
