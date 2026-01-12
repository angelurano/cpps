/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:11:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 19:13:30 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat& src);

    Cat& operator=(const Cat& src);

    ~Cat();

    void makeSound() const;
};

#endif
