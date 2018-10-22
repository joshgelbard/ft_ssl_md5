/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:20 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:20 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <string.h>
#include <stdio.h>

static void	byte2string(char *s, unsigned char b)
{
	s[0] = (b >> 4) < 10 ? (b >> 4) + '0' : (b >> 4) + 'a' - 10;
	s[1] = (b & 0x0f) < 10 ? (b & 0x0f) + '0' : (b & 0x0f) + 'a' - 10;
}

void		mem2string(void *p, size_t len, char *s)
{
	size_t			i;
	unsigned char	*pp;

	pp = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		byte2string(s + i * 2, pp[i]);
		i++;
	}
}
