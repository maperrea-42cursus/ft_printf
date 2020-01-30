# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 18:04:28 by maperrea          #+#    #+#              #
#    Updated: 2020/01/29 15:06:48 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.o obj

NAME		= libftprintf.a

SRCDIR		= src

SRCS		= $(notdir $(shell find ${SRCDIR}/*.c))

OBJDIR		= obj

OBJS		= $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

INCDIR		= inc

CC 			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

${OBJDIR}/%.o: ${SRCDIR}/%.c
			${CC} ${CFLAGS} -I${INCDIR} -c $^ -o $@

${OBJDIR}:
			$(shell mkdir -p ${OBJDIR})

${NAME}:	${OBJDIR} ${OBJS}
			$(shell cd libft && make)
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} -r ${OBJDIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
