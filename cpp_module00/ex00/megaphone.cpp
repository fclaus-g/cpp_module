/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:46:08 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/04/22 12:09:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < ac)
		{
			j = 0;
			while(av[i][j])
			{
				std::cout << (char)std::toupper(av[i][j]);
				j++;
			}
			if (ac > 2)
				std::cout << " ";
			i++;
		}
		std::cout<< std::endl;
	}
	return 0;
}