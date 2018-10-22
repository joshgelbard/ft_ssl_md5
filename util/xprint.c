/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:18 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:18 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <unistd.h>

void	xprint(char *s)
{
	size_t len;

	len = xstrlen(s);
	write(STDOUT_FILENO, s, len);
}

void	xprinterr(char *s)
{
	size_t	len;

	len = xstrlen(s);
	write(STDERR_FILENO, s, len);
}

void	xputs(char *s)
{
	xprint(s);
	xprint("\n");
}

void	xputserr(char *s)
{
	xprinterr(s);
	xprinterr("\n");
}
