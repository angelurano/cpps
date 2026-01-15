/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:14:08 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 14:14:45 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP_
# define IMATERIASOURCE_HPP_

# include "AMateria.hpp"

class IMateriaSource {
  public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif
