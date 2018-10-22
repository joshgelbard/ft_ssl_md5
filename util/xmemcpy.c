/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmemcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:19 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:19 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	xmemcpy(void *dst, void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}
