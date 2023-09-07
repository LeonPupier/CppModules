# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 09:49:02 by lpupier           #+#    #+#              #
#    Updated: 2023/09/07 16:41:16 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME			=	BigForm
CPP				=	c++ -std=c++98
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

# Sources folder
DIR_SRCS		=	./
DIR_HEADERS		=	./

# Sources files
SRCS			=	${DIR_SRCS}main.cpp														\
					${DIR_SRCS}Bureaucrat.Class/Bureaucrat.cpp								\
					${DIR_SRCS}Form.Class/Form.cpp											\
					${DIR_SRCS}ShrubberyCreationForm.Class/ShrubberyCreationForm.cpp		\
					${DIR_SRCS}RobotomyRequestForm.Class/RobotomyRequestForm.cpp			\
					${DIR_SRCS}PresidentialPardonForm.Class/PresidentialPardonForm.cpp

HEADERS			=	${DIR_HEADERS}Bureaucrat.Class/Bureaucrat.hpp							\
					${DIR_HEADERS}Form.Class/Form.hpp										\
					${DIR_HEADERS}ShrubberyCreationForm.Class/ShrubberyCreationForm.hpp		\
					${DIR_HEADERS}RobotomyRequestForm.Class/RobotomyRequestForm.hpp			\
					${DIR_HEADERS}PresidentialPardonForm.Class/PresidentialPardonForm.hpp

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