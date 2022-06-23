/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/23 16:34:16 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			index_philo;

	data = arg;
	index_philo = data->id_philo;
	data->philos[index_philo - 1].id = index_philo;
	while (1)
	{
		if (data->somebody_is_dead == TRUE)
			break ;
		philo_eating(data, index_philo);
		if (data->time_rules.ate_max_imposed == TRUE \
		&& data->philos[index_philo - 1].ate_nb \
		== data->philos[index_philo - 1].ate_max)
			break ;
		if (data->somebody_is_dead == FALSE)
		philo_sleeping(data, index_philo);
		philo_thinking(data, index_philo);
	}
	print_message(STATE_OVER, index_philo, data->philos[index_philo - 1].tid, \
		data, 0);
	// printf("\033[31mphilo %i finish, max eat is : %i\033[0m\n", index_philo, data->philos[index_philo - 1].ate_max);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->id_philo = 0;
	while(i < data->number_of_philo - 1)
	{
		data->id_philo++;
		if(pthread_create(&data->philos[i].tid, NULL, &philo_routine, data))
			return (EXIT_FAILURE);
		data->philos[i].is_died = FALSE;
		data->philos[i].ate_nb = 0;
		// data->philos[i].last_ate = time_get(data);
		data->philos[i].id = data->id_philo;
		if (data->time_rules.ate_max_imposed == TRUE)
			data->philos[i].ate_max = data->time_rules.max_philo_must_eat;
		i++;
		usleep(10); /////////////////////////////// INTERVAL BORN PHILO
	}
	while (data->id_philo > 0)
	{
		pthread_join(data->philos[data->id_philo - 1].tid, NULL);
		data->id_philo--;
	}
	printf("COUCOU DE philo.c:102 (prog bien terminé)\n");
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo - 1)
		pthread_mutex_init(&data->forks[i++].mtx_forks, NULL);
	i = 0;
	return (0);
}

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (ac == 6 && (ft_atoi_long(argv[5]) > 0))
		data->time_rules.ate_max_imposed = TRUE;
	else
		data->time_rules.ate_max_imposed = FALSE;
	if (!(data->philos = (t_philo*)malloc(sizeof(t_philo) * data->number_of_philo)))
		return (EXIT_FAILURE);
	if (!(data->forks = (t_fork*)malloc(sizeof(t_fork) * data->number_of_philo)))
		return (EXIT_FAILURE);
	time_init(data); // FIXME:
	pthread_mutex_init(&data->mtx_lock_message, NULL);
	// pthread_mutex_init(&data->mtx_somebody_is_dead, NULL);
	init_forks(data);
	data->somebody_is_dead = FALSE;
	init_monitoring(data);
	init_philo(data);
	return (0);
}