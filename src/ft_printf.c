/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:51:20 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/07 01:09:06 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	**init_dispatch_table(void)
{
	t_print	**table;

	if (!(table = malloc(sizeof(t_print *) * 12)))
		return (NULL);
	table[0] = &print_char;
	table[1] = &print_string;
	table[2] = &print_pointer;
	table[3] = &print_int;
	table[4] = &print_int;
	table[5] = &print_unsigned;
	table[6] = &print_hex;
	table[7] = &print_hex;
	table[8] = &print_percentage;
	table[9] = &print_count;
/*	table[10] = &print_double;
	table[11] = &print_e_or_f;
	table[12] = &print_science; */
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
		{
			ptr = va_arg(ap, int *);
			if (ptr)
				*ptr = ret;
		}
		ret += parse_str(&str, &tag);
	}
	va_end(ap);
	free(dispatch_table);
	return (ret);
}

#define INPUT "", (char)-10
/*
int main()
{
//	printf(">>%p<<\n", &i);
	int ret_libc = 1;
	int ret;
	ret = ft_printf(INPUT);
//	ret_libc = printf(INPUT);
	ft_printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	
}
*/
//		printf(">>flags = %d\n>>width = %d\n>>precision = %d\n>>specifier = %d\n", tag.flags, tag.width, tag.precision, tag.specifier);
