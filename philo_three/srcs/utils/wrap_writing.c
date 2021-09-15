/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:28:30 by hmin              #+#    #+#             */
/*   Updated: 2021/02/25 13:45:01 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	sem_wrap_writing(t_philo *phi, char *str, int n, void f_write())
{
	sem_wait(phi->info->write);
	f_write(phi, str, n);
	sem_post(phi->info->write);
}
