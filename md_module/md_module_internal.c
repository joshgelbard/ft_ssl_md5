/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_module_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:12 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:12 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md_module_internal.h"
#include "hash_algorithm.h"
#include "hash_ctx.h"

struct s_hash_ctx g_md_ctx =
{
	.class = NULL,
	.message_bitsize = 0,
	.block = NULL,
	.block_offset = 0,
	.processed_blocks = 0,
	.digest = NULL,
};

struct s_md_io_opts g_md_io_opts =
{
	.do_default_stdin = 1,
	.options_are_closed = 0,
	.digest_before_tag = 0,
	.quiet_mode = 0,
	.quote = 0,
	.echo = 0,
	.tag = NULL,
	.fd = 0,
};

struct s_hash_algorithm *g_md_algo = NULL;
