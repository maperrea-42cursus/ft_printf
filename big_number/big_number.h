/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_number.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:52:17 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/11 02:37:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_NUMBER_H
# define BIG_NUMBER_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct			s_big_number
{
	unsigned char		*decimal_part;
	unsigned char		*int_part;
	int					int_size;
	int					decimal_size;
	unsigned char		sign;
}						t_big_number;

typedef struct			s_bn_part
{
	unsigned char		*part;
	int					size;
}						t_bn_part;

typedef struct			s_dbl
{
	char				sign;
	unsigned long		mantissa;
	int					exponent;
}						t_dbl;

void					print_bits(void *ptr, int size);
void					print_bn(t_big_number *bn);
void					print_dbl_bits(double d);

t_dbl					dbl_to_t_dbl(double n);
t_big_number			*dbl_to_bn(double n);

void					equalize_dec(t_big_number *bn1, t_big_number *bn2);
void					equalize_int(t_big_number *bn1, t_big_number *bn2);
void					bn_trim(t_big_number *bn);
t_big_number			*big_number_add(t_big_number *bn1, t_big_number *bn2);
t_big_number			*big_number_sub(t_big_number *bn1, t_big_number *bn2);
t_big_number			*big_number_mult(t_big_number *bn1, t_big_number *bn2);

int						bn_compare(t_big_number *bn1, t_big_number *bn2);
#endif
