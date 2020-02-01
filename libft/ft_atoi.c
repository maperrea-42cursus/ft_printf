/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:31:40 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/31 22:21:35 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_len(const char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	unsigned long	result;
	int				neg;
	int				i;

	result = 0;
	i = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = str[i++] == '-' ? 1 : 0;
	if (atoi_len(&(str[i])) > 10)
		return (neg > 0 ? 0 : -1);
	if (atoi_len(&(str[i])) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
		return (neg > 0 ? 0 : -1);
	while (str[i] >= 48 && str[i] <= 57)
		result = (result * 10) + (str[i++] - 48);
	return (neg == 1 ? result * -1 : result);
}
