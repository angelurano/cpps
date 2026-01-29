/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:29:47 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/29 14:24:45 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator easyfind(const T& stl, int n) {
  typename T::const_iterator it = std::find(stl.begin(), stl.end(), n);
  if (it == stl.end()) {
    throw NotFoundException();
  }
  return it;
}

const char* NotFoundException::what() const throw() {
  return "Member not found in struct";
}

template <typename T>
void testWithStruct(const T& stl, int* arr) {
  try {
    int searchToFound = arr[std::rand() % stl.size()];
    std::cout << "Searching for " << searchToFound << ": ";
    typename T::const_iterator it = easyfind(stl, searchToFound);
    std::cout << "Found (iterator value): " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::cout << "Searching for 42: ";
    typename T::const_iterator it = easyfind(stl, 42);
    std::cout << "Found (iterator value): " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
