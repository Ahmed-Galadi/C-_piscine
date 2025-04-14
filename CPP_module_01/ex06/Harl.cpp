/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:11:13 by agaladi           #+#    #+#             */
/*   Updated: 2025/03/14 21:12:11 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"
#include <iostream>
#include <string>

void	Harl::complain(std::string level)
{
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*complainFunc[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int i = -1;
	while (++i < 4)
	{
		if (level == levels[i]) { 
			for (int j = i; j < 4; j++)
				(this->*complainFunc[j])();
			return ;
		}	
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
void	Harl::debug(void) {
	std::cout << "\e[1;32m[DEBUG]\e[0m : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "\e[1;38;5;226m[INFO]\e[0m : I cannot believe adding extra bacon costs more money. You didn’t put \
	enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "\e[1m\e[38;2;255;165;0m[WARNING]\e[0m : I think I deserve to have some extra bacon for free. I’ve been coming for \
	years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "\e[1;31m[ERROR]\e[0m : This is unacceptable! I want to speak to the manager now." << std::endl;
}
