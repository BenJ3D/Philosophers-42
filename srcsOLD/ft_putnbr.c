/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:35:51 by vvaltone          #+#    #+#             */
/*   Updated: 2022/06/22 18:36:19 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int ft_intlen(long long nb)
{
	long long i;
	long long res;
	int sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign++;
	}
	res = nb;
	if (res > 9)
	{
		res = nb / 10;
		i = ft_intlen(res);
	}
	i += 1 + sign;
	return (i);
}

long ft_putnbr(long n)
{
	char c;
	int len;

	len = ft_intlen((long long)n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	return (len);
}