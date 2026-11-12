/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:18:56 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/29 13:08:59 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;

	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1) - 1;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	if (s1[front] == '\0')
		return (ft_strdup(""));
	while (s1[back] && ft_strchr(set, s1[back]))
		back--;
	return (ft_substr(s1, front, back - front + 1));
}
