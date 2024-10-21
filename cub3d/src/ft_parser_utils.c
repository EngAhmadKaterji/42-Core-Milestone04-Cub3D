/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:28:41 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 12:09:13 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_max_x(t_data *data)
{
	int	max;
	int	i;
	int	j;

	i = -1;
	max = 0;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (max < j)
			max = j;
	}
	return (max);
}

void	ft_scan_player(t_data *data, int y, int x)
{
	data->start_point++;
	data->pos_x = (double)x;
	data->pos_y = (double)y;
}
