/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student->42->fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:19:13 by akouame           #+#    #+#             */
/*   Updated: 2022/08/21 13:11:13 by akouame          ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

void	ft_help_right(t_data *data, char **map_splited, int *coin, t_size indx_p)
{
	if (map_splited[indx_p.y][indx_p.x + 1] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'P';
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
	if (map_splited[indx_p.y][indx_p.x + 1] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'P';
		(*coin)++;
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
}

void	ft_mov_right(t_data *data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	if (map_splited[indx_p.y][indx_p.x + 1] == 'E' && *coin != data->max_c)
		return ;
	if (map_splited[indx_p.y][indx_p.x + 1] == '1')
		return ;
	if ((*coin) == data->max_c && map_splited[indx_p.y][indx_p.x + 1] == 'E')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x] = 'E';
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
		exit(1);
	}
	ft_help_right(data, data->map_splited, &data->coin, indx_p);
}

void	ft_help_left(t_data *data, char **map_splited, int *coin, t_size indx_p)
{
	if (map_splited[indx_p.y][indx_p.x - 1] == '0')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
	if (map_splited[indx_p.y][indx_p.x - 1] == 'C')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x - 1] = 'P';
		(data->cpt)++;
		(*coin)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
	}
}


void	ft_mov_left(t_data *data, char **map_splited, int *coin)
{
	t_size	indx_p;

	indx_p = ft_position(map_splited);
	if (map_splited[indx_p.y][indx_p.x - 1] == 'E' && *coin != data->max_c)
		return ;
	if (map_splited[indx_p.y][indx_p.x - 1] == '1')
		return ;
	if ((*coin) == data->max_c && map_splited[indx_p.y][indx_p.x - 1] == 'E')
	{
		map_splited[indx_p.y][indx_p.x] = '0';
		map_splited[indx_p.y][indx_p.x + 1] = 'E';
		(data->cpt)++;
		mlx_clear_window(data->init, data->wind);
		ft_build_map(map_splited, *data);
		exit(1);
	}
	ft_help_left(data, data->map_splited, &data->coin, indx_p);
}

