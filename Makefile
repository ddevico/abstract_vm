# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/23 16:29:25 by ddevico           #+#    #+#              #
#    Updated: 2017/04/23 17:43:07 by ddevico          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 	abstract_VM

SRC_PATH= src

SRC= src/main.cpp\
	src/Calculator.cpp\
	src/Operand.cpp\
	src/Exception.cpp\
	src/Parse.cpp

CC=	clang++

FLAG=	-W -Wall -Werror -Wextra

OBJ_PATH= objects/
OBJ_NAME= $(SRC_NAME:.cpp=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) $(SRC) -o $(NAME) $(OBJ)
	@echo "Your program is ready to go !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p objects
	$(GCC) $(SRC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf *~
	@rm -rf *#
	@echo "Object files has been deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "Program has been deleted"

re: fclean all
