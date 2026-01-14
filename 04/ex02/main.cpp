/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:20:24 by migugar2          #+#    #+#             */
/*   Updated: 2026/01/14 23:30:08 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

int main() {
  std::cout << "---------------------" << std::endl;
  {
    const int count = 4;
    const AAnimal *animals[count];
    for (int i = 0; i < count; i++) {
      if (i < count / 2)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }

    for (int i = 0; i < count; i++) {
      delete animals[i];
    }
  }
  std::cout << "---------------------" << std::endl;
  {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j; //should not create a leak
    delete i;
  }
  std::cout << "---------------------" << std::endl;
  {
    Dog *dog = new Dog();
    Brain dogBrain;
    dogBrain.setIdea(0, "I want to play!");
    dog->setBrain(dogBrain);

    AAnimal *dogCopy = new Dog(*dog);
    Brain dog2Brain;
    dog2Brain.setIdea(0, "I want to eat!");
    dogCopy->setBrain(dog2Brain);

    std::cout << "Dog 1 Brain Idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog 2 Brain Idea 0: " << dogCopy->getBrain()->getIdea(0) << std::endl;

    delete dog;
    delete dogCopy;
  }
  std::cout << "---------------------" << std::endl;
}
