#include "md_module.h"
#include "ft_ssl_module_interface.h"
#include "ft_ssl_module.h"
#include <stdio.h>
#include "hash_algorithm.h"
#include "algorithm_lookup.h"
#include "md_module_internal.h"
#include "hash_digest_common.h"
#include <unistd.h>
#include <fcntl.h>
#include "md_digesters.h"
#include "util.h"

static int		g_argc;
static char		**g_argv;
static char		**g_arg;

static void	md_parse_option()
{
	if (!xstrcmp(*g_arg, "-r"))
	{
		g_md_io_opts.digest_before_tag = 1;
	}
	else if (!xstrcmp(*g_arg, "-q"))
	{
		g_md_io_opts.quiet_mode = 1;
	}
	else if (!xstrcmp(*g_arg, "-p"))
	{
		g_md_io_opts.do_default_stdin = 0;
		g_md_io_opts.echo = 1;
		digest_file(STDIN_FILENO, NULL);
	}
	else if (!xstrcmp(*g_arg, "-s") && g_arg[1] != NULL)
	{
		g_md_io_opts.do_default_stdin = 0;
		g_arg++;
		digest_string(*g_arg);
	}
	else
	{
		g_md_io_opts.do_default_stdin = 0;
		g_md_io_opts.options_are_closed = 1;
		g_arg--;
	}
	g_arg++;
}

static void	md_parse_arg(void)
{
	int		fd;

	if ((fd = open(*g_arg, O_RDONLY)) == -1)
	{
		xperror(*g_arg);
	}
	else
	{
		g_md_io_opts.echo = 0;
		digest_file(fd, *g_arg);
		close(fd);
	}
	g_arg++;
}

static int		md_module_run(int argc, char **argv)
{
	define_digest_algorithms();
	g_md_algo = get_hash_algorithm_by_name(argv[1]);
	g_argc = argc;
	g_argv = argv;
	g_arg = argv + 2;
	while (g_arg < g_argv + g_argc && !g_md_io_opts.options_are_closed)
	{
		md_parse_option();
	}
	while (g_arg < g_argv + g_argc)
	{
		md_parse_arg();
	}
	if (g_md_io_opts.do_default_stdin)
		digest_file(STDIN_FILENO, NULL);
	return (0);
}

static char	*md_module_commands[] =
{
	"md5",
	"sha256",
	NULL
};

struct s_ft_ssl_module	*initialize_md_module(void)
{
	struct s_ft_ssl_module	*md_module;

	md_module = zalloc(sizeof(*md_module));

	md_module->module_id = MD_MODULE;
	md_module->matching_commands = md_module_commands;
	md_module->run = &md_module_run;
	return (md_module);
}
