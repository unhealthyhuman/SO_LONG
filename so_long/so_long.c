#include "so_long.h"

int	check_if_valid(char *line_to_check)
{

}

typedef	struct s_map
{
	char
};


void	read_map(int fd) //tengo como input el mapa? **
{
	int	i;
	char	*line;
	char *last_line;

	i = 0;
	line = get_next_line(fd);
	i = 1;
	//ft_printf("%s\n", line);
	/* while (line != NULL)
	{
		if (i == 1 && check_if_valid(line) == )
			does smt;
		
		free(line);
		line = get_next_line(fd);
		last_line = malloc(sizeof(char)*ft_strlen(line));

	} */

}

int	destroyer(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main()
{
	t_data	data;
	void	*img;
	int width;
	int height;
	int	fd;

	img = NULL;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 2000, 2000, "so_long");
	if (!(data.win_ptr))
		return (free(data.mlx_ptr), 1);
	//mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroyer, &data);
	// mlx_key_hook(data.win_ptr, on_keypress, &data);
	usleep(100000);
	img = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/cube.xpm", &width, &height);
	ft_printf("widdth=%d, height=%d\n", width, height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 110, 110);
	// usleep(100000);
	fd = open("maps/simple_valid_map.ber", O_RDONLY);
	read_map(fd);
	mlx_loop(data.mlx_ptr);
	return (0);
}

//usa el main para check si el argc es correcto y has la ventana en otra funcion
//lee el mapa, puedes usar get_next_line, lees todo el mapa y despues usas split
// y lo divivides en cada \n y tienes un str array con el que ahora puedes iterar
//puedes hacer un ss de las imagenes que quieres render pq los ss son automaticamente
//png
//has una funcion que frees and destroys the window para usar en caso de failure
//tienes que volver a hacer el mapa cada vez que el jugador se mueve
//