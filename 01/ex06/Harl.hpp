/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:44:37 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/08 13:23:28 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
# define HARL_HPP_

# include <string>
# include <iostream>

class Harl {
  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

  public:
    Harl();
    ~Harl();

    void complain( std::string level );
};

#endif
