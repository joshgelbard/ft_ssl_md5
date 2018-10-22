#include "ft_ssl_module_interface.h"
#include "ft_ssl_module.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "md_module.h"
#include <sys/errno.h>

static struct s_ft_ssl_module **g_modules;
static struct s_ft_ssl_module *g_active_module;

void	initialize_modules(void)
{
	g_modules = zalloc(sizeof(*g_modules) * (MODULE_COUNT + 1));
	g_modules[0] = initialize_md_module();
}

struct s_ft_ssl_module	*get_module_for_command_name(char *cmd)
{
	int		i;
	int		j;

	if (!cmd)
		return (NULL);
	i = 0;
	while (i < MODULE_COUNT)
	{
		j = 0;
		while (g_modules[i]->matching_commands[j])
		{
			if (!xstrcmp(g_modules[i]->matching_commands[j], cmd))
			{
				g_modulename = cmd;
				return (g_modules[i]);
			}
			j++;

		}
		i++;
	}
	return (NULL);
}

static void list_available_commands(void)
{
	char	*std_cmds[] = { NULL };
	char	*cipher_cmds[] = { NULL };
	char	**md_cmds = g_modules[MD_MODULE]->matching_commands;

	int i;

	xputserr("\nStandard commands:");
	i = 0;
	while (std_cmds[i])
		xputserr(std_cmds[i++]);
	xputserr("\nMessage Digest commands:");
	i = 0;
	while (md_cmds[i])
		xputserr(md_cmds[i++]);
	xputserr("\nCipher commands:");
	i = 0;
	while (cipher_cmds[i])
		xputserr(cipher_cmds[i++]);
}

int		load_module(char *command_name)
{
	if (!command_name)
	{
		xputserr("usage: ft_ssl command [command opts] [command args]");
		return (-1);
	}
	if (!(g_active_module = get_module_for_command_name(command_name)))
	{
		errno = EINVAL;
		xperror(command_name);
		list_available_commands();
		return (-1);
	}
	return (0);
}

int		module_run(int argc, char **argv)
{
	return (g_active_module->run(argc, argv));
}
