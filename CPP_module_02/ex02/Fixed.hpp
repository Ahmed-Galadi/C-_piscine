#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		static const int	numFracBits;
		int					fixedPoint;

	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &copy);

		~Fixed();

		Fixed	&operator=(const Fixed &src);
		bool	operator!=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &orther) const;
		float	operator+(const Fixed &other) const;
		Fixed	operator++(const int);
		Fixed	operator++(void);
		float	operator-(const Fixed &other) const;
		Fixed	operator--(const int);
		Fixed	operator--(void);
		float	operator*(const Fixed &other) const;
		float	operator/(const Fixed &other) const;

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		static Fixed	min(const Fixed &num1, const Fixed &num2);
		static Fixed	max(const Fixed &num1, const Fixed &num2);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
