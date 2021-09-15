/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:29 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:40:18 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/fcntl.h>
# include <signal.h>

typedef enum
{
	SUM_PH = 0,
	T_DIE = 1,
	T_EAT = 2,
	T_SLEEP = 3,
	T_MST_E = 4,
}	t_indexs;

/*
** ERR_WRONG_ARGC: Wrong argument counts
** ERR_N_EN_PHILO: Not enough philosophers
** ERR_SEM_OPEN: Semaphore open error
** ERR_MALLOC_PHILO: Malloc philosophers error
** ERR_MALLOC_PROCESS: Malloc processes error
** ERR_THREAD_CREATE: Thread create error
** ERR_KILL_PHILO: There remain philosophers which should be killed
*/

# define OK 0
# define BELLY_FULL 1

# define ERR_WRONG_ARGC 1
# define ERR_N_EN_PHILO 2
# define ERR_SEM_OPEN 3
# define ERR_MALLOC_PHILO 4
# define ERR_MALLOC_PROCESS 5
# define ERR_THREAD_CREATE 6
# define ERR_KILL_PHILO 7

# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DEAD	"is dead\n"
# define TAKE_F	"has taken a fork\n"

typedef struct		s_info
{
	int				dead_phi;
	int				rules[5];
	sem_t			*forks;
	sem_t			*take;
	sem_t			*write;
	sem_t			*last_eat;
	sem_t			*end;
	sem_t			*start;
	sem_t			*must_eat;
	sem_t			*first;
}					t_info;

typedef struct		s_philo
{
	int				name;
	int				must_eat;
	ssize_t			curent_time;
	ssize_t			t_start;
	ssize_t			last_eat;
	pthread_t		th;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, t_info *info);
int					ft_atoi(const char *nptr);
int					philo_start(t_philo *philo,
					t_info *info, pid_t **processes);
void				life_cycle(t_philo *phi);
ssize_t				cur_time(void);
void				spend_time(int wait);
void				life_check(t_philo *phi);
void				dead_status(t_philo *phi);
void				print_dead(t_philo *phi, char *str, int n);
void				init_philo(t_philo *phi);
void				ft_putnbr_light(unsigned int n);
void				take_forks(t_philo *phi);
void				drop_forks(t_philo *phi);
int					philo_life(t_philo *phi);
void				print_log(t_philo *phi, char *str, int n);
void				sem_wrap_writing(t_philo *phi,
						char *str, int n, void f_write());
void				clear_space(int status, t_philo **phi, pid_t **processes);
void				semaphore_close(t_info *info);
void				semaphore_unlink(void);
#endif
