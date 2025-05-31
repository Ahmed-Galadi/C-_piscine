#pragma once

#include <ostream>

class Data {
	private:
		int		id;
		std::string name;

	public:
		Data();
		Data(int initId, const std::string &initName);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();

		int			getId() const;
		std::string	getName() const;
		
		void	setId(int idToSet);
		void	setName(const std::string &nameToSet);
};

std::ostream &operator<<(std::ostream &o, const Data &obj); 
