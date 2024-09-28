/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:19:41 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/09/28 18:12:50 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat b1;
	std::cout << b1 << std::endl;
	Bureaucrat b2("b2", 1);
	std::cout << b2 << std::endl;
	Bureaucrat b3("b3", 150);
	std::cout << b3 << std::endl;
	Bureaucrat b4 = b2;
	std::cout << b4 << std::endl;
	Bureaucrat b5(b3);
	std::cout << b5 << std::endl;
	try
	{
		Bureaucrat b4("b4", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl;
	try 
	{
		b5.incrementGrade();
		std::cout << b5 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
