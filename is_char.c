/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:01:58 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/08 22:31:16 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void right_print(char c, t_struct *list)
{
    list->nprint += write(1, &c, 1);
    if (list->width > 0)
    {
        list->width--;
        while (list->width > 0)
        {
            list->nprint += write(1, " ", 1);
            list->width--;
        }
    }
}

static void left_print(char c, t_struct *list)
{
    if (list->width > 0)
    {
        list->width--;
        while (list->width > 0)
        {
            list->nprint += write(1, " ", 1);
            list->width--;
        }
    }
    list->nprint += write(1, &c, 1);
}

void    is_char(t_struct *list, va_list ap)
{
    char c;

    c = (char)va_arg(ap, char *);
    if (list->minus == 0)
        left_print(c, list);
    else
        right_print(c, list);
}
