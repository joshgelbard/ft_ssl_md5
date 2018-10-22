/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:16 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:16 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_LOOKUP_H
# define ALGORITHM_LOOKUP_H

enum					e_hash_algorithm
{
	MD5,
	SHA256,
	HASH_ALGORITHM_COUNT
};

struct s_hash_algorithm;

struct s_hash_algorithm	*get_hash_algorithm_by_name(char *name);
struct s_hash_algorithm	*get_hash_algorithm_by_id(int id);
void					define_digest_algorithms(void);
#endif
