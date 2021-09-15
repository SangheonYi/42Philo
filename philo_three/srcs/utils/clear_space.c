/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:33:14 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:40:18 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	semaphore_close(t_info *info)
{
	if (info->forks != SEM_FAILED)
		sem_close(info->forks);
	if (info->take != SEM_FAILED)
		sem_close(info->take);
	if (info->write != SEM_FAILED)
		sem_close(info->write);
	if (info->must_eat != SEM_FAILED)
		sem_close(info->must_eat);
	if (info->last_eat != SEM_FAILED)
		sem_close(info->last_eat);
	if (info->end != SEM_FAILED)
		sem_close(info->end);
	if (info->start != SEM_FAILED)
		sem_close(info->start);
	if (info->first != SEM_FAILED)
		sem_close(info->first);
	semaphore_unlink();
}

void	clear_space(int status, t_philo **phi, pid_t **processes)
{
	if (status == 1 || status == 2 || status == 3)
		return ;
	if (status >= 4 || !status)
		free(*phi);
	if (status >= 5 || !status)
		free(*processes);
}
