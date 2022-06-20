/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/20 14:43:24 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_last_ate(t_data data, int id)
{

	return (0);
}

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			index_philo;

	data = arg;
	index_philo = data->id_philo;
	while (1)
	{
		if (data->somebody_is_dead == TRUE)
			break ;
		if (philo_eating(data, index_philo) == EXIT_FAILURE)
			break ;
		if (data->time_rules.ate_max_imposed == TRUE \
		&& data->philos[index_philo - 1].ate_nb \
		== data->philos[index_philo - 1].ate_max)
			break ;
		if (data->somebody_is_dead == FALSE)
			philo_sleeping(data, index_philo);
		if (data->somebody_is_dead == TRUE)
			break ;
		philo_thinking(data, index_philo);
	}
	///////////////////////////////// DBG TEST /////////////////////////////////
	// int i = 0;															  //
	// while (i != 5)														  //
	// {																	  //
	// 	pthread_mutex_lock(&data->mtx_lock_message);						  //
	// 	printf("bonjour je suis philo %i\n", index_philo);					  //
	// 	pthread_mutex_unlock(&data->mtx_lock_message);						  //
	// 	// if (index_philo == 4)											  //
	// 	// 	usleep(800000);													  //
	// 	usleep(200000);														  //
	// 	i++;																  //
	// }																	  //
	//if ("PAS UN MORT")													  //
	// pthread_mutex_unlock(&data->mtx_somebody_is_dead);					  //
	////////////////////////////////////////////////////////////////////////////
	printf("\033[31mphilo %i finish, max eat is : %i\033[0m\n", index_philo, data->philos[index_philo - 1].ate_max);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->id_philo = 0;
	while(i < data->number_of_philo)
	{
		data->id_philo++;
		if(pthread_create(&data->philos[i].tid, NULL, &philo_routine, data))
			return (EXIT_FAILURE);
		data->philos[i].is_died = FALSE;
		data->philos[i].ate_nb = 0;
		data->philos[i].last_ate = time_get(data);
		if (data->time_rules.ate_max_imposed == TRUE)
			data->philos[i].ate_max = data->time_rules.max_philo_must_eat;
		pthread_mutex_lock(&data->mtx_lock_message);
		if (DBG_PRINT == 1)
			printf("\033[31mDBG init philo i = %i\n\t ate nb = %i\n\033[37m", i, data->philos[i].ate_nb);
		pthread_mutex_unlock(&data->mtx_lock_message);
		i++;
		usleep(7); /////////////////////////////// INTERVAL BORN PHILO
	}
	while (data->id_philo > 0)
	{
		pthread_join(data->philos[data->id_philo - 1].tid, NULL);
		data->id_philo--;
	}
	// while (data->id_philo > 0)
	// {
	// 	pthread_detach(data->philos[data->id_philo - 1].tid);
	// 	data->id_philo--;
	// }
	// pthread_mutex_lock(&data->mtx_somebody_is_dead);
	// pthread_mutex_unlock(&data->mtx_somebody_is_dead);
	printf("COUCOU DE philo.c:102 (prog bien terminé)\n");
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
	if (ac == 6 && (ft_atoi_long(argv[5]) > 0))
		data->time_rules.ate_max_imposed = TRUE;
	else
		data->time_rules.ate_max_imposed = FALSE;
	if (!(data->philos = malloc(sizeof(t_philo) * data->number_of_philo)))
		return (EXIT_FAILURE);
	if (!(data->forks = malloc(sizeof(t_fork) * data->number_of_philo)))
		return (EXIT_FAILURE);
	time_init(data);
	pthread_mutex_init(&data->mtx_lock_message, NULL);
	// pthread_mutex_init(&data->mtx_somebody_is_dead, NULL);
	init_forks(data);
	data->somebody_is_dead = FALSE;
	init_philo(data);
	return (0);
}