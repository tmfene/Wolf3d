/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:08:40 by tmfene            #+#    #+#             */
/*   Updated: 2018/09/04 09:44:43 by tmfene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map(char *buff, t_wolf3d *t)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	t->lenline = ft_linelen(buff);
	t->nb_lines = ft_countlines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != t->lenline)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int		check_side(t_wolf3d *t)
{
	int	i;

	i = 0;
	while (i < t->lenline)
	{
		if (t->map[0][i] == 0)
			return (0);
		if (t->map[t->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < t->nb_lines)
	{
		if (t->map[i][0] == 0)
			return (0);
		if (t->map[i][t->lenline - 1] == 0)
			return (0);
		i++;
	}
	if (t->map[3][3] != 0)
		return (0);
	return (1);
}
