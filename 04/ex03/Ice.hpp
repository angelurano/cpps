/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:57:23 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 15:12:17 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP_
# define ICE_HPP_

# include "AMateria.hpp"

class Ice : public AMateria {
  public:
    Ice();
    Ice(const Ice& src);

    Ice& operator=(const Ice& src);

    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
