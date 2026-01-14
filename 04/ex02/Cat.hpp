/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:11:29 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 23:26:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
# define CAT_HPP_

# include "AAnimal.hpp"

class Cat : public AAnimal {
  private:
    Brain *brain_;

  public:
    Cat();
    Cat(const Cat& src);

    Cat& operator=(const Cat& src);

    ~Cat();

    const Brain* getBrain() const;
    void setBrain(const Brain& brain);

    void makeSound() const;
};

#endif
