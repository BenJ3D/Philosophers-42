/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:01:39 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/30 14:48:59 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void dbg_print_rules(t_data *data)
{
	printf("Check parsing : \nnumber philo = %i\ntime to :\n- die = %i\n- eat =\
%i\n- sleep = %i\n\
- must eat = %i\n", \
	data->number_of_philo, data->time_rules.time_to_die, \
	data->time_rules.time_to_eat,\
	data->time_rules.time_to_sleep, data->time_rules.max_philo_must_eat);
}