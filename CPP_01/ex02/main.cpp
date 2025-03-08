#include <iostream>
#include <ostream>
#include <string>

int main (void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "strPTR address: " << strPTR << std::endl;
	std::cout << "strREF address: " << &strREF << std::endl;
	std::cout << "_______________________________\n" << std::endl;
	std::cout << "str value: " << str << std::endl;
	std::cout << "strPTR value: " << *strPTR << std::endl;
	std::cout << "strREF value: " << strREF << std::endl;

	return (0);
}
