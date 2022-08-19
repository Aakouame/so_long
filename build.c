/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:20:36 by akouame           #+#    #+#             */
/*   Updated: 2022/08/19 17:00:54 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initial(t_data *data)
{
	data->init = mlx_init();
	data->wind = mlx_new_window(data->init, (data->size.x * 32), (data->size.y * 32), "SO_LONG");
	data->img_coin = mlx_xpm_file_to_image(data->init, )
}