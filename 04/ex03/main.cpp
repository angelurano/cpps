/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:42 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/16 12:45:10 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main() {
  std::cout << LOG "========== subject test ==========" << RESET << std::endl;
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
  }
  std::cout << LOG "========== features test ==========" << RESET << std::endl;
  {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << LOG << "Trying to learn more than 4 materias:" << RESET << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice()); // Should not be learned

    std::cout << LOG << "Creating characters Cloud (name constructor) and Tifa (copy constructor)" << RESET << std::endl;
    Character* cloud = new Character("Cloud");
    AMateria* m1 = src->createMateria("ice");
    cloud->equip(m1);

    Character* tifa = new Character(*cloud);

    std::cout << LOG << "Cloud (unequipped):" << RESET << std::endl;;
    cloud->unequip(0);
    cloud->use(0, *tifa);

    std::cout << LOG << "Tifa (copy):" << RESET << std::endl;
    tifa->use(0, *cloud);

    std::cout << LOG << "Equipping Tifa with more materias:" << RESET << std::endl;
    AMateria* tmp = src->createMateria("cure");
    tifa->equip(tmp);
    tmp = src->createMateria("cure");
    tifa->equip(tmp);
    tmp = src->createMateria("cure");
    tifa->equip(tmp); // Full

    std::cout << LOG << "Creating a materia that doesn't exist:" << RESET << std::endl;
    AMateria* extra = src->createMateria("ice");
    tifa->equip(extra);
    delete extra;

    std::cout << LOG << "Using out of bounds indexes:" << RESET << std::endl;
    cloud->use(-1, *tifa);

    std::cout << LOG << "Creating a materia that doesn't exist:" << RESET << std::endl;
    AMateria* notFound = src->createMateria("fire");
    (void)notFound;

    std::cout << LOG << "Cleaning up (Unequipped materias, characters, source):" << RESET << std::endl;
    delete m1;
    delete tifa;
    delete cloud;
    delete src;
  }
}
