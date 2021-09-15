/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 12:55:54 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		semaphore_unlink(void)
{
	sem_unlink("/forks");
	sem_unlink("/take");
	sem_unlink("/write");
	sem_unlink("/must_eat");
	sem_unlink("/last_eat");
	sem_unlink("/end");
	sem_unlink("/start");
	sem_unlink("/first");
}

static int	semaphore_init(t_info *info)
{
	info->dead_phi = 0;
	semaphore_unlink();
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	info->take = sem_open("/take", O_CREAT, S_IRWXU, 1);
	info->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	info->must_eat = sem_open("/must_eat", O_CREAT, S_IRWXU, 0);
	info->last_eat = sem_open("/last_eat", O_CREAT, S_IRWXU, 1);
	info->end = sem_open("/end", O_CREAT, S_IRWXU, 0);
	info->start = sem_open("/start", O_CREAT, S_IRWXU, 0);
	info->first = sem_open("/first", O_CREAT, S_IRWXU, 1);
	if (info->forks == SEM_FAILED || info->take == SEM_FAILED ||
		info->write == SEM_FAILED || info->must_eat == SEM_FAILED ||
		info->last_eat == SEM_FAILED || info->start == SEM_FAILED ||
		info->first == SEM_FAILED || info->end == SEM_FAILED)
		return (ERR_SEM_OPEN);
	return (OK);
}

static int	set_rules(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if ((info->rules[i] < 2 && i != T_MST_E) || info->rules[i] < 1)
		return (ERR_N_EN_PHILO);
	return (OK);
}

int			philo_pars(char **argv, t_info *info)
{
	int		i;
	int		status;

	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = set_rules(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if (semaphore_init(info))
	{
		semaphore_close(info);
		return (ERR_SEM_OPEN);
	}
	return (OK);
}
