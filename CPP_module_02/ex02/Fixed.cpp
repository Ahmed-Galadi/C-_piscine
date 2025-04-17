
#include "Fixed.hpp"

const int Fixed::numFracBits = 8;

Fixed::Fixed(): fixedPoint(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input) {
	//std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = input << this->numFracBits;
}

Fixed::Fixed(const float input) {
	//std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(input * (1 << this->numFracBits));
}

Fixed::Fixed(const Fixed &copy) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->fixedPoint = src.fixedPoint;
	return *this;
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->toFloat() != other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->toFloat() >= other.toFloat());
}

float	Fixed::operator+(const Fixed &other) const {
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed &other) const {
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed &other) const {
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed &other) const {
	return (this->toFloat() / other.toFloat());
}

Fixed	Fixed::operator++(const int) {
	Fixed oldThis = *this;
	this->fixedPoint++;
	return (oldThis);
}

Fixed	Fixed::operator++() {
	++this->fixedPoint;
	return (*this);
}

Fixed	Fixed::operator--(const int) {
	Fixed oldThis = *this;
	this->fixedPoint--;
	return (oldThis);
}

Fixed Fixed::operator--(void) {
	--this->fixedPoint;
	return (*this);
}

Fixed Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1 <= num2)
		return (num1);
	return (num2);
}

Fixed Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1 >= num2)
		return (num1);
	return (num2);
}

int	Fixed::toInt(void) const {
	return (this->fixedPoint >> this->numFracBits);
}

float	Fixed::toFloat(void)const {
	return ((float)this->fixedPoint / (float)(1 << this->numFracBits));
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return (o);
}
