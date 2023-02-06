/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:00:51 by valerie           #+#    #+#             */
/*   Updated: 2023/02/06 11:02:27 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_fd_return(int n, int fd, int count)
{
	long int	n2;

	n2 = (long int)n;
	if (n2 < 0)
	{
		ft_putchar_fd_return('-', fd);
		n2 = -n2;
		count++;
	}
	if (n2 >= 0)
	{
		if (n2 > 9)
			count = ft_putnbr_fd_return((int)(n2 / 10), fd, count++);
		ft_putchar_fd_return((n2 % 10) + '0', fd);
		count++;
	}
	return (count);
}
