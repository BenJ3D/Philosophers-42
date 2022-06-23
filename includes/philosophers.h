#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_THREAD 2048
# define DBG_PRINT 0

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
	FORK_NOT_AVAILABLE,
	FORK_AVAILABLE
}	e_fork;

typedef enum	
{
	FALSE = 0,
	TRUE = 1
}	e_bool;

/****----------- struct lst -----------****/

typedef struct s_time_rules
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			max_philo_must_eat;
	e_bool		ate_max_imposed;
}				t_time_rules;			t_debug_mod;

typedef struct s_fork
{
	pthread_mutex_t		mtx_forks;
}				t_fork;
typedef struct s_philo
{
	pthread_t			tid;
	int					id;
	e_state				state_philo;
	int					ate_nb;
	long				last_ate;
}				t_philo;
typedef struct s_monitor
{
	long				*time_control;
	pthread_t			tid;
}			t_monitor;

typedef struct s_data	
{
	int					number_of_philo;
	t_philo				*philos;
	t_fork				*forks;
	t_time_rules		rules;
	pthread_mutex_t		mtx_lock_message;
	e_bool				somebody_is_dead;
	e_error				error;
	struct timeval		current_time;
	long				start_time;
	t_monitor			monitor;

}				t_data;

/******-------------- philo prog --------------******/







/******-------------- OLD --------------******/
/******-------------- OLD --------------******/
/******-------------- OLD --------------******/
/******-------------- philo prog --------------******/

int				parsing_check(t_data *data, int ac, char **argv);
int				print_message(e_state state, int pid, pthread_t tid,
					t_data *data, int dbgidfork);
int				init_philo(t_data *data);
void			*philo_routine(void *arg);
int				init_forks(t_data *data);
int				init_monitoring(t_data *data);
int				run_philo(t_data *data, int ac, char **argv);
int				check_last_ate(t_data data, int id);
int				exit_clean(t_data *data);


// int		print_pstate_change(e_state state, int pid, pthread_t tid,
// 	t_data *data);


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



#endif