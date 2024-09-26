/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:30:51 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/05/29 10:25:32 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
   	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	ICharacter* Wizard = new Character("Wizard");
	Wizard->equip(src->createMateria("ice"));
	Wizard->equip(src->createMateria("cure"));
	
	ICharacter* Warrior = new Character("Warrior");
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->equip(src->createMateria("cure"));
	Warrior->unequip(3);
	Warrior->unequip(2);
	Wizard->use(0, *Warrior);
	Wizard->use(1, *Warrior);
	Wizard->use(2, *Warrior);
	ICharacter* Loco = new Character("Loco");
	*Loco = *Warrior;
	Warrior->use(0, *Loco);

	delete Loco;
	delete Warrior;
	delete Wizard;
	delete src;
	delete src2;
	return 0;
}