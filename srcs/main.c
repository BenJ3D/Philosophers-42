#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "../includes/philosophers.h"

// Global variable:
int i = 4;

void *foo(t_data *p)
{
	// Print value received as argument:
	printf("Value recevied as argument in starting routine: ");
	printf("%i\n", (p)->i);

	// Return reference to global variable:
	pthread_exit(&i);
}

int main(void)
{
	// Declare variable for thread's ID:
	pthread_t id;
	t_data	*data;

	int j = 1;
	data->i = 42;
	pthread_create(&id, NULL, foo, (t_data *)data);

	int *ptr;

	// Wait for foo() and retrieve value in ptr;
	pthread_join(id, (void **)&ptr);
	printf("Value recevied by parent from child: ");
	printf("%i\n", *ptr);
}