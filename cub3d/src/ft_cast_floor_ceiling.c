/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:37:06 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:38:52 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_floor_step(t_floor_cast *floor_cast, int y)
{
	int	p;

	p = y - WIN_HEIGHT / 2;
	floor_cast->row_distance = floor_cast->pos_z / p;
	floor_cast->floor_step_x = floor_cast->row_distance
		* (floor_cast->ray_dir_x1 - floor_cast->ray_dir_x0) / WIN_WIDTH;
	floor_cast->floor_step_y = floor_cast->row_distance
		* (floor_cast->ray_dir_y1 - floor_cast->ray_dir_y0) / WIN_WIDTH;
}

void	initialize_floor_position(t_data *data, t_floor_cast *floor_cast)
{
	floor_cast->floor_x = data->pos_x
		+ floor_cast->row_distance * floor_cast->ray_dir_x0;
	floor_cast->floor_y = data->pos_y
		+ floor_cast->row_distance * floor_cast->ray_dir_y0;
}

void	get_floor_ceiling_colors(t_data *data, t_floor_cast *floor_cast)
{
	floor_cast->tex_x = abs((int)(floor_cast->floor_x
				* data->floor_texture.width) % data->floor_texture.width);
	floor_cast->tex_y = abs((int)(floor_cast->floor_y
				* data->floor_texture.height) % data->floor_texture.height);
	floor_cast->floor_color = *(unsigned int *)(data->floor_texture.addr
			+ (floor_cast->tex_y * data->floor_texture.line_len
				+ floor_cast->tex_x * (data->floor_texture.bpp / 8)));
	floor_cast->ceiling_tex_x = floor_cast->tex_x;
	floor_cast->ceiling_tex_y = data->ceiling_texture.height
		- floor_cast->tex_y - 1;
	floor_cast->ceiling_color = *(unsigned int *)(data->ceiling_texture.addr
			+ (floor_cast->ceiling_tex_y * data->ceiling_texture.line_len
				+ floor_cast->ceiling_tex_x * (data->ceiling_texture.bpp / 8)));
}

void	render_floor_and_ceiling(t_data *data,
		t_floor_cast *floor_cast, int x, int y)
{
	my_mlx_pixel_put(&data->img, x, y, floor_cast->floor_color);
	my_mlx_pixel_put(&data->img, x,
		WIN_HEIGHT - y - 1, floor_cast->ceiling_color);
}

void	cast_floor_and_ceiling(t_data *data)
{
	t_floor_cast	floor_cast;
	int				y;
	int				x;

	y = WIN_HEIGHT / 2 - 1;
	if (!data->floor_texture.addr || !data->ceiling_texture.addr)
	{
		printf("Error: Texture address is NULL\n");
		return ;
	}
	initialize_floor_cast(data, &floor_cast);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		calculate_floor_step(&floor_cast, y);
		initialize_floor_position(data, &floor_cast);
		while (++x < WIN_WIDTH)
		{
			get_floor_ceiling_colors(data, &floor_cast);
			render_floor_and_ceiling(data, &floor_cast, x, y);
			floor_cast.floor_x += floor_cast.floor_step_x;
			floor_cast.floor_y += floor_cast.floor_step_y;
		}
	}
}
