# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:29:36 by cramdani          #+#    #+#              #
#    Updated: 2021/11/28 23:22:03 by cramdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang++
RM		=	rm -rf
NAME	=	megaphone
CC_FLAGS	=	-Wall -Wextra -Werror 

SRCS	=	megaphone.cpp
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

test	:	all
			./$(NAME)	 "shhhhh... I think the students are asleep..."
			./$(NAME)	 Damnit " ! " "Sorry students, I thought this thing was off."
			./$(NAME)