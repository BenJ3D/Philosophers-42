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

typedef enum
{
	STATE_EATING,
	STATE_SLEEP,
	STATE_FORK,
	STATE_THINK,
	STATE_DIED,
	STATE_OVER
}	e_state;

typedef enum
{
	NO_ERROR,
	ERROR_NB_ARGS,
	ERROR_MISSING_ARG,
	ERROR_IS_NOT_INT,
	ERROR_INT_MAXUP,
	ERROR_INT_MINDOWN,
	ERROR
}	e_error;

typedef enum
{
	FORK_NON_TAKEN,
	FORK_TAKEN
}	e_fork;

typedef enum	
{
	FALSE = 0,
	TRUE = 1
}	e_bool;

/****----------- struct lst -----------****/

typedef struct s_time_rules
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_philo_must_eat;
}				t_time_rules;

typedef struct	s_table
{
	void		*a;
}				t_table;


typedef struct s_philo
{
	pthread_t			tid;
	int					id;
	e_bool				is_died; //FIXME: 
	int					*rfork;
	int					lfork;
	pthread_mutex_t		lfork_mutex;
	e_fork				lfork_state;
	e_state				state_philo;
}				t_philo;

typedef struct s_data	
{
	int					i;
	int					number_of_philo;
	t_philo				*philo;
	t_philo				*current_philo; //FIXME:
	t_time_rules		time_rules;
	pthread_mutex_t		mtx_lock_message;
	e_error				error;
	struct timeval		current_time;
	unsigned long		start_sec;
	unsigned long		start_usec;

	pthread_t			tid[2048]; // FIXME

}				t_data;

typedef struct s_voyager
{
	t_data	*data;
	int		index_philo;
}				t_voyager;
/******-------------- philo prog --------------******/

int		parsing_check(t_data *data, int ac, char **argv);
int		print_pstate_change(e_state state, int pid, pthread_t tid,
	t_data *data);

/******------------ philo routines ------------******/

int	philo_taken_fork(t_data *data, int id);
int	philo_eating(t_data *data, int id);
int	philo_sleeping(t_data *data, int id);
int	philo_thinking(t_data *data, int id);
int	philo_died(t_data *data, int id);


/******-------------- tools libs --------------******/

int	ft_atoi_long(const char *src);
int	ft_isdigit(int c);
int	ft_putstr_fd(char *s, int fd);

/******----------- Error management -----------******/

int		check_is_valid_int(char *str, int i);
int		check_int_max_or_min(long long nb);
int		write_error_type(int error_type);

/******---------- clean exit function -----------******/

void	exit_clean(t_data	*data);

/******----------- debug functions ------------******/

void dbg_print_rules(t_data *data);



#endif