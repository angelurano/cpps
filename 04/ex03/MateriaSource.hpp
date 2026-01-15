/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:38:48 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 19:07:31 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# include <iostream>

class MateriaSource : public IMateriaSource {
  private:
    AMateria* learned_[4];
    int index_;

  public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);

    MateriaSource& operator=(const MateriaSource& src);

    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(const std::string& type);

};

#endif
