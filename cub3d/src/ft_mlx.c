/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:43:55 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:24:31 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned	int	rgb_to_color(char *rgb[3])
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return ((r << 16) | (g << 8) | b);
}

void	put_floor_and_ceiling(t_data *data)
{
	int	y;
	int	x;

	y = WIN_HEIGHT / 2 - 1;
	if (data->floor_color == 0 || data->ceiling_color == 0)
	{
		printf("Error: Colors are not set\n");
		return ;
	}
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, rgb_to_color(data->floor_color));
			my_mlx_pixel_put(&data->img, x,
				WIN_HEIGHT - y - 1, rgb_to_color(data->ceiling_color));
		}
	}
}

int	ft_check_tiles(t_data *data)
{
	t_texture	*cur;
	int			i;

	i = 0;
	cur = data->texture_list;
	while (cur)
	{
		if (!ft_strcmp(cur->key, "FP"))
			i++;
		else if (!ft_strcmp(cur->key, "CP"))
			i++;
		cur = cur->next;
	}
	if (i == 2)
		return (1);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit_free(data);
	else if (keycode == LEFTROTATE)
		rotate_player(data, -ROTATION_SPEED);
	else if (keycode == RIGHTROTATE)
		rotate_player(data, ROTATION_SPEED);
	else
		move_player(data, keycode);
	mlx_clear_window(data->mlx, data->win);
	if (ft_check_tiles(data))
		cast_floor_and_ceiling(data);
	else
		put_floor_and_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	if (data)
		ft_exit_free(data);
	return (0);
}
