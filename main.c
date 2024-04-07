/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:33:17 by arnaud            #+#    #+#             */
/*   Updated: 2024/04/07 13:11:57 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int	fd_test;
	int	fd_file;
	int	fd_empty;

	fd_test = open("./test.txt", O_RDONLY);
	fd_file = open("./file", O_RDONLY);
	fd_empty = open("./empty.txt", O_RDONLY);
	printf("[%s]\n", get_next_line(fd_test));
	// printf("[%s]\n", get_next_line(fd_file));
	printf("[%s]\n", get_next_line(fd_test));
	printf("[%s]\n", get_next_line(fd_test));
	printf("[%s]\n", get_next_line(fd_test));
	printf("[%s]\n", get_next_line(fd_test));
	// printf("[%s]\n", get_next_line(fd_file));
	// printf("%s", get_next_line(fd_test));
	// printf("%s", get_next_line(fd_file));
	// printf("%s", get_next_line(fd_test));
	// printf("%s", get_next_line(fd_file));
	// printf("%s", get_next_line(fd_test));
	// printf("[%s]", get_next_line(fd_empty));
	// printf("[%s]", get_next_line(fd_empty));
	// printf("[%s]", get_next_line(fd_empty));
	close(fd_test);
	close(fd_file);
	close(fd_empty);
}
