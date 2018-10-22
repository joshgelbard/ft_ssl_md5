/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 09:07:09 by jgelbard          #+#    #+#             */
/*   Updated: 2018/10/22 09:07:09 by jgelbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_INTERNAL_H
# define SHA256_INTERNAL_H
# include <stdint.h>

extern uint32_t g_sha256_k[64];
uint32_t g_sha256_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t g_sha256_maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t g_sha256_bsig(uint32_t x, int r1, int r2, int r3);
uint32_t g_sha256_ssig(uint32_t x, int r1, int r2, int s);
#endif
