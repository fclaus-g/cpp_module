/*• [ ] ShrubberyCreationForm: Required grades: sign 145, exec 137
		* [ ] Crea un archivo <target>_shrubbery en el directorio de trabajo y escribe árboles ASCII dentro de él.*/

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif