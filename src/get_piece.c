/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:02:18 by ratin             #+#    #+#             */
/*   Updated: 2019/05/10 03:05:20 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	int	piece_info(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
			return (0);
		i++;
	}
	i++;
	filler->piece.y = ft_atoi(&line[i]);
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
			return (0);
		i++;
	}
	filler->piece.x = ft_atoi(&line[i]);
	if (filler->piece.y == 0 || filler->piece.x == 0)
		return (0);
	return (1);
}

static int	fill_piece(t_filler *filler, int i)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	if ((int)ft_strlen(line) != filler->piece.x)
	{
		free(line);
		return (0);
	}
	filler->piece.piece[i] = ft_strdup(line);
	filler->piece.piece_free = i;
	free(line);
	return (1);
}

int			get_piece(t_filler *filler)
{
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	if (!(piece_info(filler, line)))
	{
		free(line);
		return (0);
	}
	free(line);
	if (!(filler->piece.piece = (char **)malloc(sizeof(char *)
	* (filler->piece.y + 1))))
		return (0);
	while (++i < filler->piece.y)
	{
		filler->piece.piece_free = i;
		if (!(fill_piece(filler, i)))
			return (0);
	}
	filler->piece.piece[i] = 0;
	filler->piece.piece_free = i;
	return (1);
}
