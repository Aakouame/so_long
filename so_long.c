/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:02:09 by akouame           #+#    #+#             */
/*   Updated: 2022/08/15 18:07:06by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data data)
{	
	(void) data;
	exit(0);
	return (0);
}

int key_hook(int key_code, t_data *data)
{
	data->key = key_code;
	if (key_code ==  2)
		ft_mov_right(data, data->map_splited, &data->coin);
	if (key_code == 1)
		ft_mov_down(data, data->map_splited, &data->coin);
	if (key_code == 0)
		ft_mov_left(data, data->map_splited, &data->coin);
	if (key_code == 13)
		ft_mov_up(data, data->map_splited, &data->coin);
	ft_putstr_fd("\nMOVES : ", 1);
	ft_putnbr_fd(data->cpt, 1);
	if (key_code == 53)
		{
			exit(0);
		}
	return (0);
}

int main (int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_check_file(argv))
	{
		if (ft_check_map(argv[1]) != 0)
		{
			data.size = ft_size(argv[1]);
			ft_initial(&data);
			data.map_splited = ft_map(argv[1]);
			data.max_c = ft_all_coins(data.map_splited);
			ft_build_map(data.map_splited, data);
			mlx_hook(data.wind, 17, 1L << 0, ft_exit, &data);
			mlx_hook(data.wind, 2, 0L, key_hook, &data);
			printf("rak nadi canadi \n");
			mlx_loop(data.init);
		}
		else
			ft_putstr_fd("Error : Check ur Map !\n", 1);
	}
	else
		ft_putstr_fd("Error  : Check ur file name !\n",1);
	return (0);
}
