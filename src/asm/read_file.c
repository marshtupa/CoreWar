/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:40:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/16 15:51:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	valid_filename(char *fname)
{
	while(*fname != '\0')
	{
		if (*fname == '.')
			break;
		fname++;
	}
	if (ft_strcmp(fname, ".s"))
		print_error(ERR_FNAME);
}

void		read_file(char *filename)
{
	t_token		*code;

	data_init();
	valid_filename(filename);
	if ((g_data->fd = open(filename, O_RDONLY)) == -1)
		errorr(ERR_FOPEN);
	g_data->filename = filename;
	lexical_analyzer();
	code = g_data->token;
	while (code->next)
		code = code->next;
	// valid_champion_info(&code);
	while ((code->prev->type == NEW_LINE || code->prev->type == COMMAND
			|| code->prev->type == STRING) && code->prev)
		code = code->prev;
	ft_printf("Token: type=%d, cont=%s\n", code->type, code->content);
	syntax_analyser(code);
	// translate(code, g_bytes);
	// write_to_file();
	// free_data(g_data);
}