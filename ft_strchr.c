/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:39:50 by aes-salm          #+#    #+#             */
/*   Updated: 2019/10/14 16:39:55 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	char			*pstr;
	unsigned int	i;

	pstr = (char*)str;
	i = 0;
	while (i <= ft_strlen(pstr))
	{
		if (str[i] == c)
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
