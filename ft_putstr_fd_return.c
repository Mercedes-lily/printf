/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_return.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:57:43 by valerie           #+#    #+#             */
/*   Updated: 2023/02/06 11:01:59 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putstr_fd_return(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd_return(s[i], fd);
		i++;
	}
	return (i);
}
