# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 19:14:47 by maperrea          #+#    #+#              #
#    Updated: 2020/10/06 21:25:45 by maperrea         ###   ########.fr        #
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
			  ft_print_int.c		\
			  ft_print_percentage.c	\
			  ft_print_pointer.c	\
			  ft_print_science.c	\
			  ft_print_string.c		\
			  ft_print_unsigned.c	\
			  ft_printf.c

LIBSRCS		= ft_atoi.c					\
			  ft_atoi_base.c			\
			  ft_bzero.c				\
			  ft_calloc.c				\
			  ft_convert_base.c			\
			  ft_exp.c					\
			  ft_ftoa.c					\
			  ft_isalnum.c				\
			  ft_isalpha.c				\
			  ft_isascii.c				\
			  ft_isdigit.c				\
			  ft_isprint.c				\
			  ft_itoa.c					\
			  ft_itoa_base.c			\
			  ft_lstadd_back.c			\
			  ft_lstadd_front.c			\
			  ft_lstclear.c				\
			  ft_lstdelone.c			\
			  ft_lstiter.c				\
			  ft_lstlast.c				\
			  ft_lstmap.c				\
			  ft_lstnew.c				\
			  ft_lstsize.c				\
			  ft_memccpy.c				\
			  ft_memchr.c				\
			  ft_memcmp.c				\
			  ft_memcpy.c				\
			  ft_memmove.c				\
			  ft_memset.c				\
			  ft_memswap.c				\
			  ft_nbrlen.c				\
			  ft_putchar_fd.c			\
			  ft_putendl_fd.c			\
			  ft_putnbr_fd.c			\
			  ft_putstr_fd.c			\
			  ft_realloc.c				\
			  ft_reverse_str.c			\
			  ft_split.c				\
			  ft_strchr.c				\
			  ft_strdup.c				\
			  ft_strjoin.c				\
			  ft_strlcat.c				\
			  ft_strlcpy.c				\
			  ft_strlen.c				\
			  ft_strmapi.c				\
			  ft_strncmp.c				\
			  ft_strnstr.c				\
			  ft_strrchr.c				\
			  ft_strtrim.c				\
			  ft_substr.c				\
			  ft_tolower.c				\
			  ft_toupper.c				\
			  ft_utoa.c					\
			  ft_utoa_base.c			\
			  malloc_list.c

OBJDIR		= obj

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

INCDIR 		= inc

LIBINC		= libft

LIB			= libft.a

LIBDIR		= libft

LIBOBJS		= $(addprefix $(LIBDIR)/, $(LIBSRCS:.c=.o))

AR			= ar rc

CC			= gcc

CFLAGS 		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) -c $^ -o $@

all:		$(NAME)

$(LIB):
			make -C $(LIBDIR)

$(NAME):	$(LIB) $(OBJS)
			$(AR) $(NAME) libft/libft.a $(OBJS)

clean:
			make -C $(LIBDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			make -C $(LIBDIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
