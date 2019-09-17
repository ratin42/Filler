/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:26:49 by ratin             #+#    #+#             */
/*   Updated: 2019/05/10 02:42:58 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	get_player(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) != 1)
		return (0);
	if (line == NULL || ft_strstr(line, "$$$ exec p") == NULL)
	{
		free(line);
		if (filler->player == 0)
			return (0);
		return (3);
	}
	while (line[i] != 'p' && line[i])
		i++;
	i++;
	filler->player = ft_atoi(&line[i]);
	free(line);
	if (filler->player == 1)
		filler->pion = 'O';
	else if (filler->player == 2)
		filler->pion = 'X';
	else
		return (0);
	return (1);
}
