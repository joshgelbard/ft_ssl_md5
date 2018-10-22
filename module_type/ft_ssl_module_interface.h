/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_module_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:10 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:10 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MODULE_INTERFACE_H
# define FT_SSL_MODULE_INTERFACE_H

enum	e_ft_ssl_module
{
	MD_MODULE,
	MODULE_COUNT,
};

void	initialize_modules(void);
int		load_module(char *module_name);
int		module_run(int argc, char **argv);
#endif
