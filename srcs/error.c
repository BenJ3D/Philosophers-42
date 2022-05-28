/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/28 20:00:19 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief printf error type in stderror
 * 
 * @param data 
 * @param error_type 
 * @return int 
 */
int	write_error_type(int error_type)
{
	if (error_type == ERROR_IS_NOT_INT)
		ft_putstr_fd("Error\nno int detected", 2);
	else if (error_type == ERROR_NB_ARGS)
		ft_putstr_fd("Error\nrequired arguments missing", 2);
	else if (error_type == ERROR_INT_MAXUP || error_type == ERROR_INT_MINDOWN)
		ft_putstr_fd("Error\nPlease do not exceed int_max and int_min", 2);
	else if (error_type == ERROR_NB_ARGS)
		ft_putstr_fd("Error\nrequired arguments missing", 2);
	else if (error_type != NO_ERROR)
		ft_putstr_fd("Please enter in ms :\n\
		(int)number_of_philosophers\n\
		(int)time_to_die\n \
		(int)time_to_eat\n \
		(int)time_to_sleep\n \
		(int)[number_of_times_each_philosopher_must_eat](optional)", 2);
	if (error_type != NO_ERROR)
		exit(-1);
	return (0);
}