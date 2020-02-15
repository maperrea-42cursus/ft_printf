/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:51:20 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/15 18:35:16 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	**init_dispatch_table(void)
{
	t_print	**table;

	if (!(table = malloc(sizeof(t_print *) * 12)))
		return (NULL);
	table[CHAR] = &print_char;
	table[STRING] = &print_string;
	table[POINTER] = &print_pointer;
	table[INT_D] = &print_int;
	table[INT_I] = &print_int;
	table[UNSIGNED_INT] = &print_unsigned;
	table[HEX_LC] = &print_hex;
	table[HEX_UC] = &print_hex;
	table[PERCENTAGE] = &print_percentage;
	table[COUNT] = &print_count;
	table[DOUBLE] = &print_double;
/*	table[E_OR_F] = &print_e_or_f;
	table[SCIENCE] = &print_science; */
	return(table);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_print	**dispatch_table;
	t_tag	tag;
	int		ret;
	int		*ptr;

	ret = 0;
	va_start(ap, str);
	dispatch_table = init_dispatch_table();
	ret += parse_str(&str, &tag);
	while (tag.specifier != NONE)
	{
		ret += (*(dispatch_table[tag.specifier]))(tag, ap);
		if (tag.specifier == COUNT)
			if ((ptr = va_arg(ap, int *)))
				*ptr = ret;
		ret += parse_str(&str, &tag);
	}
	va_end(ap);
	free(dispatch_table);
	return (ret);
}

//		printf(">>flags = %d\n>>width = %d\n>>precision = %d\n>>specifier = %d\n", tag.flags, tag.width, tag.precision, tag.specifier);
