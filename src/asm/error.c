/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/15 19:20:51 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void	errorr(char *event, int y, int x)
{
	char *place;

	if (x != -1 && y != -1)
		place_write(y, x);
	ft_putendl_fd(place, 2);
	print_error(event);
	g_data->fd ? fclose(g_data->fd) : 1;
	free_data(g_data);
	exit(1);
}

void	place_write(int y, int x)
{
	write(2, "\nLn ", 5);
	ft_putnbr(y);
	write(2, ", Col:", 6);
	ft_putnbr(x);
	write(2, '\n', 1);
}

void	free_data(t_data *data)
{
	if (data->filename)
		free(data->filename);
	if (data->token)
		free_token(data->token);
	if (data->label)
		free_label(data->label);
	if (data->op_type);
		free_op_type(data->op_type);
	free(data);
}

void	free_token(t_token *token)
{
	t_token	*temp;

	while (token)
	{
		free(token->content);
		temp = token;
		token = token->prev;
		free(temp);
	}
}

void	free_label(t_label *label)
{
	t_label	*temp;

	while (label)
	{
		free(label->name);
		temp = label;
		label = label->next;
		free(temp);
	}
}

