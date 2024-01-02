/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:39 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/02 17:13:53 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_move(t_data *game, int x_pos, int y_pos)
{
	//Position of P
	if (game->map[y_pos][x_pos] == 'E')
	{
		if (game->c_count != 0)
			return (0);
		ft_printf("Winner Winner Chicken Dinner!\n");
		free_and_destroy(game);
	}
	else if (game->map[y_pos][x_pos] == 'C')
	{
		game->map[y_pos][x_pos] = 'P';
		game->px_pos = x_pos;
		game->py_pos = y_pos;
		game->c_count--;
		game->shell_count++;
	}
	else if (game->map[y_pos][x_pos] == '0')
	{
		game->map[y_pos][x_pos] = 'P';
		game->px_pos = x_pos;
		game->py_pos = y_pos;
		game->shell_count++;
	}
	return (1);
}

int	up_down(t_data *game, int keysym)
{
	int	x_pos;
	int	y_pos;
	int	valid;

	x_pos = game->px_pos;
	y_pos = game->py_pos;
	if (keysym == UP)
	{
		y_pos--;
		if (game->map[y_pos][x_pos] == '1')
			return (0);
		valid = valid_move(game, x_pos, y_pos);
		if (!valid)
			return (0);
		game->map[y_pos + 1][x_pos] = '0';
		
	}
	else if (keysym == DOWN)
	{
		y_pos++;
		if (game->map[y_pos][x_pos] == '1')
			return (0);
		valid = valid_move(game, x_pos, y_pos);
		if (!valid)
			return (0);
		game->map[y_pos - 1][x_pos] = '0';
	}
	return (1);
}

int	left_right(t_data *game, int keysym)
{
	int	x_pos2;
	int	y_pos2;
	int	valid2;

	x_pos2 = game->px_pos;
	y_pos2 = game->py_pos;
	if (keysym == LEFT)
	{
		x_pos2--;
		if (game->map[y_pos2][x_pos2] == '1')
			return (0);
		valid2 = valid_move(game, x_pos2, y_pos2);
		if (!valid2)
			return (0);
		game->map[y_pos2][x_pos2 + 1] = '0';	
	}
	else if (keysym == RIGHT)
	{
		x_pos2++;
		if (game->map[y_pos2][x_pos2] == '1')
			return (0);
		valid2 = valid_move(game, x_pos2, y_pos2);
		if (!valid2)
			return (0);
		game->map[y_pos2][x_pos2 - 1] = '0';
	}
	return (1);
}

int	movement(int keypressed, t_data *game)
{
	int	valid1;
	
	valid1 = 0;
	if (keypressed == ESC)
		free_and_destroy(game);
	if (keypressed == LEFT || keypressed == RIGHT)
	{
		valid1 = left_right(game, keypressed);
	}
	if (keypressed == UP || keypressed == DOWN)
	{
		valid1 = up_down(game, keypressed);
	}
	if (valid1)
		img_into_win(game);
	return (1);
}

/*
movement takes the same param as on_keypress, so keypressed will
be the keycode num of the pressed key
int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}
*/