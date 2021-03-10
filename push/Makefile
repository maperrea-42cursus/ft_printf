# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 19:14:47 by maperrea          #+#    #+#              #
#    Updated: 2021/02/10 14:10:53 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libftprintf.a

SRCDIR		= src

SRCS		= ft_itoa_size.c		\
			  ft_padding.c			\
			  ft_parser.c			\
			  ft_print_char.c		\
			  ft_print_count.c		\
			  ft_print_double.c		\
			  ft_print_e_or_f.c		\
			  ft_print_hex.c		\
			  ft_print_oct.c		\
			  ft_print_int.c		\
			  ft_print_percentage.c	\
			  ft_print_pointer.c	\
			  ft_print_science.c	\
			  ft_print_string.c		\
			  ft_print_unsigned.c	\
			  ft_printf.c

OBJDIR		= obj

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

INCDIR 		= inc

LIBINC		= libft

LIB			= libft.a

LIBDIR		= libft

LIBOBJS		= $(addprefix $(LIBDIR)/, $(LIBSRCS:.c=.o))

AR			= ar rc

CC			= gcc -g -fsanitize=address

#CFLAGS 		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $^ -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBDIR)
			cp $(LIBDIR)/$(LIB) $(NAME)
			$(AR) $(NAME) $(OBJS)

bonus:		$(NAME)

clean:
			make -C $(LIBDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBDIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
