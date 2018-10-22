/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_module.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:09 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:09 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MODULE_H
# define FT_SSL_MODULE_H

struct	s_ft_ssl_module
{
	int		module_id;
	char	**matching_commands;
	int		(*run)(int argc, char **argv);
};
#endif
