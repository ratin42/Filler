/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:12:10 by ratin             #+#    #+#             */
/*   Updated: 2019/04/21 20:07:21 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

char		*get_game(t_game *game)
{
	int		ret;
	int		i;
	char	*line;
	char	*game;

	game = NULL;
	line = NULL;
	ret = 1;
	i = 0;
	ft_putstr("partie en cours...\n");
	while (1)
	{
		printf("\rtour %d", i);
		if ((ret = get_next_line(0, &line)) == -1)
			return (0);
		if (ft_strstr(line, "fin") != NULL)
			break ;
		if (ft_strstr(line, "Plateau") != NULL)
			i++;
		game = ft_strjoin_free(game, line, 3);
		game = ft_strjoin_free(game, "\n", 1);
	}
	(void)filler;
	return (game);
}

int			parse_game(t_game *game)
{
	char	*game;

	game = get_game(filler);
	init_game(game);
	printf("%s\n", game);
	return (1);
}
