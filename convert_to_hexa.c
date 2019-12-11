/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:45:36 by aes-salm          #+#    #+#             */
/*   Updated: 2019/12/10 14:46:19 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *convert_to_hexa(unsigned long decimal, char c)
{
    char tb[100];
    char *hexa;
    unsigned long res;
    int taille;
    int i;

    res = 0;
    taille = 87;
    i = 0;
    if (c == 'X')
        taille = 55;
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
    tb[i] = '\0';
    hexa = ft_strdup(tb);
    return (ft_strrev(hexa));
}
