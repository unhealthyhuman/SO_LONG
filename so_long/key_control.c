/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:39 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/01 19:41:48 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_move(t_data *game, int x_pos, int y_pos)
{
	if (game->map[y_pos][x_pos] == 'E')
	{
		if (game->c_count != '0')
			return (0);
		ft_printf("Winner Winner Chicken Dinner!");
		free_and_destroy(game);
	}
	else if (game->map[y_pos][x_pos] == 'C')
	{
		game->map[y_pos][x_pos] = 'P';
		game->px_pos = x_pos;
		game->player = y_pos;
		game->c_count--;
	}
	else if (game->map[y_pos][x_pos] == '0')
	{
		game->map[y_pos][x_pos] = 'P';
		game->px_pos = x_pos;
		game->py_pos = y_pos;
	}
	return (1);
}

int	movement(t_data *game, int keypressed)
{
	if (keypressed == ESC)
		free_and_destroy(game);
	
	return (1);
}