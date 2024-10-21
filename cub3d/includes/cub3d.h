/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:08:04 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:51:03 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <mlx.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MAP_WIDTH 8
# define MAP_HEIGHT 6
# define PLAYER_X 3.5
# define PLAYER_Y 2.5
# define FOV 1.0
# define ROTATION_SPEED 0.05
# define MOVE_SPEED 0.1
# define TILE_SIZE 64
# define UP   119   
# define DOWN    115
# define LEFT 97
# define RIGHT 100
# define LEFTROTATE    65361
# define RIGHTROTATE   65363
# define ESC     65307

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray_cast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		d;
	t_img	texture;
}	t_ray_cast;

typedef struct s_floor_cast
{
	double	ray_dir_x0;
	double	ray_dir_y0;
	double	ray_dir_x1;
	double	ray_dir_y1;
	double	pos_z;
	double	row_distance;
	double	floor_step_x;
	double	floor_step_y;
	double	floor_x;
	double	floor_y;
	int		tex_x;
	int		tex_y;
	int		ceiling_tex_x;
	int		ceiling_tex_y;
	int		floor_color;
	int		ceiling_color;
}	t_floor_cast;

typedef struct s_utils
{
	char	*line;
	char	*file;
	char	*filename;
	char	**cpy_map;
}	t_utils;

typedef struct s_texture
{
	char				*key;
	char				*value;
	struct s_texture	*next;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		wall_textures[4];
	char		**map;
	char		**textures;
	int			start_point;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		**floor_color;
	char		**ceiling_color;
	int			map_width;
	int			map_height;
	t_img		ceiling_texture;
	t_img		floor_texture;
	t_texture	*texture_list;
	t_utils		utils;
}	t_data;

void	ft_init_params(t_data *data, char *filename);
void	ft_parser(t_data *data);
void	ft_scan_player(t_data *data, int y, int x);
int		ft_max_x(t_data *data);
void	ft_read_map(t_data *data);
void	ft_add_back_txtr(t_texture **txtr_list, t_texture *new_txtr);
void	ft_new_txtr(char *str, t_texture *new_txtr);
void	ft_clear_txtr(t_texture **txtr_list);
void	ft_cpy_game(t_data *data);
void	ft_fill_array(t_data *data, int i, int j);
void	ft_calloc_array(t_data *data, int len_x, int len_y);
void	ft_valid_map_boundaries(t_data *data);
void	ft_exit_free(t_data *data);
void	ft_error_map_elements(t_data *data);
void	ft_error_filename(void);
void	ft_error_openfile(void);
void	rotate_player(t_data *data, double angle);
void	move_player(t_data *data, int keycode);
int		close_window(t_data *data);
int		key_press(int keycode, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		init_textures(t_data *data);
void	initialize_ray(t_data *data, t_ray_cast *ray, int x);
void	calculate_step_and_side_dist(t_data *data, t_ray_cast *ray);
void	perform_dda(t_data *data, t_ray_cast *ray);
void	calculate_wall_distance_and_height(t_data *data, t_ray_cast *ray);
void	get_texture_and_wall_hit(t_data *data, t_ray_cast *ray);
void	initialize_floor_cast(t_data *data, t_floor_cast *floor_cast);
void	cast_floor_and_ceiling(t_data *data);
void	cast_rays(t_data *data);
void	put_floor_and_ceiling(t_data *data);
int		ft_check_tiles(t_data *data);
#endif