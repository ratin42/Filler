/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:37:30 by ratin             #+#    #+#             */
/*   Updated: 2019/04/16 12:43:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		free_double_int(int **array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void		free_double_char(char **array, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

void		free_three_dimension(int ***array, int size_1, int size_2)
{
	int j;

	j = 0;
	while (j < size_1)
	{
		free_double_int(array[j], size_2);
		j++;
	}
	free(array);
}
