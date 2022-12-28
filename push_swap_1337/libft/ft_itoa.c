/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaaitat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:03:17 by imaaitat          #+#    #+#             */
/*   Updated: 2022/10/20 17:59:58 by imaaitat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numberof_n(long int n)
{
	long	dig;

	dig = 1;
	while (n >= 10)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

char	*ft_itoa(int n)
{
	long		a;
	int			len;
	char		*res;
	int			i;

	a = n;
	if (n < 0)
		a *= -1;
	len = numberof_n(a);
	if (n < 0)
		len ++;
	res = malloc(len + 1);
	if (res == 0)
		return (0);
	res[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		res[i] = (a % 10) + '0';
		a /= 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
