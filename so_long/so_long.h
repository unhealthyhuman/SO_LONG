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

# define WIDTH		400;
# define HEIGHT		400;

# define ESC 65307;
# define LEFT 65361;
# define UP 65362;
# define RIGHT 65363;
# define DOWN 65364;

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
typedef struct s_data {
	void		*mlx_ptr; //MLX pointer
	void		*win_ptr; //MLX window pointer
	//void		*img;
	void		*floor; //img ptrs:
	void		*wall;
	void		*player;
	void		*exit;
	void		*coins;

	//t_vector	img_size;
	//t_vector	win_size;
	//t_map	*map; //Map pointer (contains map details)

	char		**map;

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
	int			px_pos;
	int			py_pos;
	int			i;
	int			j;
}	t_data;

void	error_handler(char *message);
void	free_and_destroy(t_data *data);
int		check_open(char *file);
//void	read_map(t_data *game);
char	**read_map(int fd);
void	master_check(char *argv1, t_data *data);
int		check_linelength(char **map);
void	check_if_rectangle(char **map, t_data *data);
void	check_pe(t_data *game, char **map);
void	check_collectible(t_data *game, char **map);
void	check_walls(char **map, t_data *data);
void    img_into_struct(t_data *game);
void	img_into_win(t_data *game);
void	place_collectable(t_data *game, int height, int width);

#endif