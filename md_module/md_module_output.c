/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_module_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:10 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:10 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md_module_output.h"
#include <stdio.h>
#include "md_module_internal.h"
#include "algorithm_lookup.h"
#include "hash_algorithm.h"
#include "hash_digest_common.h"
#include "hash_ctx.h"
#include "util.h"

char		*g_allcaps_algo_names[HASH_ALGORITHM_COUNT] =
{
	[MD5] = "MD5",
	[SHA256] = "SHA256",
};

static void	md_print_tag(char *tag)
{
	if (g_md_io_opts.digest_before_tag == 0)
	{
		xprint(g_allcaps_algo_names[g_md_ctx.class->algorithm_id]);
		xprint(" (");
	}
	else
		xprint(" ");
	if (g_md_io_opts.quote == 1)
		xprint("\"");
	xprint(tag);
	if (g_md_io_opts.quote == 1)
		xprint("\"");
	if (g_md_io_opts.digest_before_tag == 0)
		xprint(") = ");
}

void		md_output(char *tag)
{
	char	*digest;

	digest = hash_get_string(&g_md_ctx);
	if (g_md_io_opts.quiet_mode == 1 || tag == NULL)
	{
		xputs(digest);
		free(digest);
		return ;
	}
	if (g_md_io_opts.digest_before_tag)
	{
		xprint(digest);
		md_print_tag(tag);
		xputs("");
	}
	else
	{
		md_print_tag(tag);
		xputs(digest);
	}
	free(digest);
}
