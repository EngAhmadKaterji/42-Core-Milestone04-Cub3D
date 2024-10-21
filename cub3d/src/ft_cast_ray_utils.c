/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:35:11 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:58:41 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_wall_slice(t_data *data, t_ray_cast *ray, int x)
{
	int	y;
	int	color;
	int	tex_y;
	int	d;

	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		d = (y * 256 - WIN_HEIGHT * 128 + ray->lineheight * 128);
		tex_y = ((d * ray->texture.height) / ray->lineheight) / 256;
		if (tex_y >= ray->texture.height)
			tex_y = ray->texture.height - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = *(unsigned int *)(ray->texture.addr + (tex_y
					* ray->texture.line_len + ray->tex_x
					* (ray->texture.bpp / 8)));
		my_mlx_pixel_put(&data->img, x, y, color);
	}
}

void	cast_rays(t_data *data)
{
	t_ray_cast	ray;
	int			x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		initialize_ray(data, &ray, x);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_wall_distance_and_height(data, &ray);
		get_texture_and_wall_hit(data, &ray);
		render_wall_slice(data, &ray, x);
	}
}
