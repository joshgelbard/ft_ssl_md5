#ifndef DIGEST_H
# define DIGEST_H

void define_digest_algorithms(void);
void do_hash_digest(char *algo_name, char *input);
char *get_last_digest_string(void);
#endif
