/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:51:47 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/10 19:27:56 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
struct	oui
{
	int c;
};
int main()
{
	struct oui a;
	struct oui b;
	a.c = 1;
	b.c = 2;
	printf("%d\n", (0 < 1 ? a : b).c);
}
