# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 10:56:01 by maperrea          #+#    #+#              #
#    Updated: 2020/02/27 13:45:50 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCDIR		= .

#SRCS		= ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_utoa.c ft_putchar_fd.c ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memccpy.c ft_putendl_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_substr.c ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_tolower.c ft_isascii.c ft_memcpy.c ft_split.c ft_strmapi.c ft_toupper.c ft_isdigit.c ft_memmove.c ft_strchr.c ft_strncmp.c

SRCS		= $(shell find *.c)

BONUSDIR	= .

BONUS		=  ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c ft_lstadd_front.c ft_lstiter.c ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstsize.c

OBJS		= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUS:.c=.o}

INCDIR		= .

CC			= gcc

RM			= rm -f

#CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} -O3 ${CFLAGS} -I${INCDIR} -c $^ -o $@

all:		bonus

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUSOBJS}
			@ar rc ${NAME} ${OBJS} ${BONUSOBJS}

clean:
			${RM} ${OBJS} ${BONUSOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
.SILENT:	bonus
