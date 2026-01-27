/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:40:19 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/27 18:53:13 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& src) {
  (void)src;
}

Serializer& Serializer::operator=(const Serializer& src) {
  (void)src;
  return *this;
}

Serializer::~Serializer() {}
