/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:23:16 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/01 04:58:53 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bit_flag_8	get_flags(char **str)
{
	int				ret;
	t_bit_flag_8	flags;

	flags = 0;
	while (**str && (ret = ft_strchr(FLAGS, **str)) != -1)
	{
		flags = flags | (1 << ret);
		(*str)++;
	}
	return (flags);
}

int				get_width(char **str)
{
	int ret;

	ret = ft_atoi(*str);
	if (!ft_isdigit(**str))
		return (-1);
	while (ft_isdigit(**str))
		(*str)++;
	return (ret);
}

int				get_precision(char **str)
{
	int ret;

	ret = ft_atoi((*str) + 1);
	if (**str != '.')
		return (-1);
	(*str)++;
	while (ft_isdigit(**str))
		(*str)++;
	return (ret);
}

t_length		get_length(char **str)
{
	t_length length;

	length = REGULAR;
	if (**str == 'l')
		length = LONG;
	if (**str == 'l' && *((*str) + 1) == 'l')
		length = LONG_LONG;
	if (**str == 'h')
		length = SHORT;
	if (**str == 'h' && *((*str) + 1) == 'h')
		length = SHORT_SHORT;
	if (length == SHORT || length == LONG)
		(*str)++;
	if (length == SHORT_SHORT || length == LONG_LONG)
		*str += 2;
	return (length);
}

int				parse_str(char **str, t_tag *tag)
{
	char	*cpy;

	while (**str)
	{
		if (**str == '%')
		{
			if (!(cpy = ft_substr(*str, 1, ft_strlen(*str))))
				return (-1);
			tag->flags = get_flags(&cpy);
			tag->width = get_width(&cpy);
			tag->precision = get_precision(&cpy);
			tag->length = get_length(&cpy);
			tag->specifier = ft_strchr(TYPES, *cpy);
			if (tag->specifier != NONE && tag->specifier != PERCENTAGE)
			{
				*str = cpy + 1;
				return (1);
			}
		}
		if (**str == '%' && *((*str) + 1) == '%')
			(*str)++;
		write(1, *str, 1);
		(*str)++;
	}
	return (0);
}
