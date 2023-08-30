# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 09:49:02 by lpupier           #+#    #+#              #
#    Updated: 2023/07/24 15:35:20 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	Animal
CPP				=	c++ -std=c++98
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

# Sources folder
DIR_SRCS		=	./
DIR_HEADERS		=	./

# Sources files
SRCS			=	${DIR_SRCS}main.cpp								\
					${DIR_SRCS}Animal.Class/Animal.cpp				\
					${DIR_SRCS}WrongAnimal.Class/WrongAnimal.cpp	\
					${DIR_SRCS}Dog.Class/Dog.cpp					\
					${DIR_SRCS}Cat.Class/Cat.cpp					\
					${DIR_SRCS}WrongCat.Class/WrongCat.cpp

HEADERS			=	${DIR_HEADERS}Animal.Class/Animal.hpp			\
					${DIR_HEADERS}WrongAnimal.Class/WrongAnimal.hpp	\
					${DIR_HEADERS}Dog.Class/Dog.hpp					\
					${DIR_HEADERS}Cat.Class/Cat.hpp					\
					${DIR_HEADERS}WrongCat.Class/WrongCat.hpp

# Objects
DIR_OBJS		=	.objs/
OBJS			=	${patsubst %.cpp, ${DIR_OBJS}%.o, ${SRCS}}

# Rules
.PHONY :		all clean fclean re watermark

all :	 		${NAME}

%.o: %.cpp		
				$(CPP) $(CFLAGS) -c $< -o $@

${DIR_OBJS}%.o: %.cpp	${HEADERS}
				@mkdir -p ${shell dirname $@}
				${CPP} ${CFLAGS} -c $< -o $@ -I ${DIR_HEADERS}

${NAME}:		${OBJS}
				$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				${RM} ${OBJS} ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME}

re :			fclean all

watermark:
				@echo "$$WATERMARK"

# Text art
define WATERMARK

██╗  ██╗██████╗ 
██║  ██║╚════██╗ name:  Leon Pupier
███████║ █████╔╝ login: lpupier
╚════██║██╔═══╝  
     ██║███████╗
     ╚═╝╚══════╝lyon.fr

endef
export WATERMARK