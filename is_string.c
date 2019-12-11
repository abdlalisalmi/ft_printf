/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:54:01 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/11 15:01:50 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void    right_print(char *str, int strlen, t_struct *list)
{
    if (strlen > list->precision && list->precision > 0)
        strlen = list->precision;
    if (list->precision == 0)
        strlen = 0;
    list->nprint += write(1, str, strlen);
    while (list->width > strlen)
    {
        list->nprint += write(1, " ", 1);
        list->width--;
    }
}

static void    left_print(char *str, int strlen, t_struct *list)
{
    if (strlen > list->precision && list->precision > 0)
        strlen = list->precision;
    if (list->precision == 0)
        strlen = 0;
    if (list->width > strlen)
    {
        while ((list->width - strlen) > 0)
        {
            list->nprint += write(1, " ", 1);
            list->width--;
        }
    }
    list->nprint += write(1, str, strlen);
}

void is_string(t_struct *list, va_list ap)
{
    char *str;
    int strlen;

    str = (char *)va_arg(ap, char *);
    if (str == NULL)
        str = "(null)";
    strlen = ft_strlen(str);
    if (list->minus == 0)
        left_print(str, strlen, list);
    else
        right_print(str, strlen, list);
}
