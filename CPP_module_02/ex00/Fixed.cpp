#include "Fixed.hpp"
#include <ostream>

const int Fixed::numFracBits = 8;

Fixed::Fixed(void) {
	fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &setFixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
	*this  = setFixedPoint;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &otherFixedPoint) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = otherFixedPoint.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(const int ) {
	std::cout << "setRawBits member function called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}


 
