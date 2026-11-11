/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:53:17 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/27 10:11:58 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	int		len_n;
	char	*i_str;

	num = n;
	len_n = ft_intlen(n);
	i_str = (char *) ft_calloc(len_n + 1, 1);
	if (!i_str)
		return (NULL);
	if (num == 0)
	{
		i_str[0] = '0';
		return (i_str);
	}
	if (num < 0)
	{
		i_str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		i_str[--len_n] = num % 10 + '0';
		num /= 10;
	}
	return (i_str);
}
