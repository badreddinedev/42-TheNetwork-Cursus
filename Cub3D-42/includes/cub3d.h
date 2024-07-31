/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:10:00 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 19:56:21 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
# define MAP_H 1080
# define MAP_W 1920

# define M_PI 3.141592
# define M_PI_2 1.570796

//scale_factor
# define SCALE_FACTOR 0.4

// Keys
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_ESC 53

// view
# define VIEW_RIGHT 124
# define VIEW_LEFT 123

# define FOV 60
# define WALL_STRIP_WIDTH 1

# define NO 4.72
# define SO 1.57
# define WE 3.14
# define EA 0

/* ---------------------------------------------------------------------------*
							LIBRARIES
 --------------------------------------------------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
/* ---------------------------------------------------------------------------*
							STRUCT
 --------------------------------------------------------------------------- */
typedef struct s_direction
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_direction;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	float	x;
	float	y;
	float	raduis;
	float	turn_direction;
	float	walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	float	look;
	int		step;
}	t_player;

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image
{
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*data;
	char	*addr;
	void	*img;
}	t_image;

typedef struct s_img_data
{
	t_image		img_north;
	t_image		img_south;
	t_image		img_east;
	t_image		img_west;
}	t_img_data;

typedef struct s_cub_pars
{
	int			fd;
	char		*file_name;
	char		**map2d;
	char		*map;
	t_direction	directions;
	t_rgb		floor;
	t_rgb		celling;
	t_player	player;
	t_map		map_init;
}	t_cub_pars;

typedef struct s_line
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
}	t_line;

typedef struct s_minimap
{
	int		x_pos;
	int		y_pos;
	int		xp;
	int		yp;
	int		i;
	int		j;
}				t_minimap;

typedef struct s_wall
{
	float			ray_distance;
	float			distance_pjplane;
	float			wall_strip_height;
	float			walltp;
	float			wallbop;
	int				distance_fromtop;
}	t_wall;

typedef struct s_mlx
{
	int			x_offset;
	void		*mlx_ptr;
	void		*mlx_win;
	int			is_vertical;
	int			is_horizontal;
	double		rayangle;
	double		ray_x;
	double		ray_y;
	int			tex_x;
	int			tex_y;
	double		distance;
	t_image		img;
	t_image		*no_texture;
	t_image		*so_texture;
	t_image		*we_texture;
	t_image		*ea_texture;
	t_wall		wall;
	t_img_data	imgs;
	t_data		data;
	t_cub_pars	cub3d;
	t_minimap	minimap;
}	t_mlx;

/* ---------------------------------------------------------------------------*
							FUNCTIONS UTILS
 --------------------------------------------------------------------------- */
char			*ft_getrest(char *rest, char *line);
int				ft_strlen_g(char *str);
char			*ft_strdup_g(char *rest);
char			*ft_strjoin_g(char *buffer, char *rest);
int				ft_strchr_g(char *buffer);
char			*read_file(int fd, char *rest);
char			*get_next_line(int fd);
char			*ft_getline(char *rest);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl_free(char *s, int fd, char *str);
char			**ft_split(char const *s, char c);
/* ---------------------------------------------------------------------------*
							FUNCTIONS PARSING
 --------------------------------------------------------------------------- */
void			ft_initialize(t_cub_pars *cub_pars);
void			clean_map(char **file_split);
void			parsing(t_cub_pars *cub, char **av);
int				check_file_extention(char *file_name);
int				is_cardinal_direction(char *line);
void			parse(t_cub_pars *cub);
int				ft_file_len(char **file_splite);
void			save_cardinal_direction(t_cub_pars *cub, char *line);
void			save_rgb(t_cub_pars *cub, char *line);
int				is_map(char *line);
int				is_graphics(t_cub_pars cub);
void			check_newline(char *map);
void			check_map(t_cub_pars *cub);
void			is_surrounded(t_cub_pars *cub);
void			one_player(t_cub_pars *cub);
void			player_surrounded(t_cub_pars *cub);
void			*ft_calloc_char(size_t count, size_t size, char c);
void			rect_map(t_cub_pars *cub);
void			get_p_position(t_cub_pars *cub);
/* ---------------------------------------------------------------------------*
							FUNCTIONS RYCASTING
 --------------------------------------------------------------------------- */
void			player_init(t_cub_pars *cub3d);
int				key_press(int key, t_mlx *mlx);
int				key_release(int key, t_mlx *mlx);
int				mouse(int x, int y, t_mlx *ml);
int				check_wall_2(t_mlx *mlx, float x, float y);
void			render(t_mlx *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				move_player(t_mlx *mlx);
int				close_window(t_mlx *mlx);
void			move_down_up(t_mlx *mlx);
void			move_left_right(t_mlx *mlx);
int				check_wall(t_mlx *mlx, float x, float y);
int				is_player(char c);
void			look_left_right(t_mlx *mlx);
void			cast_rays(t_mlx *mlx);
void			cast(double ray_angle, t_mlx *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
// +line
void			render3dwalls(t_mlx *mlx, int nb);
void			textures_init(t_mlx *mlx);
unsigned int	get_color(t_image *tex, int x, int y);
void			minimap_render(t_mlx *mlx);
void			getdirection(t_mlx *mlx);
double			get_x(t_mlx *mlx);
int				rgb_to_int(int red, int green, int blue);
void			cleanup(t_mlx *mlx);
#endif