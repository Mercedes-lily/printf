/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:34 by valerie           #+#    #+#             */
/*   Updated: 2023/02/06 11:02:43 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunsignbr_fd(unsigned int n, int fd)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
		count = ft_putnbr_fd_return((int)(n / 10), fd, count++);
	ft_putchar_fd_return((n % 10) + '0', fd);
	count++;
	return (count);
}
