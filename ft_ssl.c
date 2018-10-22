#include <stdio.h>
#include <stdlib.h>
#include "algorithm_lookup.h"
#include "ft_ssl_module_interface.h"
#include "util.h"

char	*g_progname = NULL;

int		main(int argc, char **argv)
{
	g_progname = argv[0];
	initialize_modules();
	if (load_module(argv[1]) == -1)
		return (1);
	return (module_run(argc, argv));
}
