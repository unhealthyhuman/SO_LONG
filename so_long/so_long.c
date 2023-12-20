#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	//argv 2 es el file que hay que leer
	//check if file is .ber
	//si si, abrelo y pasalo a read_map
	data.fd = open(argv[2], );
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 500, "so_long");
	if (!(data.win_ptr))
		return (free(data.mlx_ptr), 1);
	//mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	//mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroyer, &data);
	// mlx_key_hook(data.win_ptr, on_keypress, &data);
	usleep(100000);
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./textures/charizard.xpm", &data.width, &data.height);
	//ft_printf("width=%d, height=%d\n", data.width, data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	// usleep(100000);
	data.fd = open("maps/simple_valid_map.ber", O_RDONLY);
	//read_map(fd);
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