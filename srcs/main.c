/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/10 16:12:50 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (ac == 6)
		data->time_rules.ate_max_imposed = TRUE;
	else
		data->time_rules.ate_max_imposed = FALSE;
	if (!(data->philos = malloc(sizeof(t_philo) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	if (!(data->forks = malloc(sizeof(t_fork) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	time_init(data);
	pthread_mutex_init(&data->mtx_lock_message, NULL);
	init_forks(data);
	init_philo(data);
	return (0);
}

int main(int ac, char **argv)
{
	pthread_t id;
	t_data	data;
	
	//printf("arg ac = %i\n", ac);
	if (ac >= 5 && ac <= 6)
		run_philo(&data, ac, argv);
	else if (ac > 6)
		write_error_type(ERROR_NB_ARGS);
	else
		write_error_type(ERROR_MISSING_ARG);
	free(data.philos);
	return (0);
}