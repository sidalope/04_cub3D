/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:16:44 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/27 10:14:57 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_u(unsigned int n)
{
	int	len;

	len = ft_uintlen(n);
	ft_putunbr_fd(n, 1);
	return (len);
}
