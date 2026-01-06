/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 03:08:36 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/06 17:01:01 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook {

  private:
    Contact contacts_[8];
    int current_index_;
    int total_contacts_;

    void printColumn(const std::string& str) const;

  public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact& contact);
    void displayAllContacts() const;
    void displayContact(const std::string& index_str) const;
};

#endif
