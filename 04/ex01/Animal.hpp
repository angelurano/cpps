/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:28:59 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 22:45:49 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <string>
# include <iostream>

# include "Brain.hpp"

class Animal {
  protected:
    std::string type_;

    Animal(const std::string& type);

  public:
    Animal();
    Animal(const Animal& src);

    Animal& operator=(const Animal& src);

    virtual ~Animal();

    const std::string& getType() const;
    void setType(const std::string& type);

    virtual void makeSound() const;
};

#endif
