/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:50:12 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/30 17:29:18 by maperrea         ###   ########.fr       */
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

# define MINUS			0b00010000
# define PLUS			0b00001000
# define SPACE			0b00000100
# define HASHTAG		0b00000010
# define ZEROES			0b00000001
# define FLAGS			"0# +-"
# define TYPES			"cspdiuxXnfge"

typedef unsigned char	t_bit_flag_8;


typedef enum			e_type
{
	CHAR,
	STRING,
	POINTER,
	INT,
	UNSIGNED_INT,
	HEX_LC,
	HEX_UC,
	PERCENTAGE,
	COUNT,
	FLOAT,
	E_OR_F,
	SCIENCE
}						t_type;

typedef enum			e_length
{
	REGULAR,
	LONG,
	LONG_LONG,
	SHORT,
	SHORT_SHORT,
}						t_length;

typedef union			u_var
{
	char				char_var;
	void				*ptr_var;
	int					int_var;
	float				float_var;
	long				long_var;
	long long			long_long_var;
	short				short_var;
}						t_var;

typedef struct			s_tag
{
	t_bit_flag_8		flags;
	unsigned int		width;
	unsigned int		precision;
	t_length			length;
	t_type				specifier;
}						t_tag;

typedef void			(*t_print)(t_tag, va_list);

int						parse_str(char **str, t_tag *tag);
t_print					*init_dispatch_table();

#endif
