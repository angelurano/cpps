/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:28:59 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 23:29:42 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP_
# define AANIMAL_HPP_

# include <string>
# include <iostream>

# include "Brain.hpp"

class AAnimal {
  protected:
    std::string type_;

    AAnimal(const std::string& type);

  public:
    AAnimal();
    AAnimal(const AAnimal& src);

    AAnimal& operator=(const AAnimal& src);

    virtual ~AAnimal();

    const std::string& getType() const;
    void setType(const std::string& type);

    virtual const Brain* getBrain() const = 0;
    virtual void setBrain(const Brain& brain) = 0;

    virtual void makeSound() const = 0;
};

#endif
