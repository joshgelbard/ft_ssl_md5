/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zalloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:19 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:19 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

void	*zalloc(size_t len)
{
	void	*b;
	size_t	i;

	i = 0;
	b = malloc(len);
	while (i < len)
	{
		((unsigned char *)b)[i] = 0;
		i++;
	}
	return (b);
}
