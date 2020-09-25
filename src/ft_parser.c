/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:23:16 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/25 16:46:17 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bit_flag_8	get_flags(const char *str, int *pos)
{
	int				ret;
	t_bit_flag_8	flags;

	flags = 0;
	while (str[*pos] && (ret = ft_strchr(FLAGS, str[*pos])) != -1)
	{
		flags = flags | (1 << ret);
		(*pos)++;
	}
	return (flags);
}

int				get_width(const char *str, int *pos)
{
	int ret;

	if (str[*pos] == '*')
	{
		(*pos)++;
		return (-2);
	}
	ret = ft_atoi(&(str[*pos]));
	if (!ft_isdigit(str[*pos]))
		return (-1);
	while (ft_isdigit(str[*pos]))
		(*pos)++;
	return (ret);
}

int				get_precision(const char *str, int *pos)
{
	int ret;

	if (str[*pos] != '.')
		return (-1);
	(*pos)++;
	if (str[*pos] == '*')
	{
		(*pos)++;
		return (-2);
	}
	ret = ft_atoi(&(str[*pos]));
	while (ft_isdigit(str[*pos]))
		(*pos)++;
	return (ret);
}

t_length		*get_length(const char *str, int *pos)
{
	t_length *length;

	length = &get_regular;
	if (str[*pos] == 'l')
		length = &get_long;
	if (str[*pos] == 'l' && str[*pos + 1] == 'l')
		length = &get_long_long;
	if (str[*pos] == 'h')
 		length = &get_short;
	if (str[*pos] == 'h' && str[*pos + 1] == 'h')
		length = &get_short_short;
	if (length == &get_short || length == &get_long)
		(*pos)++;
	if (length == &get_short_short || length == &get_long_long)
		(*pos) += 2;
	return (length);
}

void			build_tag(t_tag *tag, const char *str, int *pos)
{
	tag->flags = get_flags(str, pos);
	tag->width = get_width(str, pos);
	tag->precision = get_precision(str, pos);
	tag->length = get_length(str, pos);
	tag->specifier = ft_strchr(TYPES, str[*pos]);
}
