/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:04:44 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/29 19:21:03 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

static void	find_info_string(t_token **temp, _Bool type, int *arg)
{
	*temp = (*temp)->prev;
	if (*temp && (*temp)->type == STRING)
		*temp = (*temp)->prev;
	else if (type)
		error_event(ERR_NO_CHNAME);
	else
		error_event(ERR_NO_CHCOMM);
	(*arg)--;
}

void		valid_champion_info(t_token **temp)
{
	int		i;
	int		name;
	int		comm;

	name = 1;
	comm = 1;
	i = 3;
	while (--i)
	{
		while (*temp && (*temp)->type == NEW_LINE)
			*temp = (*temp)->prev;
		if ((*temp)->type != COMMAND)
			error_token(ERR_WRTYPE, *temp);
		if (ft_strcmp((*temp)->content, "comment"))
			find_info_string(temp, 0, &comm);
		else if (ft_strcmp((*temp)->content, "name"))
			find_info_string(temp, 1, &name);
	}
	if (name != 0 || comm != 0 || (*temp)->type != NEW_LINE)
		error_event(ERR_NAMECOM);
}

t_token		*print_champion_info(t_token *temp)
{
	int		i;

	i = 3;
	while (--i)
	{
		while (temp && temp->type == NEW_LINE)
			temp = temp->prev;
		if (!ft_strcmp(temp->content, "comment"))
		{
			temp = temp->prev;
			ft_memcpy(g_buf + 4 + PROG_NAME_LENGTH + 4 * 2,
					temp->content, ft_strlen(temp->content));
		}
		else if (!ft_strcmp(temp->content, "name"))
		{
			temp = temp->prev;
			ft_memcpy(g_buf + 4, temp->content, ft_strlen(temp->content));
		}
		else
			error_event(ERR_NAMECOM);
		temp = temp->prev;
	}
	return (temp);
}
