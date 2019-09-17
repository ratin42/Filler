/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:27:16 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:06:35 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

char			*get_name(t_party *party, int i)
{
	int			len;
	char		*name;

	len = 0;
	while (party->image[i] != '\0' && ft_strncmp(&party->image[i], ".filler", 7)
	!= 0)
		i++;
	while (party->image[i] != '/')
	{
		len++;
		i--;
	}
	i++;
	if (!(name = ft_strndup(&party->image[i], len - 1)))
		return (0);
	return (name);
}

void			get_score(t_party *party, int turn)
{
	int			y;
	int			x;

	y = 0;
	while (y < party->height)
	{
		x = 0;
		while (x < party->width)
		{
			if (party->map[turn].image[y][x] == 'O'
			|| party->map[turn].image[y][x] == 'o')
				party->p1.score[turn]++;
			if (party->map[turn].image[y][x] == 'X'
			|| party->map[turn].image[y][x] == 'x')
				party->p2.score[turn]++;
			x++;
		}
		y++;
	}
}

void			get_player_name(t_party *party, int i)
{
	t_player	*player;

	while (party->image[i] != 'p')
		i++;
	i++;
	if (ft_atoi(&party->image[i]) == 1)
		player = &party->p1;
	else
		player = &party->p2;
	player->name = get_name(party, i);
}

void			get_player(t_party *party)
{
	int			i;

	i = 0;
	while (party->image[i])
	{
		if (ft_strncmp(&party->image[i], "$$$", 3) == 0)
			get_player_name(party, i);
		i++;
	}
}
