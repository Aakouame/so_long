/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:55:27 by akouame           #+#    #+#             */
/*   Updated: 2022/06/03 11:58:44 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	j = 0;
	t = malloc (((ft_strlen(s1) + ft_strlen(s2)) + 2) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = ft_strlen(s1);
	while (j < i)
	{
		t[j] = (char)s1[j];
		j++;
	}
	j = 0;
	t[i++] = ' ';
	while (s2[j])
	{
		t[i++] = (char)s2[j];
		j++;
	}
	t[i] = '\0';
	return (t);
}
