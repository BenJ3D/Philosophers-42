
//TODO: maybe add *lfork et *rfork avec ladresse des forks pour simplifier 
/**
 * @brief 
 * 
 * @param data 
 * @param id index philo
 * @return int 
 */
int	last_philo_eating(t_data *data, int id)
{
	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
	data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
	if (print_pstate_change(STATE_FORK, id, data->philos->tid, data, id - 1))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&data->forks[0].mtx_forks);
	data->forks[id].availability = FORK_NOT_AVAILABLE;
	if (print_pstate_change(STATE_FORK, id, data->philos->tid, data, 0))
		return (EXIT_FAILURE);
	data->philos[id - 1].last_ate = time_get(data); // ET ICIIIIIIIIIIIIIIIIIIII
	if (print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0))
		return (EXIT_FAILURE);
	usleep(data->time_rules.time_to_eat);
	data->forks[0].availability = FORK_AVAILABLE;
	data->forks[id - 1].availability = FORK_AVAILABLE;
	pthread_mutex_unlock(&data->forks[0].mtx_forks);
	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
	if (data->time_rules.ate_max_imposed == TRUE)
		data->philos[id - 1].ate_nb++;
	return(0);
}

// void print_last_eat(t_data *data,  )

int	philo_eating(t_data *data, int id)
{
	long	res_last_ate;
	
	res_last_ate = ((data->philos[id - 1].last_ate - time_get(data)) * -1);
	pthread_mutex_lock(&data->mtx_lock_message);
	//res_last_ate = ((data->philos[id - 1].last_ate - time_get(data)) * -1);
	printf("%03i res last ate = %li\n", id, res_last_ate);
	pthread_mutex_unlock(&data->mtx_lock_message);
	if (data->somebody_is_dead == TRUE)
		return (EXIT_FAILURE);
	if ((res_last_ate * 1000) > data->time_rules.time_to_die)
	{
		pthread_mutex_lock(&data->mtx_lock_message);
		//printf("\033[31mIL EST MORT 1!!!!!!!!!!!!!!!!!!!!!!\033[0m\n");
		printf("\033[31m%03i is died (msg_philo:39)\033[0m\n", id);
		// print_pstate_change(STATE_DIED, id, data->philos->tid, data, 0);
		data->somebody_is_dead = TRUE;
		pthread_mutex_unlock(&data->mtx_lock_message);
		// exit_clean(data);
		return (EXIT_FAILURE);  
	}
	if (id == data->number_of_philo)
	{
		if (last_philo_eating(data, id))
			return (EXIT_FAILURE);
	}
	else
	{
		pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
		data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
		if (print_pstate_change(STATE_FORK, id, data->philos->tid, data, id - 1))
			return (EXIT_FAILURE);
		pthread_mutex_lock(&data->forks[id].mtx_forks);
		data->forks[id].availability = FORK_NOT_AVAILABLE;
		if (print_pstate_change(STATE_FORK, id, data->philos->tid, data, id))
			return (EXIT_FAILURE);
		data->philos[id - 1].last_ate = time_get(data); // ET ICIIIIIIIIIIIIIIII
		if (print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0))
			return (EXIT_FAILURE);
		usleep(data->time_rules.time_to_eat);
		data->forks[id - 1].availability = FORK_AVAILABLE;
		data->forks[id].availability = FORK_AVAILABLE;
		pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
		pthread_mutex_unlock(&data->forks[id].mtx_forks);
		if (data->time_rules.ate_max_imposed == TRUE)
			data->philos[id - 1].ate_nb++;
	}
	// if (data->somebody_is_dead == TRUE)
	// {
	// 	pthread_mutex_destroy(&data->mtx_lock_message);
	// }
	return (0);
}