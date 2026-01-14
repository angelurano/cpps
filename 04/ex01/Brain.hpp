/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:18:07 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 22:36:05 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <string>
# include <iostream>

class Brain {
  private:
    std::string _ideas[100];

  public:
    static const std::string nfound;

    Brain();
    Brain(const Brain& src);

    Brain& operator=(const Brain& src);

    ~Brain();

    const std::string& getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};


#endif
