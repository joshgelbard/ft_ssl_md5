#ifndef ALGORITHM_LOOKUP_H
# define ALGORITHM_LOOKUP_H

struct	s_hash_algorithm;

struct	s_hash_algorithm *get_hash_algorithm_by_name(char *name);
void	define_digest_algorithms(void);
#endif
