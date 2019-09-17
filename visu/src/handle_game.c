/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:07:35 by Raphael           #+#    #+#             */
/*   Updated: 2019/04/26 17:00:41 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int		jump_line(t_party *party, int line, int i)
{
	while (line > 0)
	{
		if (party->image[i] == '\n')
			line--;
		i++;
	}
	return (i);
}

int		line_cpy(t_party *party, int i, int turn, int y)
{
	int	x;

	i += 4;
	x = 0;
	while (party->image[i] != '\n')
	{
		party->map[turn].image[y][x] = party->image[i];
		x++;
		i++;
	}
	i++;
	party->map[turn].image[y][x] = '\0';
	return (i);
}

int		put_map(t_party *party, int i, int turn)
{
	int	y;

	y = 0;
	while (y < party->height)
	{
		i = line_cpy(party, i, turn, y);
		y++;
	}
	party->map[turn].image[y] = 0;
	return (i);
}

int		fill_map(t_party *party)
{
	int	i;
	int	turn;

	i = 0;
	turn = 0;
	while (turn < party->turn)
	{
		while (ft_strncmp(&party->image[i], "Plateau", 7) != 0 && party->image)
			i++;
		i = jump_line(party, 2, i);
		i = put_map(party, i, turn);
		party->p1.score[turn] = 0;
		party->p2.score[turn] = 0;
		get_score(party, turn);
		turn++;
	}
	return (1);
}

int		init_game(t_party *party)
{
	party->turn = 0;
	party->finished = 0;
	party->p1.name = NULL;
	party->p2.name = NULL;
	party->p1.score = NULL;
	party->p2.score = NULL;
	get_info(party);
	if (!(party->p1.score = (int *)malloc(sizeof(int) * party->turn)))
		quit_fdf(party);
	if (!(party->p2.score = (int *)malloc(sizeof(int) * party->turn)))
		quit_fdf(party);
	if (!(give_map_memory(party)))
		quit_fdf(party);
	fill_map(party);
	return (1);
}
