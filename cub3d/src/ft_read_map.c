/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:46:54 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:47:34 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line(t_data *data, int flag, int *flag2)
{
	int	i;

	i = -1;
	if (data->utils.line == NULL)
		return (0);
	if (flag == 1 && data->utils.line[0] == 10)
	{
		*flag2 = 1;
		ft_putstr_fd("Error invalid map\n", 2);
		return (0);
	}
	else if (flag == 0 && data->utils.line)
	{
		while (data->utils.line[++i])
		{
			if (!ft_is_char(data->utils.line[i], "NSWECF"))
				return (1);
			else if (data->utils.line[i] == '1')
				return (0);
		}
	}
	return (1);
}

void	ft_check_textures(t_data *data, int fd)
{
	t_texture	*cur;

	cur = data->texture_list;
	while (cur)
	{
		if (cur->key == NULL)
		{
			while (data->utils.line)
			{
				free(data->utils.line);
				data->utils.line = get_next_line(fd);
			}
			close (fd);
			ft_putstr_fd("Cub3D: Error Missing Textures\n", 2);
			ft_exit_free(data);
		}
		cur = cur->next;
	}
}

void	ft_get_texture(t_data *data, int fd)
{
	t_texture	*new_texture;
	int			flag;

	flag = 0;
	data->utils.line = get_next_line(fd);
	while (data->utils.line)
	{
		if (!ft_check_line(data, 0, &flag))
			break ;
		if (data->utils.line[0] != 10)
		{
			new_texture = malloc(sizeof(t_texture));
			ft_new_txtr(data->utils.line, new_texture);
			ft_add_back_txtr(&data->texture_list, new_texture);
		}
		free(data->utils.line);
		data->utils.line = NULL;
		data->utils.line = get_next_line(fd);
	}
	ft_check_textures(data, fd);
}

void	ft_get_map(t_data *data, int fd)
{
	int	flag;

	flag = 0;
	if (!data->utils.line)
	{
		ft_putstr_fd("Cub3d: Error No Map found\n", 2);
		ft_exit_free(data);
	}
	while (data->utils.line)
	{
		ft_check_line(data, 1, &flag);
		data->utils.file = ft_strjoin_modified(data->utils.file,
				data->utils.line);
		free(data->utils.line);
		data->utils.line = NULL;
		if (!data->utils.file)
			ft_exit_free(data);
		data->utils.line = get_next_line(fd);
		data->map_height++;
	}
	if (flag)
		return (ft_putstr_fd("Cub3D: Error Invalid Map\n", 2),
			close(fd), ft_exit_free(data));
}

void	ft_read_map(t_data *data)
{
	int	fd;

	data->utils.line = "";
	fd = open(data->utils.filename, O_RDONLY);
	if (fd == -1)
		ft_error_openfile();
	ft_get_texture(data, fd);
	ft_get_map(data, fd);
	close (fd);
	data->map = ft_split(data->utils.file, '\n');
	ft_cpy_game(data);
	if (!data->map || !data->utils.cpy_map)
		ft_exit_free(data);
	free(data->utils.file);
	data->utils.file = NULL;
}
