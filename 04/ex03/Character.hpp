/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:32:45 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:43:33 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "ICharacter.hpp"
# include "AMateria.hpp"

# include <iostream>
# include <string>

class Character : public ICharacter {
  private:
    std::string name_;
    AMateria* inventory_[4];

  public:
    Character();
    Character(const std::string& name);
    Character(const Character& src);

    Character& operator=(const Character& src);

    ~Character();

    const std::string& getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
