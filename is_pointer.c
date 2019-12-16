/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:22:00 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/15 21:58:03 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*long_to_hexa(unsigned long decimal)
{
	char			tb[100];
	unsigned long	res;
	int				i;

	res = 0;
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
				res += 87;
			tb[i++] = res;
			decimal /= 16;
		}
	}
	tb[i++] = 'x';
	tb[i++] = '0';
	tb[i] = '\0';
	return (ft_strrev(ft_strdup(tb)));
}

static void		right_print(t_struct *list, char *pointer, int pointer_len)
{
	list->nprint += write(1, pointer, pointer_len);
	if (list->width > pointer_len)
		list->width -= pointer_len;
	else
		list->width = 0;
	while (list->width > 0)
	{
		list->nprint += write(1, " ", 1);
		list->width--;
	}
}

static void		left_print(t_struct *list, char *pointer, int pointer_len)
{
	if (list->width > pointer_len)
		list->width -= pointer_len;
	else
		list->width = 0;
	while (list->width > 0)
	{
		list->nprint += write(1, " ", 1);
		list->width--;
	}
	list->nprint += write(1, pointer, pointer_len);
}

void			is_pointer(t_struct *list, va_list ap)
{
	unsigned long long	pointer;
	char				*str_pointer;
	int					pointer_len;

	pointer = (unsigned long long)va_arg(ap, void*);
	str_pointer = long_to_hexa(pointer);
	if (str_pointer[2] == '0' && list->precision == 0)
		pointer_len = 2;
	else
		pointer_len = ft_strlen(str_pointer);
	if (list->minus == 0)
		left_print(list, str_pointer, pointer_len);
	else if (list->minus == 1)
		right_print(list, str_pointer, pointer_len);
	free(str_pointer);
}
