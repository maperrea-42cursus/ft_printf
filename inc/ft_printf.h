/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:50:12 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 22:26:14 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define ZEROES			0b00000001
# define HASHTAG		0b00000010
# define SPACE			0b00000100
# define PLUS			0b00001000
# define MINUS			0b00010000
# define FLAGS			"0# +-"
# define TYPES			"cspdiuxX%nfge"
# define HEX_LC_STR		"0123456789abcdef"
# define HEX_UC_STR		"0123456789ABCDEF"
# define DEC_STR		"0123456789"

typedef unsigned char	t_bit_flag_8;

typedef enum			e_type
{
	NONE = -1,
	CHAR,
	STRING,
	POINTER,
	INT_D,
	INT_I,
	UNSIGNED_INT,
	HEX_LC,
	HEX_UC,
	PERCENTAGE,
	COUNT,
	DOUBLE,
	E_OR_F,
	SCIENCE
}						t_type;

typedef char			*(t_length)(va_list, int);

typedef struct			s_tag
{
	t_bit_flag_8		flags;
	int					width;
	int					precision;
	t_length			*length;
	t_type				specifier;
}						t_tag;

typedef struct			s_nbr
{
	char				*nbr;
	int					width;
	int					precision;
	int					size;
	int					neg;
}						t_nbr;

typedef int				(t_print)(t_tag, va_list);

t_print					**init_dispatch_table();

int						parse_str(const char **str, t_tag *tag);

int						print_char(t_tag tag, va_list ap);
int						print_string(t_tag tag, va_list ap);
int						print_pointer(t_tag tag, va_list ap);
int						print_int(t_tag tag, va_list ap);
int						print_unsigned(t_tag tag, va_list ap);
int						print_hex(t_tag tag, va_list ap);
int						print_percentage(t_tag tag, va_list ap);
int						print_count(t_tag tag, va_list ap);
int						print_double(t_tag tag, va_list ap);
int						print_e_or_f(t_tag tag, va_list ap);
int						print_science(t_tag tag, va_list ap);

void					print_nbr(t_tag tag, t_nbr n);

char					*get_regular(va_list ap, int u);
char					*get_short(va_list ap, int u);
char					*get_short_short(va_list ap, int u);
char					*get_long(va_list ap, int u);
char					*get_long_long(va_list a, int up);

void					padding(int size, int zeroes);

int						ft_printf(const char *str, ...);
#endif
