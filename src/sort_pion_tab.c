/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pion_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 05:26:49 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:39:01 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		pioncpy(t_pion *dst, t_pion *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->coef = src->coef;
}

void		swap_pion(t_pion *tab, int i, int j)
{
	t_pion tmp;

	pioncpy(&tmp, &tab[i]);
	pioncpy(&tab[i], &tab[j]);
	pioncpy(&tab[j], &tmp);
}

void		sort_pion(t_filler *filler, t_pion *tab)
{
	int		i;
	int		j;

	i = filler->my_territory.nbr_of_pion;
	while (i > 1)
	{
		j = 0;
		while (j < i - 1)
		{
			if (tab[j + 1].coef < tab[j].coef)
				swap_pion(tab, j + 1, j);
			j++;
		}
		i--;
	}
}
