/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:01:25 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 16:28:12 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define ZEROES			1
# define HASHTAG		2
# define SPACE			4
# define PLUS			8
# define MINUS			16
# define FLAGS			"0# +-"
# define TYPES			"cspdiuxXo%nfge"
# define HEX_LC_STR		"0123456789abcdef"
# define HEX_UC_STR		"0123456789ABCDEF"
# define OCT_STR		"01234567"
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
	OCT,
	PERCENTAGE,
	COUNT,
	DOUBLE,
	E_OR_F,
	SCIENCE
}						t_type;

typedef char			*(t_length)(va_list ap, int u);

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
void					build_tag(t_tag *tag, const char *str, int *pos);

int						print_char(t_tag tag, va_list ap);
int						print_string(t_tag tag, va_list ap);
int						print_pointer(t_tag tag, va_list ap);
int						print_int(t_tag tag, va_list ap);
int						print_unsigned(t_tag tag, va_list ap);
int						print_hex(t_tag tag, va_list ap);
int						print_oct(t_tag tag, va_list ap);
int						print_percentage(t_tag tag, va_list ap);
int						print_count(t_tag tag, va_list ap);
int						print_double(t_tag tag, va_list ap);
int						print_e_or_f(t_tag tag, va_list ap);
int						print_science(t_tag tag, va_list ap);

void					print_nbr(t_tag tag, t_nbr n);
int						print_special(t_tag tag, t_nbr n);
int						print_float(t_tag tag, t_nbr n);
int						print_exp(t_tag tag, t_nbr n, int exp);

char					*get_regular(va_list ap, int u);
char					*get_short(va_list ap, int u);
char					*get_short_short(va_list ap, int u);
char					*get_long(va_list ap, int u);
char					*get_long_long(va_list a, int up);

void					padding(int size, int zeroes);
int						rounding(t_nbr *n);
int						move_comma(t_nbr *n);

int						ft_printf(const char *str, ...);

#endif
