/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:34:34 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:35:57 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_ray(t_data *data, t_ray_cast *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = data->dir_x + data->plane_x * ray->camera_x;
	ray->ray_dir_y = data->dir_y + data->plane_y * ray->camera_x;
	ray->map_x = (int)data->pos_x;
	ray->map_y = (int)data->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	calculate_step_and_side_dist(t_data *data, t_ray_cast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->pos_y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_data *data, t_ray_cast *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_y][ray->map_x] > '0')
			ray->hit = 1;
	}
}

void	calculate_wall_distance_and_height(t_data *data, t_ray_cast *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - data->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perpwalldist = (ray->map_y - data->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->lineheight = (int)(WIN_HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray->drawend >= WIN_HEIGHT)
		ray->drawend = WIN_HEIGHT - 1;
}

void	get_texture_and_wall_hit(t_data *data, t_ray_cast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->texture = data->wall_textures[0];
		else
			ray->texture = data->wall_textures[1];
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->texture = data->wall_textures[2];
		else
			ray->texture = data->wall_textures[3];
	}
	if (ray->side == 0)
		ray->wall_x = data->pos_y + ray->perpwalldist * ray->ray_dir_y;
	else
		ray->wall_x = data->pos_x + ray->perpwalldist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(ray->texture.width));
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = ray->texture.width - ray->tex_x - 1;
}
