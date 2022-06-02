/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/02 19:12:10 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	int y;
	t_data *data;

	data = arg;
	y = 0;
	while (1)
	{
		
		break ;
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
		pthread_create(&data->philo[i].tid, NULL, philo_routine, data);
		i++;
		data->i++;
	}
	printf("data i = %i\n", data->i);
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
	printf("timestamp start = : %ld ms = %ld\n", data->current_time.tv_sec,\
	data->current_time.tv_usec);
	usleep(200);
	gettimeofday(&data->current_time, NULL);
	printf("timestamp start = : %ld ms = %ld\n", data->current_time.tv_sec,\
	data->current_time.tv_usec);
	usleep(200);
	gettimeofday(&data->current_time, NULL);
	printf("timestamp start = : %ld ms = %ld\n", data->current_time.tv_sec,\
	data->current_time.tv_usec);
	usleep(200);
	return (0);
}

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (!(data->philo = malloc(sizeof(t_philo) * data->number_of_philo + 1)))
		exit(EXIT_FAILURE);
	init_time(data);
	// pthread_mutex_init(&data->lock, NULL);
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