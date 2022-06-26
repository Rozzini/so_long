/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:42:02 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/25 06:10:42 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	free_split(char **s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_staf(t_game *game, t_map *map)
{
	free_split(map->map);
	free(map->player);
	free(map);
	free(game);
}

int	close_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_staf(game, game->map);
	exit(0);
}
