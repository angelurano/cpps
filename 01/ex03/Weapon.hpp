/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:31:09 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/07 16:40:19 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon {
  private:
    std::string type_;

  public:
    Weapon(const std::string& type);
    ~Weapon();

    const std::string& getType() const;
    void setType(const std::string& type);
};

#endif
