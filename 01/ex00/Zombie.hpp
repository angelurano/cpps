/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:46:50 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 14:11:30 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <iostream>

class Zombie {

  private:
    std::string name_;

  public:
    Zombie(std::string& name);
    ~Zombie();

    void announce(void);

};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif
