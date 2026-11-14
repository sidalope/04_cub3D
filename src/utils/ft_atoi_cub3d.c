/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 22:27:01 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/14 22:27:51 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	ft_atoi_cub3d(const char *str)
{
	int		i;
	int		integer;
	int		minus;

	i = skip_whitespace(str);
	integer = -1;
	minus = 0;
	if (str[i])
	{
		if (str[i] == '-')
		{
			minus = 1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			integer = integer * 10 + str[i] - '0';
			i++;
		}
		if (minus)
			integer *= -1;
	}
	return (integer);
}
