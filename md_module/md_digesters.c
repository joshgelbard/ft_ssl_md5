/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_digesters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:12 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:12 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md_digesters.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "md_module_internal.h"
#include "hash_digest_common.h"
#include "md_module_output.h"
#include <string.h>
#include "hash_ctx.h"
#include "util.h"

void	digest_file(int fileno, char *filename)
{
	char	buf[BUFSIZ];
	ssize_t	count;

	hash_initialize(g_md_algo, &g_md_ctx);
	while ((count = read(fileno, buf, BUFSIZ - 1)) > 0)
	{
		buf[count] = '\0';
		if (g_md_io_opts.echo == 1)
			xprint(buf);
		hash_update(&g_md_ctx, buf, count);
	}
	hash_finalize(&g_md_ctx);
	g_md_io_opts.quote = 0;
	md_output(filename);
}

void	digest_string(char *s)
{
	hash_initialize(g_md_algo, &g_md_ctx);
	hash_update(&g_md_ctx, s, xstrlen(s));
	hash_finalize(&g_md_ctx);
	g_md_io_opts.quote = 1;
	md_output(s);
}
