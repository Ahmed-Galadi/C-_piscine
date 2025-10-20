#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

template<typename T>
void printStack(MutantStack<T> stack) {
	std::cout << "Stack Size: " << stack.size() << std::endl;
	if (stack.empty())
		std::cout << "Stack is Empty" << std::endl;
	else {
		std::cout << "Stack is Not Empty" << std::endl;
		std::cout << "Getting Top of the Stack => " << stack.top() << std::endl;
	}
}

int main() {

	std::cout << "------| SUBJECT TESTS |-----------\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--------| SUBJECT TEST WITH LIST |-----------\n";
	std::list<int> mstack1;
	mstack1.push_back(5);
	mstack1.push_back(17);
	std::cout << mstack1.back() << std::endl;  // fixed
	mstack1.pop_back();
	std::cout << mstack1.size() << std::endl;
	mstack1.push_back(3);
	mstack1.push_back(5);
	mstack1.push_back(737);
	mstack1.push_back(0);
	std::list<int>::iterator it1 = mstack1.begin();
	std::list<int>::iterator ite1 = mstack1.end();
	++it1;
	--it1;
	while (it1 != ite1) {
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::list<int> s1(mstack1);

	std::cout << "=====================================================\n";
	std::cout << "||                  MY TESTS                       ||\n";
	std::cout << "=====================================================\n";
	
	MutantStack<int> numbers;

	printStack(numbers);
	std::cout << "\t* push [8] to stack *" <<std::endl;
	numbers.push(8);
	std::cout << "Getting Top of the Stack => " << numbers.top() << std::endl;
	printStack(numbers);

	std::cout << "\t* push [9] to stack *" << std::endl;
	numbers.push(9);
	std::cout << "Getting Top of the Stack => " << numbers.top() << std::endl;
	std::cout << "\t* push [10] to stack *" << std::endl;
	numbers.push(10);
	
	printStack(numbers);

	std::cout << "\t* Pop Stack *" << std::endl;
	numbers.pop();
	printStack(numbers);

	std::cout << "\t* Other Number Creation and Pushed [1337] *" << std::endl;
	MutantStack<int> otherNumbers;
	otherNumbers.push(1337);
	otherNumbers.push(1998);
	otherNumbers.push(1997);
	otherNumbers.push(1945);
	otherNumbers.push(666);
	printStack(otherNumbers);

	std::cout << "\t* Print Using Iterators *" << std::endl;
	std::cout << "numbers: ";
	for (MutantStack<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
		std::cout << *iter << "| ";
	std::cout << std::endl;
	std::cout << "other numbers: ";
	for (MutantStack<int>::iterator iter = otherNumbers.begin(); iter != otherNumbers.end(); iter++)
		std::cout << *iter << "| ";
	std::cout << std::endl;

	return (0);
}
