/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preg_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:18:57 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/16 15:20:14 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_preg_replace(char const *str, char c)
{
    int 	i;
    char 	*s;
    
    i = 0;
    s = ft_strdup(str);
    while (s[i] != '\0')
    {
        if (s[i] == '\t')
            s[i] = c;
        i++;
    }
    return (s);
}
