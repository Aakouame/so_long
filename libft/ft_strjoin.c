/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:55:27 by akouame           #+#    #+#             */
/*   Updated: 2022/08/21 18:10:06 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		i;
	int		j;
	char const	*ss1;

	if (!s1)
		return ((char *)s2);
	j = 0;
	ss1 = s1;
	t = malloc (((ft_strlen(s1) + ft_strlen(s2)) + 2) * sizeof(char));
	free((char *)s1);
	if (t == NULL)
		return (NULL);
	i = ft_strlen(ss1);
	while (j < i)
	{
		t[j] = (char)ss1[j];
		j++;
	}
	j = 0;
	while (s2[j])
		t[i++] = (char)s2[j++];
	t[i] = '\0';
	return (t);
}
