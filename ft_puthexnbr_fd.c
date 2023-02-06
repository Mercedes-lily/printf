/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:04:49 by valerie           #+#    #+#             */
/*   Updated: 2023/02/06 10:58:39 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthexnbr_fd(unsigned long nbr, int fd, int count)
{
	int	multiplication;
	int	total;
	int	rest;

	multiplication = nbr / 16;
	total = multiplication * 16;
	rest = nbr - total;
	if (total > 0)
		count = ft_puthexnbr_fd(multiplication, fd, count++);
	if (rest >= 0 && rest <= 9)
	{
		ft_putchar_fd_return(rest + '0', 1);
		count++;
	}
	if (rest >= 10 && rest <= 15)
	{
		ft_putchar_fd_return(rest - 10 + 'a', 1);
		count++;
	}
	return (count);
}
