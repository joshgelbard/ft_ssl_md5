/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_byte_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:21 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:21 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <string.h>

void	reverse_byte_order(void *p, size_t len)
{
	unsigned char	tmp;
	unsigned char	*pp;
	size_t			i;

	pp = (unsigned char *)p;
	i = 0;
	while (i < len / 2)
	{
		tmp = pp[i];
		pp[i] = pp[len - i - 1];
		pp[len - i - 1] = tmp;
		i++;
	}
}
