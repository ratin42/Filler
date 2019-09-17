/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:37:30 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:00:44 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

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

void		free_map(t_party *party)
{
	int		turn;

	turn = 0;
	if (party->map == NULL)
		return ;
	while (turn <= party->turn)
	{
		free_double_char(party->map[turn].image, party->height);
		turn++;
	}
	free(party->map);
	party->map = NULL;
}

void		free_prog(t_party *party)
{
	free(party->image);
	party->image = NULL;
	free(party->p1.name);
	party->p1.name = NULL;
	free(party->p2.name);
	party->p2.name = NULL;
	free(party->p1.score);
	party->p1.score = NULL;
	free(party->p2.score);
	party->p2.score = NULL;
	free_map(party);
}
