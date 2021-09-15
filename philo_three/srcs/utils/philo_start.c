/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:34:51 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:54:25 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	start_life(t_info *info, int i)
{
	int		cnt;

	cnt = 0;
	if (i == info->rules[SUM_PH])
		while (cnt < i)
		{
			sem_post(info->start);
			cnt++;
		}
}

static int	wait_end(t_info *info, pid_t pid, pid_t *processes, int proc_cnt)
{
	int		cnt;

	cnt = 0;
	if (pid)
	{
		if (pid < 0)
			write(1, "Forks error\n", 10);
		else if (pid > 0)
			sem_wait(info->end);
		while (cnt < proc_cnt)
		{
			kill(processes[cnt], SIGKILL);
			cnt++;
		}
	}
	return (cnt);
}

int			philo_start(t_philo *phi, t_info *info, pid_t **processes)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		pid = fork();
		if (pid < 0)
			break ;
		if (pid)
			(*processes)[i] = pid;
		else
		{
			sem_wait(info->start);
			life_cycle(&phi[i]);
		}
		i++;
	}
	start_life(info, i);
	if (wait_end(info, pid, *processes, i) != i)
		return (ERR_KILL_PHILO);
	semaphore_close(info);
	return (OK);
}
