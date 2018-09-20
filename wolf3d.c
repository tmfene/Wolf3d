/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:07:20 by tmfene            #+#    #+#             */
/*   Updated: 2018/09/04 09:45:52 by tmfene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	wolf3d_init(t_wolf3d *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0;
	t->y_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->x_text = 0;
	t->y_text = 0;
}

int		main(int argc, char **argv)
{
	t_wolf3d *t;

	if (argc != 2)
	{
		ft_putstr(" How to run: ./wolf3d maps/map\n");
		return (0);
	}
	if (!(t = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
		return (0);
	if (!(get_map(t, argv)))
		return (0);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WINX, WINY, "tmfene");
	mlx_hook(t->win, 17, 0L, ft_close, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	wolf3d_init(t);
	ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
