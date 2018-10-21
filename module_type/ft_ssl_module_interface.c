#include "ft_ssl_module_interface.h"
#include "ft_ssl_module.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "md_module.h"

static struct s_ft_ssl_module **g_modules;
static struct s_ft_ssl_module *g_active_module;

void	initialize_modules(void)
{
	g_modules = malloc(sizeof(*g_modules) * (MODULE_COUNT + 1));
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
	
	xputs("Standard commands:");
	i = 0;
	while (std_cmds[i])
		xputs(std_cmds[i++]);
	xputs("\nMessage Digest commands:");
	i = 0;
	while (md_cmds[i])
		xputs(md_cmds[i++]);
	xputs("\nCipher commands:");
	i = 0;
	while (cipher_cmds[i])
		xputs(cipher_cmds[i++]);
}

void	load_module_or_exit(char *command_name)
{
	if (!command_name)
	{
		xputs("usage: ft_ssl command [command opts] [command args]");
		exit(1);
	}
	if (!(g_active_module = get_module_for_command_name(command_name)))
	{
		xprint("ft_ssl: Error: ");
		xprint(command_name);
		xputs(" is an invalid command.");
		list_available_commands();
		exit(1);
	}
}

int		module_run(int argc, char **argv)
{
	return (g_active_module->run(argc, argv));
}
