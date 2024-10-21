/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_floor_ceiling_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:38:37 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:38:57 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_floor_cast(t_data *data, t_floor_cast *floor_cast)
{
	floor_cast->ray_dir_x0 = data->dir_x - data->plane_x;
	floor_cast->ray_dir_y0 = data->dir_y - data->plane_y;
	floor_cast->ray_dir_x1 = data->dir_x + data->plane_x;
	floor_cast->ray_dir_y1 = data->dir_y + data->plane_y;
	floor_cast->pos_z = 0.5 * WIN_HEIGHT;
}
