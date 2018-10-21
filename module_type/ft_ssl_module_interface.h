#ifndef FT_SSL_MODULE_INTERFACE_H
# define FT_SSL_MODULE_INTERFACE_H

enum	e_ft_ssl_module
{
	MD_MODULE,
	MODULE_COUNT,
};

void	initialize_modules(void);
void	load_module_or_exit(char *module_name);
int		module_run(int argc, char **argv);
#endif
