#include "functii.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc, char **argv)
{
	char buffer[20];
	ssize_t nr;

	int fout;
	fout = open("total.dat", O_WRONLY | O_FSYNC| O_CREAT | O_TRUNC, S_IREAD | S_IWRITE | S_IRGRP);

	if( fout == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}


	int i;
	for(i=1; i<argc; i++)
	{
		int fd;
		fd = open(argv[i], O_RDONLY | O_FSYNC);

		if(fd<0)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}


		if((nr = read(fd, buffer, 20))>0)
		{
			write(fout, buffer, 20);
		}
		close(fd);
	}

	close(fout);
	return 0;
}
