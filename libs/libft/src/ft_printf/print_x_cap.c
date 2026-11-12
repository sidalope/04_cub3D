/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:52:43 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/26 16:07:07 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_x_cap(unsigned int n)
{
	int		i;
	int		len;
	int		started;

	i = sizeof(unsigned int) * 2 - 1;
	len = 0;
	started = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i >= 0)
	{
		if (started || "0123456789ABCDEF"[(n >> (i * 4)) & 0xF] != '0')
		{
			write(1, &"0123456789ABCDEF"[(n >> (i * 4)) & 0xF], 1);
			len++;
			started = 1;
		}
		i--;
	}
	return (len);
}
