/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:35:15 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/25 05:20:17 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	read_map_from_fd(char *file, t_map *map)
{
	int		fd_error;
	char	*temp;
	char	*s;

	fd_error = open(file, O_RDONLY);
	s = NULL;
	temp = get_next_line(fd_error);
	while (temp != NULL)
	{
		s = ft_strjoin_gnl(s, temp);
		temp = get_next_line(fd_error);
		if (temp != NULL && temp[0] == '\n')
			return (-1);
	}
	free(temp);
	fd_error = call_checkers(s, map);
	return (fd_error);
}

int	call_checkers(char *s, t_map *map)
{
	int	err;

	if (s == NULL)
		return (-1);
	err = split_map_check_lines(s, map);
	if (err == 0)
	{
		err += check_symbols(map);
		err += check_top_bot_boundaries(map);
		err += check_side_boundaries(map);
		err += check_coins(map);
		err += check_exit(map);
		err += check_player(map);
	}
	return (err);
}

int	split_map_check_lines(char *s, t_map *map)
{
	int	i;

	i = 0;
	map->map = ft_split(s, '\n');
	map->w = ft_strlen(map->map[0]);
	while (map->map[i] != NULL)
	{
		if (ft_strlen(map->map[i]) != map->w)
			return (1);
		i++;
	}
	map->h = i;
	return (0);
}
