/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/03 16:01:15 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	int			y;
	t_data		*data;
	t_philo		*current;

	data = arg;
	current = data->current_philo;
	y = 0;
	while (1)
	{
		philo_eating(data);
		philo_sleeping(data);
		philo_thinking(data);
	}
	// pthread_mutex_lock(&(data)->lock);
	// pthread_mutex_unlock(&(data)->lock);
	return (0);
}

int	ini_philo(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	data->i = 0;
	while(i < data->number_of_philo)
	{
		data->philo->id = y ++;
		data->current_philo = &data->philo[i]; //FIXME
		pthread_create(&data->philo[i].tid, NULL, philo_routine, data);
		i++;
		data->i++;
		usleep(5); /////////////////////////////// INTERVAL BORN PHIL
	}
	printf("data i = %i\n", data->i);
	while(1);
	while (data->i >= 0)
	{
		pthread_join(data->tid[data->i], NULL);
		data->i--;
	}
	return (0);
}

int	init_time(t_data *data)
{
	gettimeofday(&data->current_time, NULL);
	data->start_sec = data->current_time.tv_sec;
	data->start_usec = data->current_time.tv_usec;
	gettimeofday(&data->current_time, NULL);
	printf("timestamp start = : %04ld ms = %03ld\n", data->current_time.tv_sec % 1000,\
	data->current_time.tv_usec / 1000);
	usleep(150000);
	gettimeofday(&data->current_time, NULL);
	printf("timestamp start = : %04ld ms = %03ld\n", data->current_time.tv_sec % 1000,\
	data->current_time.tv_usec / 1000);

	usleep(150000);
	gettimeofday(&data->current_time, NULL);
	printf("timestamp start = : %04ld ms = %03ld\n", data->current_time.tv_sec % 1000,\
	data->current_time.tv_usec / 1000);
	usleep(150000);
	return (0);
}

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (!(data->philo = malloc(sizeof(t_philo) * data->number_of_philo + 1)))
		exit(EXIT_FAILURE);
	init_time(data);
	pthread_mutex_init(&data->mtx_lock_message, NULL);
	ini_philo(data);
	return (0);
}

int main(int ac, char **argv)
{
	pthread_t id;
	t_data	data;
	
	printf("arg ac = %i\n", ac);
	if (ac >= 5 && ac <= 6)
		run_philo(&data, ac, argv);
	else if (ac > 6)
		write_error_type(ERROR_NB_ARGS);
	else
		write_error_type(ERROR_MISSING_ARG);
	free(data.philo);
	return (0);
}