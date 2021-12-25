CXX		=	c++
RM		=	rm -rf
NAME	=	HiBrain 
CXXFLAGS	=	-Wall -Wextra -Werror 

SRCS	=	main.cpp 

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

