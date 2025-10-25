#include <iostream>
#include <stack>

void	executeOperation(std::stack<int> &S, const char oper) {
	if (S.size() < 2) {
		std::cerr << "Invalid Expression!\n";
		exit(1);
	}
	int		secondOperand = S.top();
	S.pop();
	int		firstOperand = S.top();
	S.pop();
	if (oper == '+')
		S.push(firstOperand + secondOperand);
	else if (oper == '-')
		S.push(firstOperand - secondOperand);
	else if (oper == '*')
		S.push(firstOperand * secondOperand);
	else if (oper == '/') {
		if (secondOperand == 0) {
			std::cout << "Invalid Operation (Division By Zero)!\n";
			exit(1);
		}
		S.push(firstOperand / secondOperand);
	} else {
		std::cerr << "Invalid Token!\n";
		exit(1);
	}
}

void	removeSpaces(std::string &str) {
	std::string output;
	for (int i = 0; i < str.length(); i++)
		if (!isspace(str[i]))
			output += str[i];
	str = output;
}

int main(int argc, char *argv[]) {
	std::stack<int> S;
	if (argc < 2)
		return (1);
	std::string args = argv[1];
	removeSpaces(args);
	for (size_t i = 0; i < args.length(); i++) {
		if (std::isdigit(args[i]))
			S.push(args[i] - '0');
		else
			executeOperation(S, args[i]);
	}
	if (S.size() > 1) {
		std::cerr << "Invalid Expression!\n";
		return (1);
	}
	std::cout << S.top() << std::endl;
	return (0);
}
