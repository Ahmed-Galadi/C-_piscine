NAME = PmergeMe
SRCS = main.cpp FordJhonson.cpp
HDRS = FordJhonson.hpp FordJhonsonBiderect.hpp Parsing.hpp Parsing.tpp FordJhonsonBidirect.tpp FordJhonson.tpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
