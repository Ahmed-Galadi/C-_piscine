
#include <iostream>
#include <ctype.h>


int main(int argc, char *argv[])
{
	std::string str;
	if (argc > 1)
	{
		int	i = 1;
		while (i < argc)
		{
			str = argv[i];
			int j = 0;
			while (str[j])
			{
				if (str[j] >= 'a' && str[j] <= 'z')
					str[j] = toupper(str[j]);
				j++;
			}
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
