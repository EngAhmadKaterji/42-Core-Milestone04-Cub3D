/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:33:16 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:25:01 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward_backward(t_data *data, int keycode)
{
	if (keycode == UP)
	{
		if (data->map[(int)(data->pos_y + data->dir_y * MOVE_SPEED)]
		[(int)data->pos_x] == '0')
			data->pos_y += data->dir_y * MOVE_SPEED;
		if (data->map[(int)data->pos_y]
			[(int)(data->pos_x + data->dir_x * MOVE_SPEED)] == '0')
			data->pos_x += data->dir_x * MOVE_SPEED;
	}
	if (keycode == DOWN)
	{
		if (data->map[(int)(data->pos_y - data->dir_y * MOVE_SPEED)]
		[(int)data->pos_x] == '0')
			data->pos_y -= data->dir_y * MOVE_SPEED;
		if (data->map[(int)data->pos_y]
			[(int)(data->pos_x - data->dir_x * MOVE_SPEED)] == '0')
			data->pos_x -= data->dir_x * MOVE_SPEED;
	}
}

void	strafe_left_right(t_data *data, int keycode)
{
	double	move_x;
	double	move_y;

	if (keycode == RIGHT)
	{
		move_x = -data->dir_y * MOVE_SPEED;
		move_y = data->dir_x * MOVE_SPEED;
		if (data->map[(int)(data->pos_y + move_y)]
		[(int)(data->pos_x + move_x)] == '0')
		{
			data->pos_y += move_y;
			data->pos_x += move_x;
		}
	}
	if (keycode == LEFT)
	{
		move_x = data->dir_y * MOVE_SPEED;
		move_y = -data->dir_x * MOVE_SPEED;
		if (data->map[(int)(data->pos_y + move_y)]
		[(int)(data->pos_x + move_x)] == '0')
		{
			data->pos_y += move_y;
			data->pos_x += move_x;
		}
	}
}

void	move_player(t_data *data, int keycode)
{
	if (keycode == UP || keycode == DOWN)
		move_forward_backward(data, keycode);
	else if (keycode == LEFT || keycode == RIGHT)
		strafe_left_right(data, keycode);
	// mlx_clear_window(data->mlx, data->win);
	// cast_floor_and_ceiling(data);
	// cast_rays(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
