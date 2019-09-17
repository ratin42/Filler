/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:04:18 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:02:32 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void	get_turn(t_party *party)
{
	int	i;

	i = 0;
	while (party->image[i])
	{
		if (ft_strncmp(&party->image[i], "Plateau", 7) == 0)
			party->turn++;
		i++;
	}
}

void	get_info(t_party *party)
{
	int	i;

	i = 0;
	get_turn(party);
	get_player(party);
	while (ft_strncmp(&party->image[i], "Plateau", 7) != 0 && party->image)
		i++;
	while (party->image[i] != ' ')
		i++;
	i++;
	party->height = ft_atoi(&party->image[i]);
	while (party->image[i] != ' ')
		i++;
	party->width = ft_atoi(&party->image[i]);
}

int		give_map_memory(t_party *party)
{
	int	turn;
	int	y;

	turn = 0;
	if (!(party->map = (t_map *)malloc(sizeof(t_map) * party->turn + 1)))
		return (0);
	while (turn <= party->turn)
	{
		if (!(party->map[turn].image = (char **)malloc(sizeof(char *)
		* party->height + 1)))
			return (0);
		y = 0;
		while (y < party->height)
		{
			if (!(party->map[turn].image[y] = (char *)malloc(sizeof(char)
			* party->width + 1)))
				return (0);
			y++;
		}
		turn++;
	}
	return (1);
}
