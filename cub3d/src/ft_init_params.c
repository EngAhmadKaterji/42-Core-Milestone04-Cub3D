/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:36:30 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 12:54:11 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_params_utils(t_data *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->dir_x = 1.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
	data->start_point = 0;
}

void	ft_init_params(t_data *data, char *filename)
{
	int	i;

	i = -1;
	ft_init_params_utils(data);
	while (++i < 4)
		data->wall_textures[i].img = NULL;
	data->utils.cpy_map = NULL;
	data->utils.file = NULL;
	data->utils.filename = filename;
	data->utils.line = NULL;
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	data->texture_list = NULL;
	data->ceiling_texture.img = NULL;
	data->floor_texture.img = NULL;
	data->img.img = NULL;
	data->textures = NULL;
	data->map = NULL;
	data->utils.cpy_map = NULL;
	data->win = NULL;
	data->mlx = NULL;
	data->map_width = 0;
	data->map_height = 0;
}
