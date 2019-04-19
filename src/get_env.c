/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:13:26 by ratin             #+#    #+#             */
/*   Updated: 2019/04/17 19:04:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	get_size(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) == -1)
		return (0);
	if (ft_strstr(line, "Plateau") == NULL || line == NULL)
	{
		return (0);
	}
	while (line[i] != ' ')
		i++;
	i++;
	filler->map_height = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	filler->map_width = ft_atoi(&line[i]);
	free(line);
	return (1);
}

static int	check_map(char *str)
{
	int		i;

	i = 4;
	while (str[i])
	{
		if (ft_strchr(".XxOo", str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int	fill_map(t_filler *filler, char *line, int i)
{
	if (get_next_line(0, &line) == -1)
		return (0);
	if (check_map(line) == 0)
		return (0);
	if ((int)ft_strlen(line) != filler->map_width + 4)
		return (0);
	if (!(filler->map[i] = ft_strdup(&line[4])))
		return (0);
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
	if (get_next_line(0, &line) == -1)
		return (0);
	free(line);
	while (i < filler->map_height)
	{
		if (!(fill_map(filler, line, i)))
			return (0);
		filler->map_free = i;
		i++;
	}
	filler->map_free = i;
	filler->map[i] = 0;
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
