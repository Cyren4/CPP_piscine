CXX		=	clang++
RM		=	rm -rf
NAME	=	walkingDead 
CXXFLAGS	=	-Wall -Wextra -Werror 

SRCS	=	main.cpp Zombie.cpp ZombieHorde.cpp

OBJS	=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:
			@$(RM) $(OBJS)
			
fclean	:	clean
			@$(RM) $(NAME)
			
re		:	fclean all
.PHONY: clean fclean re compile all

