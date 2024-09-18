
#include "ShrubberyCreationForm.hpp"

/*Canonical Ortodox*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExe())
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	this->_target = rhs._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	std::cout << "ShrubberyCreationForm assignation operator" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
		this->setSign(copy.getSigned());
	}
	return (*this);
}

/*Get*/

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

/*Method*/

void ShrubberyCreationForm::action() const
{
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";
	file.open(filename.c_str());
	if (file.is_open())
	{
		file << "       _-_\n";
		file << "    /~~   ~~\\\n";
		file << " /~~         ~~\\\n";
		file << "{               }\n";
		file << " \\  _-     -_  /\n";
		file << "   ~  \\\\ //  ~\n";
		file << "_- -   | | _- _\n";
		file << "   _-  | |   -_\n";
		file << "  _-   | | __-_\n";
		file << "      // \\\\\n";
		file << this->_target << std::endl;
		file.close();
	}
	else
		std::cerr << "Error: could not open file" << std::endl;
}

/*Operator*/

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form)
{
	out << GRN << "ShrubberyCreationForm" << RES << std::endl;
	out << "Name: " << form.getName() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade to exe: " << form.getGradeToExe() << std::endl;
	out << "Signed: " << form.getSigned() << std::endl;
	out << "Target: " << form.getTarget() << std::endl;
	return out;
}
