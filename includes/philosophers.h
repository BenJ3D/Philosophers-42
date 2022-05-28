#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>
# include  <sys/time.h>

/****------------ enum ------------****/

enum	e_stat
{
	EATING,
	SLEEP,
	FORK,
	THINK,
	DIED,
	OVER
};

enum	e_error
{
	NO_ERROR,
	ERROR_NB_ARGS,
	ERROR_IS_NOT_INT,
	ERROR_INT_MAXUP,
	ERROR_INT_MINDOWN,
	ERROR
};

enum	e_bool
{
	FALSE = 0,
	TRUE = 1
};

/****----------- struct lst -----------****/

typedef struct s_time_rules
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_philo_must_eat;
}			t_time_rules;

typedef struct	s_table
{
	void	*a;
}				t_table;


typedef struct s_philo
{
	pthread_t			tid;
	int					id;
	enum e_bool			is_eating;

}				t_philo;

typedef struct s_data
{
	int					i;
	t_philo				*philo;
	int					number_of_philo;
	t_time_rules		time_rules;
	pthread_mutex_t		lock;
	enum e_error		error;


	pthread_t			tid[1024]; // FIXME

}				t_data;

/******-------------- philo prog --------------******/

int		parsing_check(t_data *data, int ac, char **argv);


/******-------------- tools libs --------------******/

int	ft_atoi_long(const char *src);
int	ft_isdigit(int c);
int	ft_putstr_fd(char *s, int fd);

/******-------------- Error management --------------******/

int		check_is_valid_int(char *str, int i);
int		check_int_max_or_min(long long nb);
int		write_error_type(int error_type);

#endif