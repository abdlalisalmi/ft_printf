/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:45:36 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/13 17:46:37 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*convert(char *hexa, unsigned long decimal,
					int taille, unsigned long res)
{
	char	tb[100];
	int		i;

	i = 0;
	if (decimal == 0)
		tb[i++] = '0';
	else
	{
		while (decimal != 0)
		{
			res = decimal % 16;
			if (res < 10)
				res += '0';
			else
				res += taille;
			tb[i] = res;
			i++;
			decimal /= 16;
		}
	}
	tb[i] = '\0';
	hexa = ft_strdup(tb);
	return (*&hexa);
}

char			*convert_to_hexa(unsigned long decimal, char c)
{
	char			*hexa;
	unsigned long	res;
	int				taille;

	hexa = NULL;
	res = 0;
	taille = 87;
	if (c == 'X')
		taille = 55;
	hexa = convert(hexa, decimal, taille, res);
	return (ft_strrev(hexa));
}
