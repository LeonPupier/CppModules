# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 09:49:02 by lpupier           #+#    #+#              #
#    Updated: 2023/09/26 13:49:08 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	RPN
CPP				=	c++ -std=c++98
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

# Sources folder
DIR_SRCS		=	./
DIR_HEADERS		=	./

# Sources files
SRCS			=	${DIR_SRCS}main.cpp				\
					${DIR_SRCS}RPN.Class/RPN.cpp

HEADERS			=	${DIR_HEADERS}RPN.Class/RPN.hpp

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