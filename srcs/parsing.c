/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/28 20:20:42 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	parsing_check(t_data *data, int ac, char **argv)
{
	data->number_of_philo = ft_atoi_long(argv[1]);
	data->time_rules.time_to_die = ft_atoi_long(argv[2]);
	data->time_rules.time_to_eat = ft_atoi_long(argv[3]);
	data->time_rules.time_to_sleep = ft_atoi_long(argv[4]);
	if (ac == 6)
		data->time_rules.max_philo_must_eat = ft_atoi_long(argv[5]);
	else
		data->time_rules.max_philo_must_eat = 0;
	return (0);
}