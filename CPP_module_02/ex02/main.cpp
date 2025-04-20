#include "Fixed.hpp"

int main( void ) {

// Fixed x = Fixed(0.2f);
// Fixed y = Fixed(0.05f);
// std::cout << "x + y = " << x + y << std::endl;
// std::cout << "x - y = " << x - y << std::endl;
// std::cout << "x * y = " << x * y << std::endl;
// std::cout << "x / y = " << x / y << std::endl;
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
