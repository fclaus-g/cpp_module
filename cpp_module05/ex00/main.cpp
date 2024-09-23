#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat b1;
	Bureaucrat b2("b2", 1);
	Bureaucrat b3("b3", 150);
	Bureaucrat b4("b4", 151);
	Bureaucrat b5("b5", 0);

	Bureaucrat b6(b2);
	Bureaucrat b7 = b3;
	std::cout  <<"b6 se crea con el nombre:" << b6.getName() << std::endl;
	std::cout <<"b7 se crea con el nombre:" << b7.getName() << std::endl;

	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b2.incrementGrade();
	std::cout << b2 << std::endl;
	b3.decrementGrade();
	std::cout << b3 << std::endl;
	b4.decrementGrade();
	std::cout << b4 << std::endl;
	return 0;
}
