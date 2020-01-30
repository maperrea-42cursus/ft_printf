/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:36:16 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/09 13:41:41 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;

	if (!(dup = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	(void)ft_strlcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}
