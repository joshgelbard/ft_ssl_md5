/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_digesters.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:11 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:11 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD_DIGESTERS_H
# define MD_DIGESTERS_H

void	digest_file(int fileno, char *filename);
void	digest_string(char *s);
#endif
