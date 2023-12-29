#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <stdlib.h>
//# include <X11/X.h>
//# include <x11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include "so_long.h"
# include "./libft/libft.h"

# define WIDTH		400;
# define HEIGHT		400;

# define ESC XK_Escape;
# define LEFT XK_Left;
# define UP XK_Up;
# define RIGHT XK_Right;
# define DOWN XK_Down;

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef	struct s_mapdata {
	t_vector	size;
	t_vector	point;
	int			m_player; // 1 == TRUE, 0 == FALSE
	int			m_exit; // 1 == TRUE, 0 == FALSE
	int			m_collectable; // 1 == TRUE, 0 == FALSE
}	t_mapdata;

typedef struct s_data {
	void		*mlx_ptr; //MLX pointer
	void		*win_ptr; //MLX window pointer
	t_vector	win_size;
	void		*textures[5]; //MLX image pointers
	//t_map	*map; //Map pointer (contains map details)
	void		*img;
	void		*floor;
	void		*wall;
	void		*player;
	void		*exit;
	void		*coins;
	t_vector	img_size;
	char		**map;
	int			height;
	int			width;
	int			fd;
	int			linelen;
	int			maplen;
	int			vlen;
	int			hlen;
	int			c_count;
	int			p_count;
	int			e_count;
	int			i;
	int			j;
}	t_data;

void	error_handler(char *message);
int		check_open(char *file);
char	**read_map(int fd);
void	master_check(char *argv1, t_data *data);
int		check_linelength(char **map);
void	check_if_rectangle(char **map, t_data *data);
void	check_pe(t_data *game, char **map);
void	check_collectible(t_data *game, char **map);
void	check_walls(char **map, t_data *data);

#endif