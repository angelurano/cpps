/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:40:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 19:01:53 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog& src);

    Dog& operator=(const Dog& src);

    ~Dog();

    void makeSound() const;
};

#endif
