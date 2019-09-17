/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:12:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/10 02:43:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void		error_get_game(char *line)
{
	free(line);
	printf("\rERROR");
	exit(1);
}

static int	count(char *line, int i)
{
	if (ft_strstr(line, "Plateau") != NULL)
		return (i + 1);
	return (i);
}

char		*get_game(void)
{
	int		i;
	int		k;
	char	*line;
	char	*game;

	game = NULL;
	line = NULL;
	i = 0;
	k = -1;
	while (++k > -1)
	{
		printf("\rLoading %d", i);
		if (get_next_line(0, &line) != 1)
			error_get_game(line);
		if (line == NULL || ft_strncmp(line, "error", 5) == 0 || (k == 0
		&& ft_strstr(line, "VM  version 1.1") == NULL))
			error_get_game(line);
		game = ft_strjoin_free(game, line, 3);
		game = ft_strjoin_free(game, "\n", 1);
		if (ft_strstr(line, "fin") != NULL)
			break ;
		i = count(line, i);
	}
	printf("\n");
	return (game);
}

int			parse_game(t_party *party)
{
	party->pause = 0;
	party->image = get_game();
	return (1);
}
