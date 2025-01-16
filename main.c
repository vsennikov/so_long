/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:25 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 13:05:35 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sub_init(t_game *game, t_map *map, t_player *player)
{
	map->map_h = 0;
	map->map_w = 0;
	map->num_con = 0;
	map->num_ex = 0;
	map->num_pl = 0;
	map->col_for_valid = 0;
	player->x_pos = 0;
	player->y_pos = 0;
	game->map = map;
	game->player = player;
	game->mooves = 0;
	game->ex_x = 0;
	game->ex_y = 0;
}

static void	map_init(t_game *game)
{
	t_map		*map;
	t_player	*player;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		free(game);
		error_exit("memory allocation for map failed");
	}
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
	{
		free(map);
		free(game);
		error_exit("memory allocation for player failed");
	}
	sub_init(game, map, player);
}

static void	free_stuff(t_game *game, char *msg)
{
	free_map(game->map);
	free(game->player);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->mlx_win_ptr)
		free(game->mlx_win_ptr);
	free(game);
	error_exit(msg);
}

static void	game_stuff(char **argv, t_game *game)
{
	void	*win_ptr;
	void	*mlx;

	map_init(game);
	map_parsing(argv[1], game);
	map_validation(game);
	mlx = mlx_init();
	if (!mlx)
		free_stuff(game, "mlx failed");
	game->mlx = mlx;
	win_ptr = mlx_new_window(game->mlx, game->map->map_w * 18, game->map->map_h
			* 18, "so_long");
	if (!win_ptr)
		free_stuff(game, "mlx_new_window failed");
	game->mlx_win_ptr = win_ptr;
	init_map(game);
	mlx_key_hook(game->mlx_win_ptr, key_hook, game);
	mlx_hook(game->mlx_win_ptr, 17, 1L << 0, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
		error_exit("no map provided");
	else if (argc > 2)
		error_exit("too many arguments");
	name_validation(argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		error_exit("memory allocation for game failed");
	game_stuff(argv, game);
	return (0);
}
