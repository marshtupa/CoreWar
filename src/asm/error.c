/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:57:52 by gdamion-          #+#    #+#             */
/*   Updated: 2019/07/07 10:49:57 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "com.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//here we clean all lists and allocated info
void	free_info()
{

}

void	error(char *err_place, int str_no, int col_no)
{
	ft_printf("Error: %s, string %d col %d\n", err_place, str_no, col_no);
	fclose(); //close file
	free_info();
	exit(1);
}
