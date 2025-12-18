/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:48:49 by migugar2          #+#    #+#             */
/*   Updated: 2025/12/18 23:58:31 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
		std::cout << std::endl;
	}
}
