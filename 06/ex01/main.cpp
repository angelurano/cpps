/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:11:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/27 19:21:12 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data = {
    42
  };
  std::cout << "Original data address: " << &data << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized data (uintptr_t): " << raw << std::endl;

  Data* deserializedData = Serializer::deserialize(raw);
  std::cout << "Deserialized data address: " << deserializedData << std::endl;
  std::cout << "Deserialized data example value: " << deserializedData->example << std::endl;
}
