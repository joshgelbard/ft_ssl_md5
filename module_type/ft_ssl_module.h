#ifndef FT_SSL_MODULE_H
# define FT_SSL_MODULE_H

struct s_ft_ssl_module
{
	int		module_id;
	char	**matching_commands;
	int		(*run)(int argc, char **argv);
};
#endif
