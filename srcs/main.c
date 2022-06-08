/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/08 16:31:37 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			index_philo;

	data = arg;
	index_philo = data->i;
	
	printf("routine start philo number :  %i\n", index_philo);
	while (1)
	{
		philo_eating(data, index_philo);
		philo_sleeping(data, index_philo);
		philo_thinking(data, index_philo);
	}
	// pthread_mutex_lock(&(data)->lock);
	// pthread_mutex_unlock(&(data)->lock);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;
	
	i = 0;
	data->i = 0;
	while(i < data->number_of_philo)
	{
		data->i = i + 1;
		pthread_create(&data->philos[i].tid, NULL, &philo_routine, data);
		i++;
		// data->i++;
		usleep(5); /////////////////////////////// INTERVAL BORN PHIL
	}
	//printf("data i = %i\n", data->i);
	while(1);
	while (data->i >= 0)
	{
		pthread_join(data->tid[data->i], NULL);
		data->i--;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i++].mtx_forks, NULL);
	i = 0;
	while (i < data->number_of_philo)
		data->forks[i++].availability = FORK_AVAILABLE;
	return (0);
}

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (!(data->philos = malloc(sizeof(t_philo) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	if (!(data->forks = malloc(sizeof(t_philo) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	init_time(data);
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