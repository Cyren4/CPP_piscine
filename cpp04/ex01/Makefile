CXX		=	c++
RM		=	rm -rf
CXXFLAGS	=	-Wall -Wextra -Werror 
CXXFLAGS += -fsanitize=address -g3

NAME	=	farm	

DIR_SRCS	= srcs
DIR_OBJS	= objs

SRCS_F	=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

SRCS = $(addprefix $(DIR_SRCS)/,$(SRCS_F))

OBJS = $(addprefix $(DIR_OBJS)/,$(SRCS_F:.cpp=.o))


all		:	$(NAME)


$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp
	mkdir -p $(DIR_OBJS)	
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $^ -o $@

clean:
		@$(RM) $(DIR_OBJS)	

fclean	:	clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY: clean fclean re compile all

