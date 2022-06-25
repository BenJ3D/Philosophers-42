/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:20:54 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/25 21:52:02 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/****------------ enum ------------****/

typedef enum e_state
{
	STATE_EATING,
	STATE_SLEEP,
	STATE_FORK,
	STATE_THINK,
	STATE_DIED,
	STATE_OVER
}	t_state;

typedef enum e_error
{
	NO_ERROR,
	ERROR_NB_ARGS,
	ERROR_MISSING_ARG,
	ERROR_IS_NOT_INT,
	ERROR_INT_MAXUP,
	ERROR_INT_MINDOWN,
	ERROR_MAX_PHILOS,
	ERROR
}	t_error;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/****----------- struct lst -----------****/

typedef struct s_time_rules
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_philo_must_eat;
	t_bool		ate_max_imposed;
}				t_time_rules;

typedef struct s_fork
{
	pthread_mutex_t		mtx_forks;
}				t_fork;
typedef struct s_philo
{
	pthread_t			tid;
	int					id;
	t_bool				is_died;
	t_state				state_philo;
	int					ate_nb;
	t_bool				ate_max;
	long				last_ate;
}				t_philo;
typedef struct s_monitor
{
	long				*time_control;
	pthread_t			tid;
}			t_monitor;

typedef struct s_data
{
	int					id_philo;
	int					number_of_philo;
	t_philo				*philos;
	t_fork				*forks;
	t_time_rules		time_rules;
	pthread_mutex_t		mtx_lock_message;
	pthread_mutex_t		mtx_lock_gettime;
	t_bool				somebody_is_dead;
	t_error				error;
	struct timeval		current_time;
	long				start_time;
	t_monitor			monitor;
	pthread_t			*tid;
}				t_data;

/******-------------- philo prog --------------******/

int				parsing_check(t_data *data, int ac, char **argv);
int				print_message(t_state state, int pid, pthread_t tid,
					t_data *data);
int				init_philo(t_data *data);
void			*philo_routine(void *arg);
int				init_forks(t_data *data);
int				init_monitoring(t_data *data);
int				run_philo(t_data *data, int ac, char **argv);
int				check_last_ate(t_data data, int id);
int				exit_clean(t_data *data);

/******-------------- time function --------------******/

int				time_init(t_data *data);
void			time_print(t_data *data);
long			time_get(t_data	*data);

/******------------ philo routines ------------******/

int				philo_taken_fork(t_data *data, int id);
int				philo_eating(t_data *data, int id);
int				philo_sleeping(t_data *data, int id);
int				philo_thinking(t_data *data, int id);
int				philo_died(t_data *data, int id);
long			philo_check_is_died(t_data *data, int id);

/******-------------- tools libs --------------******/

int				ft_atoi_long(const char *src);
int				ft_isdigit(int c);
int				ft_putstr_fd(char *s, int fd);

/******----------- Error management -----------******/

int				check_is_valid_int(char *str, int i);
int				check_int_max_or_min(long long nb);
int				write_error_type(int error_type);

/******---------- clean exit function -----------******/

int				exit_clean(t_data *data);

/******----------- debug functions ------------******/

void			dbg_print_rules(t_data *data);
void			time_print_dbg(t_data *data);
long			ft_putnbr(long n);

#endif