/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:34:52 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/26 04:54:12 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_if_er(t_map *map, t_game *game, int sw)
{
	if (sw == 1)
	{
		free_split(map->map);
		free(map->player);
	}
	free(map);
	free(game);
	exit(0);
}

void	check_error(char *s, t_map *map, t_game *game)
{
	int	err;

	err = read_map_from_fd(s, map);
	if (err == -1)
	{
		ft_printf("Error\nEmpty/Wrong file\n");
		free_if_er(map, game, 0);
	}
	if (err != 0)
	{
		ft_printf("Error\nMap Error\n");
		free_if_er(map, game, 1);
	}
}

void	check_file_name(int argc, char *s, t_map *map, t_game *game)
{
	char	*c;

	if (argc < 2)
	{
		ft_printf("Error\nAdd map\n");
		free_if_er(map, game, 0);
	}
	c = ft_strnstr(s, ".ber", ft_strlen(s));
	if (c == NULL)
	{
		ft_printf("Error\nExtension Error\n");
		free_if_er(map, game, 0);
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;
	t_wme	**wme;

	map = malloc(sizeof(t_map));
	game = malloc(sizeof(t_game));
	init_structs(map, game);
	check_file_name(argc, argv[1], map, game);
	check_error(argv[1], map, game);
	wme = malloc(sizeof(t_wme) * count_wme(map));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	draw_map(map, game, wme);
	mlx_hook(game->mlx_win, 2, 1L << 0, move, game);
	mlx_hook(game->mlx_win, 17, (1L << 17), close_game, game);
	mlx_loop(game->mlx);
	return (0);
}


// #include <time.h>

// int	animate(t_game *game)
// {
// 	static time_t prev;
// 	time_t current;
// 	time_t dif;
	
// 	game->steps = 0;
//     current = time(NULL);
// 	if (prev == 0)
// 	{
// 		move_wme(game);
// 		prev = current;
// 	}
// 	dif = current - prev;
// 	if (dif >= 2)
// 	{
// 		move_wme(game);
// 		prev = current;
// 	}
// 	return (0);
// }