/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 22:47:32 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:28:49 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	t;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	t = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (t > i && ft_strchr(set, s1[t - 1]))
		t--;
	str = ft_substr(s1, i, (t - i));
	return (str);
}
