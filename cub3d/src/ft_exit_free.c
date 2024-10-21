/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:07:46 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/15 15:04:36 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_img *textures, void *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (textures[i].img)
		{
			mlx_destroy_image(mlx, textures[i].img);
			textures[i].img = NULL;
		}
	}
}

void	ft_free_images(t_data *data)
{
	free_textures(data->wall_textures, data->mlx);
	if (data->ceiling_texture.img)
	{
		mlx_destroy_image(data->mlx, data->ceiling_texture.img);
		data->ceiling_texture.img = NULL;
	}
	if (data->floor_texture.img)
	{
		mlx_destroy_image(data->mlx, data->floor_texture.img);
		data->floor_texture.img = NULL;
	}
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
}

void	ft_free_window(t_data *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	ft_exit_free(t_data *data)
{
	ft_free_images(data);
	if (data->textures)
		ft_free_array(data->textures);
	if (data->texture_list)
		ft_clear_txtr(&data->texture_list);
	if (data->ceiling_color)
		ft_free_array(data->ceiling_color);
	if (data->floor_color)
		ft_free_array(data->floor_color);
	if (data->map)
		ft_free_array_to_y(data->map, data->map_height);
	if (data->utils.cpy_map)
		ft_free_array_to_y(data->utils.cpy_map, data->map_height + 2);
	if (data->utils.file)
		free(data->utils.file);
	if (data->utils.line)
		free(data->utils.line);
	ft_free_window(data);
	exit(EXIT_FAILURE);
}
