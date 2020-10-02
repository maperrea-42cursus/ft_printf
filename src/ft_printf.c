/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:51:20 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 13:50:22 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		**init_dispatch_table(void)
{
	t_print	**table;

	if (!(table = malloc(sizeof(t_print *) * 13)))
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
	table[E_OR_F] = &print_e_or_f;
	table[SCIENCE] = &print_science;
	return (table);
}

int			parse_str(const char **str, t_tag *tag)
{
	int		pos;
	int		i;

	i = 0;
	while (**str)
	{
		if (**str == '%')
		{
			pos = 1;
			build_tag(tag, *str, &pos);
			if (tag->specifier != NONE || (**str == '%' && *(*str + 1) == 0))
			{
				*str += pos + 1;
				return (i);
			}
			(*str)++;
		}
		write(1, *str, 1);
		(*str)++;
		i++;
	}
	tag->specifier = NONE;
	return (i);
}

int			ft_printf(const char *str, ...)
{
	va_list ap;
	t_print	**dispatch_table;
	t_tag	tag;
	int		ret;
	int		*ptr;

	if (!str)
		return (-1);
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
