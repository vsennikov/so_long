/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:43 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 13:04:19 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_char(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static int	calculate_size(char *map_name, t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		ended;

	ended = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_pars(game, "wrong file permission", fd);
	line = get_next_line(fd, &ended);
	if (ended == -1)
		error_pars(game, "gnl failed 1", fd);
	i = 0;
	while (!ended)
	{
		i++;
		free(line);
		line = get_next_line(fd, &ended);
		if (ended == -1)
			error_pars(game, "gnl failed 2", fd);
	}
	close(fd);
	return (i);
}

static void	update_line(t_game *game)
{
	int		i;
	char	*new_line;

	i = 0;
	while (game->map->values[i])
	{
		if (game->map->map_w != count_char(game->map->values[i]))
			error_ass(game, "some line are longer or shorter");
		new_line = ft_substr(game->map->values[i], 0, game->map->map_w);
		if (!new_line)
			error_ass(game, "ft_substr failed");
		free(game->map->values[i]);
		game->map->values[i] = new_line;
		i++;
	}
}

static void	transit_map(char *line, int fd, t_game *game)
{
	int	i;
	int	ended;

	i = 0;
	ended = 0;
	while (!ended)
	{
		game->map->values[i++] = line;
		line = get_next_line(fd, &ended);
		if (ended == -1)
			error_pars(game, "gnl failed 5", fd);
		game->map->map_h++;
	}
	close(fd);
}

void	map_parsing(char *map_name, t_game *game)
{
	char	*line;
	int		fd;
	int		pos_size;
	int		i;
	int		ended;

	ended = 0;
	pos_size = calculate_size(map_name, game);
	game->map->values = ft_calloc((pos_size + 1), sizeof(char *));
	if (!game->map->values)
		error_pars(game, "memory allocation for map->values failed", 0);
	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_pars(game, "wrong file permission", fd);
	line = get_next_line(fd, &ended);
	if (ended == -1)
		error_pars(game, "gnl failed 5", fd);
	game->map->map_w = count_char(line);
	if (game->map->map_w == -1)
		error_pars(game, "empty line", fd);
	transit_map(line, fd, game);
	update_line(game);
}
