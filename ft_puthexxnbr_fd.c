/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexxnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:04:56 by valerie           #+#    #+#             */
/*   Updated: 2023/02/06 10:59:28 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthexxnbr_fd(unsigned int nbr, int fd, int count)
{
	int	multiplication;
	int	total;
	int	rest;

	multiplication = nbr / 16;
	total = multiplication * 16;
	rest = nbr - total;
	if (total > 0)
		count = ft_puthexxnbr_fd(multiplication, fd, count++);
	if (rest >= 0 && rest <= 9)
	{
		ft_putchar_fd_return(rest + '0', 1);
		count++;
	}
	if (rest >= 10 && rest <= 15)
	{
		ft_putchar_fd_return(rest - 10 + 'A', 1);
		count++;
	}
	return (count);
}
