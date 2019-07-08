/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:25:22 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 13:25:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

void		data_init(t_data **data, int fd)
{
	t_data	*temp;

	if (INIT_DATA)
		error(ERR_ALLOC);
	ft_bzero(temp, sizeof(temp));
	temp->fd = fd;
	*data = temp;
}

void		token_add(t_data *data, t_type type)
{
	t_token	*new;

	if (INIT_TOKEN)
		error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	new->type = type;
	if (data->token)
		data->token->prev = new;
	new->next = data->token;
	data->token = new;
}

void		label_add(t_data *data)
{
	t_label	*new;

	if (INIT_TOKEN)
		error(ERR_ALLOC);
	ft_bzero(new, sizeof(new));
	data->token->type = LABEL;
	if (data->token)
		data->token->prev = new;
	new->next = data->token;
	data->token = new;
}
