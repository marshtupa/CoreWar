/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 21:38:07 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/28 20:21:13 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "com.h"

int		main(int ac, char **av)
{
	errno = 0;
	g_data = 0;
	g_bytes = 0;
	g_buf = NULL;
	if (ac == 2)
		read_file(av[1], 0);
	else if (ac == 3 && !ft_strcmp(av[2], "-test"))
		read_file(av[1], 1);
	else
		error_event(ERR_NOFILE);
	return (0);
}
