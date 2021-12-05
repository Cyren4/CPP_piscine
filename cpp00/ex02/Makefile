CXX		=	clang++
RM		=	rm -rf
NAME	=	globalBanksters 
CXXFLAGS	=	-Wall -Wextra -Werror 

SRCS	=	tests.cpp Account.cpp

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

