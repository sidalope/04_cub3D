/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisani <abisani@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:35:09 by abisiani          #+#    #+#             */
/*   Updated: 2025/12/29 18:32:01 by abisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	parse_format_specifier(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len = print_c(va_arg(args, int));
	else if (*format == 's')
		len = print_s(va_arg(args, char *));
	else if (*format == 'p')
		len = print_p(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		len = print_di(va_arg(args, int));
	else if (*format == 'u')
		len = print_u(va_arg(args, unsigned int));
	else if (*format == 'x')
		len = print_x(va_arg(args, unsigned int));
	else if (*format == 'X')
		len = print_x_cap(va_arg(args, unsigned int));
	else if (*format == '%')
		len = write(1, "%", 1);
	else
	{
		len += write(1, "%", 1);
		len += write(1, format, 1);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	int		non_format_chars;

	count = 0;
	non_format_chars = 0;
	va_start(args, format);
	while (*format)
	{
		while (format[non_format_chars] && format[non_format_chars] != '%')
			non_format_chars++;
		write(1, format, non_format_chars);
		count += non_format_chars;
		format += non_format_chars;
		if (*format == '%')
		{
			format++;
			if (*format)
				count += parse_format_specifier(format, args);
			else
				count += write(1, "%", 1);
			format++;
		}
		non_format_chars = 0;
	}
	va_end(args);
	return (count);
}
