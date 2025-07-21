#include <iostream>
#include <stack>
#include <deque>

template<typename T>
void printStack(std::stack<T> stack) {
	std::cout << "Stack Size: " << stack.size() << std::endl;
	if (stack.empty())
		std::cout << "Stack is Empty" << std::endl;
	else {
		std::cout << "Stack is Not Empty" << std::endl;
		std::cout << "Getting Top of the Stack => " << stack.top() << std::endl;
	}
}

int main() {
	std::stack<int> numbers;
	
	printStack<int>(numbers);

	std::cout << "\t* push [8] to stack *" <<std::endl;
	numbers.push(8);
	std::cout << "Getting Top of the Stack => " << numbers.top() << std::endl;
	printStack<int>(numbers);

	std::cout << "\t* push [9] to stack *" << std::endl;
	numbers.push(9);
	std::cout << "Getting Top of the Stack => " << numbers.top() << std::endl;
	std::cout << "\t* push [10] to stack *" << std::endl;
	numbers.push(10);
	
	printStack<int>(numbers);

	std::cout << "\t* Pop Stack *" << std::endl;
	numbers.pop();
	printStack<int>(numbers);

	std::cout << "\t* Other Number Creation and Pushed [1337] *" << std::endl;
	std::stack<int> otherNumbers;
	otherNumbers.push(1337);
	printStack(otherNumbers);

	std::cout << "\t* Swap otherNumbers With numbers *" << std::endl;
	otherNumbers.swap(numbers);
	printStack(otherNumbers);

	std::cout << "=====================================================\n";

}