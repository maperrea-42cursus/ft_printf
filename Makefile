# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 18:04:28 by maperrea          #+#    #+#              #
#    Updated: 2020/02/25 15:23:56 by maperrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.h inc
vpath %.c src
vpath %.c libft
vpath %.o obj

NAME		= libftprintf.a

INCNAME		= ftprintf

SRCDIR		= src

SRCS		= $(notdir $(shell find $(SRCDIR)/*.c))

LIBSRC		= $(notdir $(shell find $(LIBDIR)/*.c))

OBJDIR		= obj

OBJS		= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

LIBOBJS		= $(addprefix $(LIBDIR)/,$(LIBSRC:.c=.o))

INCDIR		= inc

LIB			= ft

LIBDIR		= libft

LIBINC		= libft

CC 			= gcc

RM			= rm -f

#CFLAGS		= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@$(CC) -O3 $(CFLAGS) -I$(INCDIR) -I$(LIBINC) -c $^ -o $@

all:		$(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)

$(LIB):
			@make -C libft
			@echo "\033[38;5;33mlibft: \033[38;5;2m[OK]\033[0m"

$(NAME):	$(LIB) $(OBJDIR) $(OBJS)
			@ar rc $(NAME) $(OBJS) $(LIBOBJS)
			@ranlib $(NAME)
			@echo "\033[38;5;33mlibftprintf: \033[38;5;2m[OK]\033[0m"

a.out:		all $(LIB)
			@$(CC) -O3 -fsanitize=address -I$(INCDIR) -I$(LIBINC) main.c $(NAME)
			@echo "\033[38;5;33mmain: \033[38;5;2m[OK]\033[0m"

clean:
			$(RM) -r $(OBJDIR)
			make -C libft clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBDIR)/libft.a
			$(RM) a.out

re:			
			make -C libft fclean
			make fclean
			make all

.PHONY:		all a.out clean fclean re
