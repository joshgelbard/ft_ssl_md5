/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_algorithm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:16 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:16 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_ALGORITHM_H
# define HASH_ALGORITHM_H
# include <string.h>

struct s_hash_ctx;

struct	s_hash_algorithm
{
	int		is_big_endian;
	void	(*finish_initialize)(struct s_hash_ctx *ctx);
	void	(*process_block)(struct s_hash_ctx *ctx);
	char	*(*to_string)(struct s_hash_ctx *ctx);
	size_t	block_size;
	size_t	word_size;
	size_t	digest_size;
	char	*algorithm_name;
	int		algorithm_id;
};
#endif
