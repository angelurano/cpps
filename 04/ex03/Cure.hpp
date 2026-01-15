/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:12:43 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 15:12:59 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP_
# define CURE_HPP_

# include "AMateria.hpp"

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure& src);

    Cure& operator=(const Cure& src);

    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
