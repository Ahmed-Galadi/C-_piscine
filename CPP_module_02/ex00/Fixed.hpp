#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		static const int	numFracBits;
		int					fixedPoint;

	public:
		Fixed(void);
		Fixed(const Fixed &setFixedPoint);
		Fixed &operator=(const Fixed &otherFixedPoint);
		~Fixed(void);
		
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
