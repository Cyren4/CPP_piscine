CXX		=	c++
RM		=	rm -rf
NAME	=	octogone 
CXXFLAGS	=	-Wall -Wextra -Werror 

SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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

