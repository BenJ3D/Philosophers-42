/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/28 20:06:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_is_valid_int(char *str, int i)
{
	if (ft_isdigit(str[i]) == 0)
		write_error_type(ERROR_IS_NOT_INT);
	i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write_error_type(ERROR_IS_NOT_INT);
			break ;
		}
		i++;
	}
	return (0);
}

int	check_int_max_or_min(long long nb)
{
	if (nb > INT_MAX)
		write_error_type(ERROR_INT_MAXUP);
	else if (nb < INT_MIN)
		write_error_type(ERROR_INT_MINDOWN);
	return (0);
}	
