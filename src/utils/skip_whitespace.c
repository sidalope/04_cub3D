/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:35:23 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/14 21:37:43 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_whitespace(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (str + i);
}
