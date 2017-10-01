/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 12:15:19 by zgodongw          #+#    #+#             */
/*   Updated: 2017/06/24 12:44:38 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			set_conversion_array(char *array, int base)
{
	char			current;
	int				i;

	i = 0;
	current = '0';
	while (i < base && current <= '9')
	{
		array[i] = current;
		current++;
		i++;
	}
	current = 'A';
	while (i < base && current <= 'Z')
	{
		array[i] = current;
		current++;
		i++;
	}
	current = 'a';
	while (i < base && current <= 'z')
	{
		array[i] = current;
		current++;
		i++;
	}
}

static int			count_digits(uintmax_t number, int base)
{
	int				count;

	count = 0;
	while (number)
	{
		count++;
		number /= base;
	}
	return (count);
}

static void			write_chars(char *string, int base
								, char conversion[base], uintmax_t number)
{
	while (number)
	{
		*string = conversion[number % base];
		number /= base;
		string--;
	}
}

char				*ft_basetoa(uintmax_t number, int base)
{
	char	*new;
	char	conversion[base];
	int		length;

	if (base > ('9' - '0') + ('Z' - 'A') + ('z' - 'a'))
		return (ft_strdup("BASE_TOO_BIG"));
	if (number == 0)
		return (ft_strdup("0"));
	set_conversion_array(conversion, base);
	length = count_digits(number, base);
	new = ft_strnew(length);
	write_chars(new + length - 1, base, conversion, number);
	return (new);
}
