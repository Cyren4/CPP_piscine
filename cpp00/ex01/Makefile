CXX		=	clang++
RM		=	rm -rf
NAME	=	phoneBook 
CXXFLAGS	=	-Wall -Wextra -Werror 

SRCS	=	main.cpp PhoneBook.cpp Contact.cpp

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

