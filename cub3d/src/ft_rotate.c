/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:42:43 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:43:01 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_data *data, double angle)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = data->dir_x;
	oldplane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	data->dir_y = olddir_x * sin(angle) + data->dir_y * cos(angle);
	data->plane_x = data->plane_x * cos(angle) - data->plane_y * sin(angle);
	data->plane_y = oldplane_x * sin(angle) + data->plane_y * cos(angle);
}
