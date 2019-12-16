/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:08:27 by aes-salm          #+#    #+#             */
/*   Updated: 2019/11/28 14:17:09 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n)
{
	unsigned int	nb;
	int				nprint;

	nb = n;
	nprint = 0;
	if (n < 0)
	{
		nprint += ft_putchar('-');
		nb = n * (-1);
	}
	if (nb > 10)
	{
		nprint += ft_putnbr((nb / 10));
		nprint += ft_putnbr((nb % 10));
	}
	else
		nprint += ft_putchar((nb + '0'));
	return (nprint);
}
