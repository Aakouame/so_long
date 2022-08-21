/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:41:17 by akouame           #+#    #+#             */
/*   Updated: 2022/08/21 13:42:34 by akouame          ###   ########.fr       */
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

void	ft_help_down(t_data *data, char **map_splited, int *coin, t_size indx_p)
{
	if (map_splited[indx_p.y + 1][indx_p.x] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y + 1][indx_p.x] = 'P';
		(data->cpt)++;

		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
	if (map_splited[indx_p.y + 1][indx_p.x] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y + 1][indx_p.x] = 'P';
		(*coin)++;
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
}

void	ft_mov_down(t_data *data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	printf ("we are in ft_mov_down !\n");
	if (map_splited[indx_p.y + 1][indx_p.x] == 'E' && *coin != data->max_c)
		return ;
	if (map_splited[indx_p.y + 1][indx_p.x] == '1')
		return ;
	if ((*coin) == data->max_c && map_splited[indx_p.y + 1][indx_p.x] == 'E')
	{
		printf ("hola\n\n");
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y + 1][indx_p.x] = 'E';
		mlx_clear_window(data->init, data->wind);
		(data->cpt)++;

		ft_build_map(map_splited, *data);
		exit(1);
	}
	ft_help_down(data, data->map_splited, &data->coin, indx_p);
}

void	ft_help_up(t_data *data, char **map_splited, int *coin, t_size indx_p)
{
	if (map_splited[indx_p.y - 1][indx_p.x] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y - 1][indx_p.x] = 'P';
		(data->cpt)++;

		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
	if (map_splited[indx_p.y - 1][indx_p.x] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y - 1][indx_p.x] = 'P';
		(*coin)++;
		(data->cpt)++;

		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
}

void	ft_mov_up(t_data *data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	printf ("we are in ft_mov_up !\n");
	if (map_splited[indx_p.y - 1][indx_p.x] == 'E' && *coin != data->max_c)
		return ;
	if (map_splited[indx_p.y - 1][indx_p.x] == '1')
		return ;
	if ((*coin) == data->max_c && map_splited[indx_p.y - 1][indx_p.x] == 'E')
	{
		printf ("hola\n\n");
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y - 1][indx_p.x] = 'E';
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
		exit(1);
	}
	ft_help_up(data, data->map_splited, &data->coin, indx_p);
}

