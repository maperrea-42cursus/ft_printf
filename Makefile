# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maperrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 18:04:28 by maperrea          #+#    #+#              #
#    Updated: 2020/10/06 21:01:43 by maperrea         ###   ########.fr        #
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

LIB			= libft.a

LIBDIR		= libft

LIBINC		= libft

CC 			= gcc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@$(CC) -O3 $(CFLAGS) -I$(INCDIR) -I$(LIBINC) -c $^ -o $@

all:		$(NAME)

$(OBJDIR):
			@mkdir -p $(OBJDIR)

$(LIB):
			@echo "\033[38;5;33mBuilding libft...\033[0m"
			@make --no-print-directory -C libft
			@echo "\033[38;5;2m[built]\033[0m"

buildecho:
			@echo "\033[38;5;33mBuilding libftprintf...\033[0m"

$(NAME):	$(LIB) buildecho $(OBJDIR) $(OBJS)
			@ar rc $(NAME) $(OBJS) $(LIBOBJS)
			@ranlib $(NAME)
			@echo "\033[38;5;2m[built]\033[0m"

a.out:		all $(LIB)
			@echo "\033[38;5;33mBuilding main...\033[0m"
			@$(CC) $(CFLAGS) -O3 -I$(INCDIR) -I$(LIBINC) main.c $(NAME)
			@echo "\033[38;5;2m[built]\033[0m"

clean:
			@echo "\033[38;5;33mCleaning libftprintf...\033[0m"
			@$(RM) -r $(OBJDIR)
			@echo "\033[38;5;33m\033[38;5;2m[cleaned]\033[0m"
			@echo "\033[38;5;33mCleaning libft...\033[0m"
			@make --no-print-directory -C libft clean
			@echo "\033[38;5;33m\033[38;5;2m[cleaned]\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBDIR)/libft.a
			@$(RM) a.out

re:			
			@make --no-print-directory -C libft fclean
			@make --no-print-directory fclean
			@make --no-print-directory all

.PHONY:		all a.out clean fclean re
