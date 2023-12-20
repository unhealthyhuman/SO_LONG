#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
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
}	t_data;

void	error_handler(char *message);
char	**read_map(int fd);

#endif