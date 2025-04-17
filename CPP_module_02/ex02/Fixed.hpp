#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int	numFracBits;
		int					fixedPoint;

	public:
	//constructors
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &copy);
	//destructor
		~Fixed();
	//assignment operators
		Fixed	&operator=(const Fixed &src);
		Fixed	&operator!=(const Fixed &other) const;
		Fixed	&operator==(const Fixed &other) const;
		Fixed	&operator>(const Fixed &other) const;
		Fixed	&operator<(const Fixed &other) const;
		Fixed	&operator>=(const Fixed &other) const;
		Fixed	&operator<=(const Fixed &orther) const;
		Fixed	&operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;
	//public member functions
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

//overload insertion operator
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
