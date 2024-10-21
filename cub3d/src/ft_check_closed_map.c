/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_closed_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:44 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/15 15:23:32 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_over_boundaries(int x, int y, t_data *data)
{
	char	type;

	if (x < 0 || x > data->map_width + 1 || y < 0 || y > data->map_height + 1)
		return ;
	type = data->utils.cpy_map[y][x];
	if (type == '1')
		return ;
	else if (type == 'a')
		data->utils.cpy_map[y][x] = '1';
	else if (type == '0')
	{
		ft_putstr_fd("Cub3d: Error Invalid Map Paths are Open\n", 2);
		ft_exit_free(data);
	}
	ft_move_over_boundaries(x + 1, y, data);
	ft_move_over_boundaries(x - 1, y, data);
	ft_move_over_boundaries(x, y + 1, data);
	ft_move_over_boundaries(x, y - 1, data);
}

void	ft_valid_map_boundaries(t_data *data)
{
	ft_move_over_boundaries(0, 0, data);
}

void	ft_calloc_array(t_data *data, int len_x, int len_y)
{
	int	i;

	i = -1;
	data->utils.cpy_map = ft_calloc(sizeof(char *), len_y);
	if (!data->utils.cpy_map)
		ft_exit_free(data);
	while (++i < len_y)
	{
		data->utils.cpy_map[i] = ft_calloc(sizeof(char), len_x);
		if (!data->utils.cpy_map[i])
			ft_exit_free(data);
	}
}

void	ft_fill_array(t_data *data, int i, int j)
{
	int	len_x;
	int	len_y;

	len_x = ft_max_x(data) + 2;
	len_y = data->map_height + 2;
	if (i == 0 || i == len_x - 1 || j == 0 || j == len_y - 1)
		data->utils.cpy_map[j][i] = 'a';
	else if (i - 1 < ft_strlen(data->map[j - 1])
		&& data->map[j - 1][i - 1] == ' ')
		data->utils.cpy_map[j][i] = 'a';
	else if (i - 1 < ft_strlen(data->map[j - 1]) && data->map[j - 1][i - 1])
		data->utils.cpy_map[j][i] = data->map[j - 1][i - 1];
	else
		data->utils.cpy_map[j][i] = 'a';
}

void	ft_cpy_game(t_data *data)
{
	int	len_x;
	int	len_y;
	int	i;
	int	j;

	data->map_width = ft_max_x(data);
	len_x = ft_max_x(data) + 2;
	len_y = data->map_height + 2;
	ft_calloc_array(data, len_x, len_y);
	j = -1;
	while (++j < len_y)
	{
		i = -1;
		while (++i < len_x)
		{
			ft_fill_array(data, i, j);
		}
	}
}
