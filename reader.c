/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:53:32 by tmfene            #+#    #+#             */
/*   Updated: 2018/09/04 09:45:35 by tmfene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_countlines(char *str)
{
	int			lines;

	lines = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}

size_t		ft_linelen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int			read_map(t_wolf3d *t, char **av)
{
	int			i;
	int			j;
	int			k;
	char		*str;

	i = 0;
	t->fd = open(av[1], O_RDONLY);
	while (get_next_line(t->fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
			return (0);
		while (++j < t->lenline)
		{
			if (str[k] == ' ')
				k++;
			t->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	free(str);
	return (1);
}

void		get_map2(t_wolf3d *t, char *buff, char **av)
{
	int			i;
	int			fd;

	fd = 0;
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			t->lenline--;
		i++;
	}
	ft_strdel(&buff);
	close(fd);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->nb_lines))
			|| !(read_map(t, av)))
		return ;
	if (!check_side(t))
	{
		ft_putstr("Map error\n");
		return ;
	}
}

int			get_map(t_wolf3d *t, char **av)
{
	int			fd;
	char		*buff;
	int			i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr("wolf3d: ");
		ft_putstr(av[1]);
		ft_putstr(": No such file\n");
		return (0);
	}
	if (!(check_map(buff, t)))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	get_map2(t, buff, av);
	return (1);
}
