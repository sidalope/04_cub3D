/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:52:38 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/27 09:41:46 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_s(char *s)
{
	int		len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	len += write(1, s, ft_strlen(s));
	return (len);
}
