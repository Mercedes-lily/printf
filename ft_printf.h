/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:36:30 by cchouina          #+#    #+#             */
/*   Updated: 2023/02/06 10:48:09 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *string, ...);
unsigned int	ft_puthexxnbr_fd(unsigned int nbr, int fd, int count);
unsigned int	ft_puthexnbr_fd(unsigned long nbr, int fd, int count);
unsigned int	ft_putaddinhex_fd(unsigned long add, int fd, unsigned int c);
unsigned int	ft_putnbr_fd_return(int n, int fd, int count);
unsigned int	ft_putstr_fd_return(char *s, int fd);
unsigned int	ft_putunsignbr_fd(unsigned int n, int fd);
unsigned int	ft_putchar_fd_return(char c, int fd);

#endif