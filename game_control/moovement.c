/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:30:42 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/26 16:51:46 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_images(t_game *game)
{
	if (game->s_coin)
		mlx_destroy_image(game->mlx, game->s_coin);
	if (game->s_wall)
		mlx_destroy_image(game->mlx, game->s_wall);
	if (game->s_floor)
		mlx_destroy_image(game->mlx, game->s_floor);
	if (game->s_player)
		mlx_destroy_image(game->mlx, game->s_player);
	if (game->s_exit)
		mlx_destroy_image(game->mlx, game->s_exit);
}

int	close_window(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->values[i])
		free(game->map->values[i++]);
	free(game->map->values);
	free(game->map);
	free(game->player);
	delete_images(game);
	mlx_destroy_window(game->mlx, game->mlx_win_ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
	return (0);
}

static void	move_player(t_game *game, int x, int y)
{
	game->player->old_x = game->player->x_pos;
	game->player->old_y = game->player->y_pos;
	if (game->map->values[game->player->x_pos + x][game->player->y_pos
		+ y] == '1')
		return ;
	game->player->x_pos += x;
	game->player->y_pos += y;
	if (game->map->values[game->player->x_pos][game->player->y_pos] == 'C')
		--game->map->num_con;
	ft_printf("Mooves: %d\n", ++game->mooves);
	if (game->map->values[game->player->x_pos][game->player->y_pos] == 'E'
		&& game->map->num_con != 0)
	{
		game->ex_x = game->player->x_pos;
		game->ex_y = game->player->y_pos;
	}
	else if (game->map->values[game->player->x_pos][game->player->y_pos] == 'E'
		&& game->map->num_con == 0)
		close_window(game);
	if (game->player->old_x == game->ex_x && game->player->old_y == game->ex_y)
		game->map->values[game->player->old_x][game->player->old_y] = 'E';
	else
		game->map->values[game->player->old_x][game->player->old_y] = '0';
	game->map->values[game->player->x_pos][game->player->y_pos] = 'P';
	display_map(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 1, 0);
	return (0);
}
