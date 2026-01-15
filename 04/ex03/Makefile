NAME = materia

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
