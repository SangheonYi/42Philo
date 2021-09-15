/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:20:29 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 10:56:09 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum
{
	SUM_PH = 0,
	T_DIE = 1,
	T_EAT = 2,
	T_SLEEP = 3,
	T_MST_E = 4,
	LEFT = 0,
	RIGHT = 1
}	t_indexs;

/*
** ERR_N_EN_PHILO: Not enough philosophers
** ERR_WRONG_ARGC: Wrong argument counts
** ERR_MALLOC_FORK: Malloc fork error
** ERR_MUTEX_INIT: Mutex init error
** ERR_MALLOC_PHILO: Malloc philosophers error
** ERR_THREAD_CREATE: Thread create error
*/

# define OK 0
# define ERR_WRONG_ARGC 1
# define ERR_N_EN_PHILO 2
# define ERR_MALLOC_FORK 3
# define ERR_MUTEX_INIT 4
# define ERR_MALLOC_PHILO 5
# define ERR_THREAD_CREATE 6

# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DEAD	"is dead\n"
# define TAKE_F	"has taken a fork\n"

typedef struct		s_info
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	l_check;
	pthread_mutex_t	last_eat;
	pthread_t		monitor;
	int				dead_phi;
	int				rules[5];
}					t_info;

typedef struct		s_philo
{
	int				name;
	int				waf[2];
	int				must_eat;
	ssize_t			curent_time;
	ssize_t			t_start;
	ssize_t			last_eat;
	pthread_t		th;
	t_info			*info;
}					t_philo;

int					philo_pars(char **argv, t_info *info);
int					ft_atoi(const char *nptr);
int					thread_start(t_philo **philo, t_info *info);
void				life_cycle(t_philo *phi);
void				change_status(t_info *info);
ssize_t				cur_time(void);
void				spend_time(int wait);
void				life_check(t_philo **phi);
void				dead_status(t_philo *phi);
void				print_dead(t_philo *phi, char *str, int n);
void				ft_putnbr_light(unsigned int n);
void				take_forks(t_philo *phi);
void				drop_forks(t_philo *phi);
void				philo_life(t_philo *phi);
void				print_log(t_philo *phi, char *str, int n);
void				mutex_wrap_chng(t_philo *phi,
						pthread_mutex_t *type, void f_chng());
void				mutex_wrap_writing(t_philo *phi,
						char *str, int n, void f_write());
void				clear_space(t_info *info, t_philo **phi);
int					is_absent(t_philo *phi);
#endif
