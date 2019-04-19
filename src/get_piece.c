/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:02:18 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:38:11 by ratin            ###   ########.fr       */
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
		{
			free(line);
			return (0);
		}
		i++;
	}
	i++;
	filler->piece.y = ft_atoi(&line[i]);
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
		{
			free(line);
			return (0);
		}
		i++;
	}
	filler->piece.x = ft_atoi(&line[i]);
	return (1);
}

static int	fill_piece(t_filler *filler, int i)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
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
	if (get_next_line(0, &line) == -1)
		return (0);
	if (!(piece_info(filler, line)))
		return (0);
	free(line);
	if (!(filler->piece.piece = (char **)malloc(sizeof(char *)
	* (filler->piece.y + 1))))
	{
		free(line);
		return (0);
	}
	while (++i < filler->piece.y)
		fill_piece(filler, i);
	filler->piece.piece[i] = 0;
	filler->piece.piece_free = i;
	return (1);
}
