/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:06:10 by akouame           #+#    #+#             */
/*   Updated: 2022/08/21 18:40:54 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_exist(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_map(char **map_splited)
{
	int	i;

	i = 0;
	while (map_splited[i])
	{
		free(map_splited[i]);
		i++;
	}
	free(map_splited);
}

int	ft_hep_check_split(char **map_splited, t_size indx, t_size max)
{
	while(map_splited[indx.y])
	{
		if ((ft_strlen(map_splited[indx.y]) - 1) != ((size_t)max.x))
			{
				ft_free_map(map_splited);
				return (1);
			}
		indx.x = 0;
		while (map_splited[indx.y][indx.x])	
		{
			if (map_splited[0][indx.x] != '1' || map_splited[indx.y][0] != '1'
				|| map_splited[max.y][indx.x] != '1' || map_splited[indx.y][max.x] != '1')
			{
				ft_free_map(map_splited);
				return (1);
			}
			(indx.x)++;
		}
		(indx.y)++;
	}
	return (0);
}