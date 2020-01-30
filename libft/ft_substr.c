/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:56:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/01/15 19:16:47 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	l = ft_strlen(&(s[start])) < len ? ft_strlen(&(s[start])) : len;
	if (!(sub = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	(void)ft_strlcpy(sub, &(s[start]), l + 1);
	return (sub);
}
