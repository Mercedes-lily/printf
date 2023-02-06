/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:47:50 by vst-pier          #+#    #+#             */
/*   Updated: 2023/02/06 10:58:12 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	print_to_convert(char c, va_list to_convert)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar_fd_return(c, 1);
	if (c == 'c')
		count = ft_putchar_fd_return(va_arg(to_convert, int), 1);
	else if (c == 's')
		count = ft_putstr_fd_return(va_arg(to_convert, char *), 1);
	else if (c == 'i' || c == 'd')
		count = ft_putnbr_fd_return(va_arg(to_convert, int), 1, 0);
	else if (c == 'u')
		count = ft_putunsignbr_fd(va_arg(to_convert, unsigned int), 1);
	else if (c == 'x')
		count = ft_puthexnbr_fd(va_arg(to_convert, int), 1, 0);
	else if (c == 'X')
		count = ft_puthexxnbr_fd(va_arg(to_convert, int), 1, 0);
	else if (c == 'p')
		count = ft_putaddinhex_fd(va_arg(to_convert, unsigned long), 1, 0);
	return (count);
}

static char	*print_until_percentage(const char *string, int index)
{
	char	*tab;
	int		count;

	tab = malloc(sizeof(char) * 3);
	if (!tab)
		return (NULL);
	count = 0;
	while (string[index] && string[index] != '%')
	{
		count += ft_putchar_fd_return(string[index], 1);
		index++;
	}
	tab[0] = index;
	tab[1] = count;
	tab[2] = '\0';
	return (tab);
}

int	ft_printf(const char *string, ...)
{
	int		index;
	int		count;
	char	*tab;
	va_list	to_convert;

	index = 0;
	count = 0;
	va_start(to_convert, string);
	while (string[index])
	{
		tab = print_until_percentage(string, index);
		count = count + (int)tab[1];
		index = (int)tab[0];
		free(tab);
		if (string[index] && string[index] == '%')
		{
			index++;
			count += print_to_convert(string[index], to_convert);
			index++;
		}
	}
	va_end(to_convert);
	return (count);
}
