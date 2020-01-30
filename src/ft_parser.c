/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:23:16 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/30 17:29:13 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bit_flag_8	get_flags(char **str)
{
	int ret;
	t_bit_flag_8 flags;

	flags = 0;
	while ((ret = ft_strchr(FLAGS, **str)))
	{
		flags = flags & (1 << ret);
		(*str)++;
	}
	return (flags);
}

int				parse_str(char **str, t_tag *tag)
{
	int i;

	(void)tag;
	i = 0;
	while (**str)
	{
		if (**str == '%')
		{
			tag->flags = get_flags(str);
			
		}
	}
	return 0;
}

