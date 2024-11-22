/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:25 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/22 17:45:13 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init(t_map *map, t_player *player)
{
	map->map_h = 0;
	map->map_w = 0;
	map->num_con = 0;
	map->num_ex = 0;
	map->num_pl = 0;
	map->col_for_valid = 0;
	player->x_pos = 0;
	player->y_pos = 0;
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;
	void	*mlx;
	void	*mlx_win;
		
	if (argc == 1)
		error_exit("no map provided");
	else if (argc > 2)
		error_exit("too many arguments");
	name_validation(argv[1]);
	map = malloc(sizeof(t_map));
	if (!map)
		error_exit("memory allocation for map failed");
	player = malloc(sizeof(t_player));
	if (!player)
		error_exit("memory allocation for player failed");
	map_init(map, player);
	map_parsing(argv[1], map);
	map_validation(map, player);
	free_map(map);
	free(player);
	ft_printf("good job!\n");
	mlx = mlx_init();
	void *img;
	char *relative_path = "textures/asphalt3.png";
	int		img_width;
	int	img_height;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	
	mlx_loop(mlx);
	return (0);
}
