/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/28 20:19:06 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philosophers.h"

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	printf("Check parsing : \nnumber philo = %i\ntime to :\n-die = %i\n-eat = %i\n-sleep = %i\n\
	must eat = %i\n", \
	data->number_of_philo, data->time_rules.time_to_die, data->time_rules.time_to_eat,\
	 data->time_rules.time_to_sleep, data->time_rules.max_philo_must_eat);
	return (0);
}

int main(int ac, char **argv)
{
	pthread_t id;
	t_data	data;
	
	if (ac >= 5 && ac < 7)
		run_philo(&data, ac, argv);
	else if (ac <= 7)
		printf("trop d'args\n");
	else
		printf("rentre des args ducon\n");
	return (0);
}