/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:39 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/02 21:07:12 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf/ft_printf.h"
#include "so_long.h"

	//Position of P
	//hazlo un viable path si c_coun != 0?

int	valid_move(t_data *game, int x_pos, int y_pos)
{
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
	int	valid;

	game->x_pos1 = game->px_pos;
	game->y_pos1 = game->py_pos;
	if (keysym == UP)
	{
		game->y_pos1--;
		if (game->map[game->y_pos1][game->x_pos1] == '1')
			return (0);
		valid = valid_move(game, game->x_pos1, game->y_pos1);
		if (!valid)
			return (0);
		game->map[game->y_pos1 + 1][game->x_pos1] = '0';
	}
	else if (keysym == DOWN)
	{
		game->y_pos1++;
		if (game->map[game->y_pos1][game->x_pos1] == '1')
			return (0);
		valid = valid_move(game, game->x_pos1, game->y_pos1);
		if (!valid)
			return (0);
		game->map[game->y_pos1 - 1][game->x_pos1] = '0';
	}
	return (1);
}

int	left_right(t_data *game, int keysym)
{
	int	valid2;

	game->x_pos2 = game->px_pos;
	game->y_pos2 = game->py_pos;
	if (keysym == LEFT)
	{
		game->x_pos2--;
		if (game->map[game->y_pos2][game->x_pos2] == '1')
			return (0);
		valid2 = valid_move(game, game->x_pos2, game->y_pos2);
		if (!valid2)
			return (0);
		game->map[game->y_pos2][game->x_pos2 + 1] = '0';
	}
	else if (keysym == RIGHT)
	{
		game->x_pos2++;
		if (game->map[game->y_pos2][game->x_pos2] == '1')
			return (0);
		valid2 = valid_move(game, game->x_pos2, game->y_pos2);
		if (!valid2)
			return (0);
		game->map[game->y_pos2][game->x_pos2 - 1] = '0';
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
		ft_printf("counter: %d\n", game->shell_count);
	}
	if (keypressed == UP || keypressed == DOWN)
	{
		valid1 = up_down(game, keypressed);
		ft_printf("counter: %d\n", game->shell_count);
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