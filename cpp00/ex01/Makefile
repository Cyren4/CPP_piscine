CC		=	clang++
RM		=	rm -rf
NAME	=	phoneBook 
CC_FLAGS	=	-Wall -Wextra -Werror 

SRCS	=	main.cpp PhoneBook.cpp Contact.cpp

OBJS	=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS)

clean	:
			@$(RM) $(OBJS)
			
fclean	:	clean
			@$(RM) $(NAME)
			
re		:	fclean all
.PHONY: clean fclean re compile all

