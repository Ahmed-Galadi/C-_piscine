
#include "Form.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
	{
		std::cout << "\e[34mConstructing\e[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;
		std::cout << *b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}


		std::cout << *b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << *a;
		std::cout << *b;
		std::cout << *c;

		// Assistant signs the Form
		try
		{
			/*c->beSigned(*a);*/
			a->signForm(*c);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		// CEO signs the Form
		std::cout << *c;
		try
		{
			c->beSigned(*b);
			// b->signForm(*c);
		}
		catch(std::exception &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << *c;

		// try signing the from again
		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Form *a = NULL;

		// sign-grade too high
		try
		{
			a = new Form("FORM_1",160, 145);
		}
		catch (std::exception &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too high
		try
		{
			a = new Form("FORM_2",145, 160);
		}
		catch (std::exception &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// sign-grade too low
		try
		{
			a = new Form("FORM_3", -15, 145);
		}
		catch (std::exception &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// exec-grade too low
		try
		{
			a = new Form("FORM_4",145, -15);
		}
		catch (std::exception &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		// Deconstruction to prevent unused variable, in this case will never be called
		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			delete a;
		}
	}
	return (0);
}
