#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>
# include "so_long.h"
# include "./libft/libft.h"

#define WIDTH		400;
#define HEIGHT		400;

typedef struct s_data {
	void	*mlx_ptr; //MLX pointer
	void	*win_ptr; //MLX window pointer
	void	*textures[5]; //MLX image pointers
	//t_map	*map; //Map pointer (contains map details)
	void	*img;
	int		height;
	int		width;
	int		fd;
	int		linelen;
	int		maplen;
	int		vlen;
	int		hlen;
	int		i;
	int		j;
}	t_data;

void	error_handler(char *message);
int		check_open(char *file);
char	**read_map(int fd);
void	master_check(char **map, t_data *data);
int		check_linelength(char **map);
void	check_if_rectangle(char **map, t_data *data);
void	check_pe(char **map);
void	check_collectible(char **map);
void	check_walls(char **map, t_data *data);

#endif