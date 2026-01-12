/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:53:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/12 20:30:19 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

# include <string>
# include <iostream>

class WrongAnimal {
  protected:
    std::string type_;

    WrongAnimal(const std::string& type);

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);

    WrongAnimal& operator=(const WrongAnimal& src);

    virtual ~WrongAnimal();

    const std::string& getType() const;
    void setType(const std::string& type);

    void makeSound() const;
};

#endif
