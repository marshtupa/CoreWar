/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_ops.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:54:46 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/09 19:12:59 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OPS_H
#define ASM_OPS_H

#include "com.h"

typedef struct		s_op
{
	char			*name;
	unsigned int	code;
	unsigned int	args_num;
	_Bool			args_types_code;
	unsigned int	args_types[3];
	unsigned int	t_dir_size;
}					t_op;


static t_op			g_op_tab[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = FALSE,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = TRUE,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = TRUE,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = FALSE,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = FALSE,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = TRUE,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = TRUE,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = FALSE,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = TRUE,
		.args_types = {T_REG, 0, 0},
		.t_dir_size = 4,
	}
};

#endif
