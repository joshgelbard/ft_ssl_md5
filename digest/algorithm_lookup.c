/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_lookup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:16 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:24:51 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm_lookup.h"
#include "hash_algorithm.h"
#include "md5_digest.h"
#include "sha256_digest.h"
#include "util.h"

static struct s_hash_algorithm	**g_algos;

struct s_hash_algorithm			*get_hash_algorithm_by_name(char *name)
{
	int	i;

	i = 0;
	while (i < HASH_ALGORITHM_COUNT)
	{
		if (!xstrcmp(g_algos[i]->algorithm_name, name))
			return (g_algos[i]);
		i++;
	}
	return (NULL);
}

struct s_hash_algorithm			*get_hash_algorithm_by_id(int id)
{
	int	i;

	i = 0;
	while (i < HASH_ALGORITHM_COUNT)
	{
		if (g_algos[i]->algorithm_id == id)
			return (g_algos[i]);
		i++;
	}
	return (NULL);
}

void							define_digest_algorithms(void)
{
	g_algos = zalloc(HASH_ALGORITHM_COUNT * sizeof(struct s_hash_algorithm *));
	g_algos[HASH_ALGORITHM_COUNT] = NULL;
	g_algos[0] = define_md5_algorithm();
	g_algos[1] = define_sha256_algorithm();
}
