#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
//# include <x11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include "so_long.h"
# include "./libft/libft.h"

# define WIDTH		400
# define HEIGHT		400

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

/* typedef struct s_vector {
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
 */

typedef struct s_flood {
	char	**flood_map;
	int		x;
	int		y;
	int		px;
	int		py;
}	t_flood;

typedef struct s_data {
	void		*mlx_ptr; //MLX pointer
	void		*win_ptr; //MLX window pointer
	//void		*img;
	void		*floor; //img ptrs:
	void		*wall;
	void		*player;
	void		*exit;
	void		*coins;

	char		**map;
	char		**cpy;

	//int			height;
	//int			width;
	int			fd;
	int			linelen;
	int			maplen;
	int			vlen;
	int			hlen;
	int			c_count;
	int			p_count;
	int			e_count;
	int			shell_count;
	int			px_pos;
	int			py_pos;
	int			px_cpy;
	int			py_cpy;
	int			x;
	int			y;
	int			i;
	int			j;
	int			x_pos1;
	int			y_pos1;
	int			x_pos2;
	int			y_pos2;
}	t_data;

void	error_handler(char *message);
void	free_and_destroy(t_data *data);
int		map_copy(t_data *game);
void	check_map(t_data *game);
int		check_open(char *file);
//void	read_map(t_data *game);
char	**read_map(int fd);
void	p_surrounded(t_data *game);
void	master_check(char *argv1, t_data *data);
int		check_linelength(char **map);
void	check_if_rectangle(char **map, t_data *data);
void	check_pe(t_data *game, char **map);
void	check_collectible(t_data *game, char **map);
void	check_walls(char **map, t_data *data);
void    img_into_struct(t_data *game);
void	img_into_win(t_data *game);
void	img_into_win2(t_data *game);
void	destroy_and_put(t_data *game, int height, int width);
int		movement(int keypressed, t_data *game);
int		valid_move(t_data *game, int x_pos, int y_pos);
int		up_down(t_data *game, int keysym);
int		left_right(t_data *game, int keysym);
void	flood_map(t_data *game);

#endif