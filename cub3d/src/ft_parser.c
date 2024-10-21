/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:42:24 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:59:10 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_valid_params(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	data->start_point = 0;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
			|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				ft_scan_player(data, y, x);
			else if (data->map[y][x] == '0'
				|| data->map[y][x] == '1' || data->map[y][x] == ' ')
				;
			else if (data->map[y][x] == '\0')
				break ;
			else
				ft_error_map_elements(data);
		}
	}
	if (data->start_point != 1)
		ft_error_map_elements(data);
}

int	ft_check_valid_color(char *str)
{
	char	**colors;
	int		i;
	int		color_value;

	color_value = 0;
	i = -1;
	colors = ft_split(str, ',');
	while (colors[++i])
	{
		color_value = ft_atoi(colors[i]);
		if (color_value < 0 || color_value > 255)
			return (0);
	}
	ft_free_array(colors);
	return (1);
}

void	ft_check_color(t_data *data)
{
	t_texture	*cur_txtr;

	cur_txtr = data->texture_list;
	while (!ft_strcmp(cur_txtr->key, "F") || !ft_strcmp(cur_txtr->key, "C"))
		cur_txtr = cur_txtr->next;
	while (cur_txtr)
	{
		if (!ft_check_valid_color(cur_txtr->value))
		{
			printf("error:\n");
			ft_exit_free(data);
		}
		if (!ft_strcmp(cur_txtr->key, "F"))
			data->floor_color = ft_split(cur_txtr->value, ',');
		else if (!ft_strcmp(cur_txtr->key, "C"))
			data->ceiling_color = ft_split(cur_txtr->value, ',');
		cur_txtr = cur_txtr->next;
	}
}

void	ft_check_filename(t_data *data)
{
	size_t	len;
	char	*filename;

	filename = data->utils.filename;
	len = ft_strlen(filename);
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u'
		|| filename[len - 3] != 'c' || filename[len - 4] != '.'
		|| !ft_strnstr(filename, ".cub", len))
		ft_error_filename();
}

void	ft_parser(t_data *data)
{
	ft_check_filename(data);
	ft_read_map(data);
	ft_check_color(data);
	ft_valid_map_boundaries(data);
	ft_valid_params(data);
}
