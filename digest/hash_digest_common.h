/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_digest_common.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:15 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:15 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_DIGEST_COMMON_H
# define HASH_DIGEST_COMMON_H
# include <stdlib.h>

struct s_hash_ctx;
struct s_hash_algorithm;

void hash_initialize(struct s_hash_algorithm *class,
		struct s_hash_ctx *instance);
void hash_update(struct s_hash_ctx *this,
		void *data, size_t data_len);
void hash_finalize(struct s_hash_ctx *this);
char *hash_get_string(struct s_hash_ctx *this);
#endif
