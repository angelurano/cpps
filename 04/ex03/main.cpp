/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:33:42 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/15 20:57:17 by migugar2         ###   ########.fr       */
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

    Character* cloud = new Character("Cloud");
    AMateria* m1 = src->createMateria("ice");
    cloud->equip(m1);

    Character* tifa = new Character(*cloud);

    cloud->unequip(0);

    std::cout << LOG << "Cloud (unequipped):" << RESET << std::endl;;
    cloud->use(0, *tifa);
    std::cout << LOG << "Tifa (copy):" << RESET << std::endl;
    tifa->use(0, *cloud);

    tifa->equip(src->createMateria("cure"));
    tifa->equip(src->createMateria("cure"));
    tifa->equip(src->createMateria("cure")); // Full

    AMateria* extra = src->createMateria("ice");
    tifa->equip(extra);

    delete extra;

    delete m1;
    delete tifa;
    delete cloud;
    delete src;
  }
}
