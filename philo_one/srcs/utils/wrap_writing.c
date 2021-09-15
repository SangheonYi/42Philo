/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:28:30 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:11:40 by hmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	mutex_wrap_writing(t_philo *phi, char *str, int n, void f_write())
{
	pthread_mutex_lock(&phi->info->write);
	f_write(phi, str, n);
	pthread_mutex_unlock(&phi->info->write);
}
