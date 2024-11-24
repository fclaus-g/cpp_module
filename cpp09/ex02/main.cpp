/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:37:43 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/11/24 19:43:53 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Usage " << av[0] << " <set of numbers>" << std::endl;
		return 1;
	}
	try {
		PmergeMe p(av);
		p.run();
		
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	return 0;
	}
}
