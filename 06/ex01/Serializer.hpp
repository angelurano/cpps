/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:40:16 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/27 19:21:02 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

# include <stdint.h>

struct Data {
  int example;
};

class Serializer {
  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

  private:
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& src);
    ~Serializer();
};

#endif
