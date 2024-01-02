/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:11:55 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/02 22:14:39 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

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
		return ;
	game->px_cpy = game->px_pos;
	game->py_cpy = game->py_pos;
	game->x = game->linelen;
	game->y = game->maplen;
	flood(game, game->py_cpy, game->px_cpy);
	check_map(game);
}

//f_data.flood_map = game->map; //cant copy like that
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_data	game;

	ft_bzero(&game, sizeof(game));
	if (argc == 2)
	{
		master_check(argv[1], &game);
		printf("linelen = %d\nmaplen = %d\n", game.linelen, game.maplen); //delete
		game.mlx_ptr = mlx_init();
		if (!game.mlx_ptr)
			return (1);
		game.win_ptr = mlx_new_window(game.mlx_ptr, (game.linelen * 50), (game.maplen * 50), "so_long");
		if (!(game.win_ptr))
			return (free(game.mlx_ptr), 1);
		img_into_struct(&game);
		img_into_win(&game);
		mlx_key_hook(game.win_ptr, &movement, &game);
		mlx_hook(game.win_ptr, 17, 0, (void *)exit, &game); //makes the exit possible by clicking the x
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}

//usa el main para check si el argc es correcto y has la ventana en otra funcion
//lee el mapa, puedes usar get_next_line, lees todo el mapa y despues usas split
// y lo divivides en cada \n y tienes un str array con el que ahora puedes iterar
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