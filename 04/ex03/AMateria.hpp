/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:35:49 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 15:22:17 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

# include "ICharacter.hpp"

# include <iostream>
# include <string>

class AMateria {
  private:
    AMateria();

  protected:
    const std::string type_;

  public:
    AMateria(const AMateria& src);
    AMateria(const std::string& type);

    AMateria& operator=(const AMateria& src);

    virtual ~AMateria();

    const std::string& getType() const; // Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
