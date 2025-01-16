/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:53:58 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 12:31:43 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	name_validation(char *name)
{
	int		i;
	char	*extension;

	i = 0;
	while (name[i])
	{
		if (name[i] == '.' && name[i + 4] == '\0')
		{
			extension = ft_substr(name, i, 5);
			if (!extension)
				error_exit("memory allocation during name_validation failed");
			if (ft_strncmp(extension, ".ber", 5) != 0)
			{
				free(extension);
				error_exit("map not .ber");
			}
			else
				return (free(extension), 1);
		}
		i++;
	}
	error_exit("map not .ber");
	return (1);
}
