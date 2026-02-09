/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:03:16 by migugar2          #+#    #+#             */
/*   Updated: 2026/02/09 13:25:05 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP_
# define BITCOINEXCHANGE_HPP_

# include <string>
# include <map>
# include <iostream>
# include <fstream>
# include <cstdlib>

# define DATABASE_FILE "data.csv"

class BitcoinExchange {
  private:
    std::map<std::string, float> exchangeRates_;

    bool isDateInRange(const std::string& date) const;

  public:
    BitcoinExchange();

    BitcoinExchange(const BitcoinExchange& src);

    BitcoinExchange& operator=(const BitcoinExchange& src);

    ~BitcoinExchange();

    void loadExchangeRates();
    float processInputLine(const std::string& line) const;

};

#endif
