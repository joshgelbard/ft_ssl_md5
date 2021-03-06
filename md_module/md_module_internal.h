/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_module_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:12 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:12 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD_MODULE_INTERNAL_H
# define MD_MODULE_INTERNAL_H

extern struct s_hash_ctx		g_md_ctx;
extern struct s_hash_algorithm	*g_md_algo;
extern struct					s_md_io_opts
{
	int		do_default_stdin;
	int		options_are_closed;
	int		digest_before_tag;
	int		quiet_mode;
	int		quote;
	int		echo;
	char	*tag;
	int		fd;
}								g_md_io_opts;
#endif
