/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:09 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/15 13:45:02 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Cree un programa que tome tres parámetros en el siguiente orden: un nombre de archivo y
dos strings, s1 y s2.
Abrirá el archivo <nombre de archivo> y copiará su contenido en un archivo nuevo.
<nombre de archivo>.replace, reemplazando cada aparición de s1 con s2.
El uso de funciones de manipulación de archivos C está prohibido y se considerará trampa. Todo
las funciones miembro de la clase std::string están permitidas, excepto reemplazar. Usalos, usalos a ellos
sabiamente!
Por supuesto, maneje entradas y errores inesperados. Tienes que crear y entregar tu
propias pruebas para garantizar que su programa funcione como se espera.*/

#include <iostream>
#include <fstream>
#include <string>

void	replaceStrings(std::ifstream &inFile, std::ofstream &outFile, std::string target, std::string replace);


void	replaceStrings(std::ifstream &inFile, std::ofstream &outFile, std::string target, std::string replace)
{
	std::string line;
	
	while (std::getline(inFile, line))//mientras haya lineas en el archivo
	{
		size_t pos = 0;
		while ((pos = line.find(target, pos)) != std::string::npos)//mientras haya target en la linea
		{
			line.erase(pos, target.length());//elimina el target con su longitud
			line.insert(pos, replace);//inserta el replace en la posicion del target
			pos += replace.length();//avanza la posicion hasta el final de replace
		}
		outFile << line << std::endl;//escribe la linea en el archivo de salida
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string target = av[2];
		std::string replace = av[3];
		if (target.empty() || replace.empty() || filename.empty())
		{
			std::cout << "Error: s1, s2 or filename is empty" << std::endl;
			return (1);
		}
		std::ifstream inFile(filename.c_str());//COMPROBAR CON LOS COMPAÑEROS SI ESTO ES NECESARIO
		if (!inFile.is_open())
		{
			std::cout << "Error: file not found" << std::endl;
			return (1);
		}
		std::string newFilename = filename + ".replace";
		std::ofstream outFile(newFilename .c_str());
		if (!outFile.is_open())
		{
			std::cout << "Error: file not created" << std::endl;
			return (1);
		}
		while (!inFile.eof())
	        replaceStrings(inFile, outFile, target, replace);
		inFile.close();
		outFile.close();
	}
	else 
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
	}
	return (0);
}