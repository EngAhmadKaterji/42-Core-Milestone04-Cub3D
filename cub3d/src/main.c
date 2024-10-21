/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:10:35 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:52:39 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_execute(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (init_textures(data))
		return (ft_exit_free(data));
	if (ft_check_tiles(data))
		cast_floor_and_ceiling(data);
	else
		put_floor_and_ceiling(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_init_params(&data, argv[1]);
		ft_parser(&data);
		ft_execute(&data);
		ft_exit_free(&data);
		return (0);
	}
	ft_putstr_fd("cub3D: invalid number of arguments\n", 2);
	exit(EXIT_FAILURE);
}
