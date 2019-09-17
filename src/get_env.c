/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:13:26 by ratin             #+#    #+#             */
/*   Updated: 2019/05/10 03:07:37 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_size(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) != 1)
		return (0);
	if (ft_strstr(line, "Plateau ") == NULL || line == NULL)
	{
		free(line);
		return (0);
	}
	while (line[i] != ' ' && line[i])
		i++;
	i++;
	filler->map_height = ft_atoi(&line[i]);
	while (line[i] != ' ' && line[i])
		i++;
	filler->map_width = ft_atoi(&line[i]);
	free(line);
	if (filler->map_height == 0 || filler->map_width == 0)
		return (0);
	return (1);
}

static int	check_map(char *str)
{
	int		i;

	i = 4;
	while (str[i])
	{
		if (ft_strchr(".XxOo", str[i]) == NULL)
		{
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	fill_map(t_filler *filler, char *line, int i)
{
	line = NULL;
	if (get_next_line(0, &line) != 1)
		return (0);
	if (check_map(line) == 0)
		return (bad_map());
	if ((int)ft_strlen(line) != filler->map_width + 4)
	{
		free(line);
		return (0);
	}
	if (!(filler->map[i] = ft_strdup(&line[4])))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static int	start_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (!(filler->map = (char **)malloc(sizeof(char *)
	* (filler->map_height + 1))))
		return (0);
	if (get_next_line(0, &line) != 1)
		return (0);
	free(line);
	while (i < filler->map_height)
	{
		filler->map_free = i;
		if (!(fill_map(filler, line, i)))
			return (0);
		i++;
	}
	filler->map_free = i;
	filler->map[i] = 0;
	if (!(sertif_map(filler)))
		return (0);
	return (1);
}

int			get_env(t_filler *filler)
{
	int	turn;

	if ((turn = get_player(filler)) == 0)
		return (0);
	if (turn != 3)
	{
		if (get_size(filler) == 0)
			return (0);
	}
	if (start_map(filler) == 0)
		return (0);
	if (get_piece(filler) == 0)
		return (0);
	return (1);
}
