/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:19:13 by akouame           #+#    #+#             */
/*   Updated: 2022/08/20 21:32:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_size	ft_position(char **map_splited)
{
	t_size	indx;

	indx.y = 0;
	while (map_splited[indx.y])
	{
		indx.x = 0;
		while (map_splited[indx.y][indx.x])
		{
			if (map_splited[indx.y][indx.x] == 'P')
				return (indx);
			indx.x++;
		}
		indx.y++;
	}	
	return (indx);
}

int	ft_all_coins(char **map_splited)
{
	int	c;
	t_size	i;

	i.y = 0;
	c = 0;
	while (map_splited[i.y])
	{
		i.x = 0;
		while (map_splited[i.y][i.x])
		{
			if (map_splited[i.y][i.x] == 'C')
				c++;
			i.x++;
		}
		i.y++;
	}
	return (c);
}

void	ft_mov_right(t_data data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	printf ("we are in ft_mov_right !\n");
	if (map_splited[indx_p.y][indx_p.x + 1] == 'E' && *coin != data.max_c)
		return ;
	if (map_splited[indx_p.y][indx_p.x + 1] == '1')
		return ;
	if ((*coin) == data.max_c && map_splited[indx_p.y][indx_p.x + 1] == 'E')
	{
		printf ("hola\n\n");
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x] = 'E';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
		exit(1);
	}
	if (map_splited[indx_p.y][indx_p.x + 1] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'P';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
	if (map_splited[indx_p.y][indx_p.x + 1] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'P';
		(*coin)++;
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
}

void	ft_mov_left(t_data data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	printf ("we are in ft_mov_right !\n");
	if (map_splited[indx_p.y][indx_p.x - 1] == 'E' && *coin != data.max_c)
		return ;
	if (map_splited[indx_p.y][indx_p.x - 1] == '1')
		return ;
	if ((*coin) == data.max_c && map_splited[indx_p.y][indx_p.x - 1] == 'E')
	{
		printf ("hola\n\n");
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'E';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
		exit(1);
	}
	if (map_splited[indx_p.y][indx_p.x - 1] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
	if (map_splited[indx_p.y][indx_p.x - 1] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		(*coin)++;
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
}

void	ft_mov_(t_data data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	printf ("we are in ft_mov_right !\n");
	if (map_splited[indx_p.y][indx_p.x - 1] == 'E' && *coin != data.max_c)
		return ;
	if (map_splited[indx_p.y][indx_p.x - 1] == '1')
		return ;
	if ((*coin) == data.max_c && map_splited[indx_p.y][indx_p.x - 1] == 'E')
	{
		printf ("hola\n\n");
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'E';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
		exit(1);
	}
	if (map_splited[indx_p.y][indx_p.x - 1] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
	if (map_splited[indx_p.y][indx_p.x - 1] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		(*coin)++;
		mlx_clear_window(data.init, data.wind);
		ft_build_map(map_splited, data);
	}
}