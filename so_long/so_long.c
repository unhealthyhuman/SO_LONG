/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:11:55 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/03 22:21:08 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include <stdlib.h>

void	destroy_img(t_data *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlx_ptr, data->floor);
	if (data->wall)
		mlx_destroy_image(data->mlx_ptr, data->wall);
	if (data->player)
		mlx_destroy_image(data->mlx_ptr, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx_ptr, data->exit);
	if (data->coins)
		mlx_destroy_image(data->mlx_ptr, data->coins);
}

void	flood(t_data *f, int py, int px)
{
	if (px < 0 || px >= f->x || py < 0 || py >= f->y)
		return ;
	if (f->cpy[py][px] == '1')
		return ;
	if (f->cpy[py][px] == 'V')
		return ;
	f->cpy[py][px] = 'V';
	flood(f, py + 1, px);
	flood(f, py - 1, px);
	flood(f, py, px + 1);
	flood(f, py, px - 1);
}

void	flood_map(t_data *game)
{
	int		j;

	j = map_copy(game);
	if (!j)
		error_handler("error during copying", *game);
	game->px_cpy = game->px_pos;
	game->py_cpy = game->py_pos;
	game->x = game->linelen;
	game->y = game->maplen;
	flood(game, game->py_cpy, game->px_cpy);
	check_map(game);
}

//f_data.flood_map = game->map; //cant copy like that
int	main(int argc, char **argv)
{
	t_data	game;

	ft_bzero(&game, sizeof(game));
	game.fd = -1;
	if (argc == 2)
	{
		master_check(argv[1], &game);
		if (((game.linelen * 50) > 1920) || ((game.maplen * 50) > 999))
			error_handler("invalid map: map too big", game);
		game.mlx_ptr = mlx_init();
		if (!game.mlx_ptr)
			return (free_and_destroy(&game), 1);
		game.win_ptr = mlx_new_window(game.mlx_ptr,
				(game.linelen * 50), (game.maplen * 50), "so_long");
		if (!(game.win_ptr))
			return (free_and_destroy(&game), 1);
		img_into_struct(&game);
		img_into_win(&game);
		mlx_key_hook(game.win_ptr, &movement, &game);
		mlx_hook(game.win_ptr, 17, 0, (void *)exit, &game);
		mlx_loop(game.mlx_ptr);
		free_and_destroy(&game);
	}
	return (0);
}

//usa el main para check si el argc es correcto y has la ventana en otra funcion
//lee el mapa, puedes usar get_next_line, lees todo el mapa y despues usas split
// y lo divivides en cada \n y tienes un str array con el 
//que ahora puedes iterar
//puedes hacer un ss de las imagenes que quieres render pq los ss son
//automaticamente png
//has una funcion que frees and destroys the window para usar en caso de failure
//tienes que volver a hacer el mapa cada vez que el jugador se mueve
//
	/* for (size_t i = 0; filip[i]; i++)
	{
		for (size_t j = 0; filip[i][j]; j++)
			printf("%c", filip[i][j]);
		printf("\n");
	} */

	/* int i = 0;
	while (filip[i] != NULL)
	{
		ft_printf("%s\n", filip[i]);
		i++;
	} */