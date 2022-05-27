#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <pthread.h>
#include  <sys/time.h>

/****------------ enum ------------****/
enum e_error
{
	NO_ERROR,
	ERROR
};

/****----------- struct lst -----------****/

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

typedef struct s_data
{
	int					i;
	pthread_t			tid[1024];
	pthread_mutex_t		lock;


}				t_data;


#endif