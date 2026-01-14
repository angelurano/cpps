/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:40:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 17:08:58 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
  private:
    Brain *brain_;

  public:
    Dog();
    Dog(const Dog& src);

    Dog& operator=(const Dog& src);

    ~Dog();

    const Brain* getBrain() const;
    void setBrain(const Brain& brain);

    void makeSound() const;
};

#endif
