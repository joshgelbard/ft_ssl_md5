/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:14 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:14 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_INTERNAL_H
# define MD5_INTERNAL_H
# include <stdint.h>

uint32_t	g_md5_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t	g_md5_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t	g_md5_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t	g_md5_i(uint32_t x, uint32_t y, uint32_t z);
extern		uint32_t g_md5_t[64];
extern		int g_md5_s[4][4];
extern		int g_md5_k[4][16];
#endif
