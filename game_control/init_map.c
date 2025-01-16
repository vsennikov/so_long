/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:31:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 12:26:42 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win_ptr, game->s_wall, y * 18,
		x * 18);
}

static void	display_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win_ptr, game->s_player, y
		* 18, x * 18);
}

static void	display_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win_ptr, game->s_floor, y * 18,
		x * 18);
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->map_h)
	{
		y = 0;
		while (y < game->map->map_w)
		{
			if (game->map->values[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win_ptr,
					game->s_coin, y * 18, x * 18);
			if (game->map->values[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win_ptr,
					game->s_exit, y * 18, x * 18);
			if (game->map->values[x][y] == '0')
				display_floor(game, x, y);
			if (game->map->values[x][y] == 'P')
				display_player(game, x, y);
			if (game->map->values[x][y] == '1')
				display_wall(game, x, y);
			y++;
		}
		x++;
	}
}

void	init_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->s_coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &i,
			&j);
	game->s_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i,
			&j);
	game->s_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i,
			&j);
	game->s_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &i,
			&j);
	game->s_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i,
			&j);
	check_displaying(game);
	display_map(game);
}
