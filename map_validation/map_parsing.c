/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:04:43 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/21 18:26:05 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static int	calculate_size(char *map_name)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_exit("wrong file permission");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

static void	assigne_values(char *line, t_map *map, int fd)
{
	int		i;
	char	*line_no_n;

	i = 0;
	line_no_n = ft_substr(line, 0, map->map_w);
	if (!line_no_n)
	{
		close(fd);
		free_map(map);
		free(line);
		error_exit("memmort allocation during ft_substr failed");
	}
	free(line);
	map->values[map->map_h] = line_no_n;
}

static void read_and_assigne(char *line, int fd, t_map *map)
{
	while (line)
	{
		if (map->map_w != count_char(line))
		{
			free(line);
			free_map(map);
			close(fd);
			error_exit("some line are longer or shorter");
		}
		assigne_values(line, map, fd);
		map->map_h++;
		line = get_next_line(fd);
	}
	close(fd);
}

void	map_parsing(char *map_name, t_map *map)
{
	char	*line;
	int		fd;
	int		pos_size;

	pos_size = calculate_size(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_exit("wrong file permission");
	line = get_next_line(fd);
	map->map_w = count_char(line);
	map->values = ft_calloc(sizeof(char *), (pos_size + 1));
	if (!map->values)
		error_exit("memory allocation for map->values failed");
	map->map_h = 0;
	read_and_assigne(line, fd, map);
}
