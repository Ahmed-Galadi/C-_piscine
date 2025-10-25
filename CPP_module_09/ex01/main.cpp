#include <iostream>
#include <stack>
#include <algorithm>

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
	else if (oper == '/')
		S.push(firstOperand / secondOperand);
	else {
		std::cerr << "Invalid Token!\n";
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	std::stack<int> S;
	if (argc < 2)
		return (1);
	std::string args = std::string(argv[1]);

	args.erase(std::remove(args.begin(), args.end(), ' '), args.end());
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
