/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:01:31 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/15 15:21:58 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_openfile(void)
{
	ft_putstr_fd("Cub3D : Error Failed Open File\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_map_elements(t_data *data)
{
	ft_putstr_fd("Cub3D: Error Failed Elements\n", 2);
	ft_exit_free(data);
	exit(EXIT_FAILURE);
}

void	ft_error_filename(void)
{
	ft_putstr_fd("Cub3D: Error Filename \n", 2);
	exit(EXIT_FAILURE);
}
