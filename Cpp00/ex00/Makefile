# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 09:49:02 by lpupier           #+#    #+#              #
#    Updated: 2023/05/09 08:18:23 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME		=	megaphone
CPP			=	c++ -std=c++98
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

# Directories path
DIR_SRCS	=	sources/

# Sources files
SRCS		=	${DIR_SRCS}megaphone.cpp

# Objects
DIR_OBJS	=	.objs/
OBJS		=	${patsubst %.cpp, ${DIR_OBJS}%.o, ${SRCS}}

# Rules
.PHONY :		all clean fclean re watermark

all :	 		${NAME}

%.o: %.cpp		
				$(CPP) $(CFLAGS) -c $< -o $@

${DIR_OBJS}%.o: %.cpp
				@mkdir -p ${shell dirname $@}
				${CPP} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				${RM} ${OBJS} ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

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