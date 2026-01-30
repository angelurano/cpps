/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:32:51 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/30 21:31:30 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP_

# include <set>
# include <exception>
# include <stdexcept>
# include <stdint.h>

# define SPAN_LENGTH_ERROR "Span does not have enough elements to calculate a span"
# define SPAN_OVERFLOW_ERROR "Span container is full. Cannot add more elements"

class Span {
  private:
    std::set<int> numbers_;
    unsigned int maxSize_;
    unsigned int realSize_;

    Span();

  public:
    Span(unsigned int maxSize);
    Span(const Span& src);

    Span& operator=(const Span& src);

    ~Span();

    void addNumber(int n);

    template <typename I>
    void addNumber(I begin, I end) {
      for (I it = begin; it != end; ++it) {
        addNumber(*it);
      }
    }

    size_t shortestSpan() const;
    size_t longestSpan() const;
};

#endif
