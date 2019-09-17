/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sertif_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:14:37 by ratin             #+#    #+#             */
/*   Updated: 2019/04/27 19:41:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_starter(t_filler *filler)
{
	int		y;
	int		x;
	int		start;

	start = 0;
	y = 0;
	while (y < filler->map_height)
	{
		x = 0;
		while (x < filler->map_width)
		{
			if (filler->player == 1 && filler->map[y][x] == 'O')
				start = 1;
			if (filler->player == 2 && filler->map[y][x] == 'X')
				start = 1;
			x++;
		}
		y++;
	}
	if (start == 0)
		return (0);
	return (1);
}

int			bad_map(void)
{
	ft_putstr_fd("bad map ", 2);
	ft_putstr_fd("0 0", 1);
	return (0);
}

int			sertif_map(t_filler *filler)
{
	if (!(check_starter(filler)))
		return (bad_map());
	return (1);
}
