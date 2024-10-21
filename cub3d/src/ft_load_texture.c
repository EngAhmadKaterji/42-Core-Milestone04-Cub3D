/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:40:56 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:55:30 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_texturefiles(t_data *data)
{
	char		**textruefiles;
	t_texture	*cur_texture;

	cur_texture = data->texture_list;
	textruefiles = (char **)malloc(sizeof(char *) * 7);
	textruefiles[4] = NULL;
	textruefiles[5] = NULL;
	while (cur_texture)
	{
		if (!ft_strcmp(cur_texture->key, "NO"))
			textruefiles[0] = ft_strdup(cur_texture->value);
		if (!ft_strcmp(cur_texture->key, "SO"))
			textruefiles[1] = ft_strdup(cur_texture->value);
		if (!ft_strcmp(cur_texture->key, "WE"))
			textruefiles[2] = ft_strdup(cur_texture->value);
		if (!ft_strcmp(cur_texture->key, "EA"))
			textruefiles[3] = ft_strdup(cur_texture->value);
		if (!ft_strcmp(cur_texture->key, "CP"))
			textruefiles[4] = ft_strdup(cur_texture->value);
		if (!ft_strcmp(cur_texture->key, "FP"))
			textruefiles[5] = ft_strdup(cur_texture->value);
		cur_texture = cur_texture->next;
	}
	textruefiles[6] = NULL;
	data->textures = textruefiles;
}

int	load_texture(void *mlx, t_img *texture, char *file)
{
	texture->img = mlx_xpm_file_to_image(mlx,
			file, &texture->width, &texture->height);
	if (!texture->img)
		return (printf("Error: Failed to load texture %s\n", file), 1);
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->line_len, &texture->endian);
	return (0);
}

int	load_textures(t_data *data, char **texturefiles)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (load_texture(data->mlx, &data->wall_textures[i], texturefiles[i]))
			return (1);
	}
	if (texturefiles[i] != NULL)
	{
		if (load_texture(data->mlx, &data->ceiling_texture, texturefiles[i++]))
			return (1);
		if (load_texture(data->mlx, &data->floor_texture, texturefiles[i]))
			return (1);
	}
	return (0);
}

int	init_textures(t_data *data)
{
	data->textures = NULL;
	ft_get_texturefiles(data);
	if (load_textures(data, data->textures))
		return (1);
	return (0);
}
