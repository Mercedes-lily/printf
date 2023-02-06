/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddinhex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:27:30 by vst-pier          #+#    #+#             */
/*   Updated: 2023/02/06 11:00:19 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthexnbr2_fd(unsigned long nbr, int fd, int c)
{
	long	multiplication;
	long	total;
	long	rest;

	multiplication = nbr / 16;
	total = multiplication * 16;
	rest = nbr - total;
	if (total > 0)
		c = ft_puthexnbr2_fd(multiplication, fd, c++);
	if (rest >= 0 && rest <= 9)
	{
		ft_putchar_fd_return(rest + '0', 1);
		c++;
	}
	if (rest >= 10 && rest <= 15)
	{
		ft_putchar_fd_return(rest - 10 + 'a', 1);
		c++;
	}
	return (c);
}

unsigned int	ft_putaddinhex_fd(unsigned long add, int fd, unsigned int c)
{
	unsigned long	multiplication;
	unsigned long	total;
	unsigned long	rest;

	ft_putstr_fd_return("0x", 1);
	multiplication = add / 16;
	total = multiplication * 16;
	rest = add - total;
	if (total > 0)
		c = ft_puthexnbr2_fd(multiplication, fd, c++);
	if (rest >= 0 && rest <= 9)
	{
		ft_putchar_fd_return(rest + '0', 1);
		c++;
	}
	if (rest >= 10 && rest <= 15)
	{
		ft_putchar_fd_return(rest - 10 + 'a', 1);
		c++;
	}
	return (c + 2);
}
