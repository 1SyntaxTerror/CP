#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "functii.h"


int main(int argc, char** argv)
{

	int fout;
	unsigned char buffer[20];
	int nr;

	char nume[30];
	printf("\nNume fisier nou: ");
	scanf("%s", nume);

	fout = open(nume, O_RDWR | O_CREAT | O_TRUNC | O_FSYNC, S_IREAD | S_IWRITE | S_IRGRP);

	if( fout == -1 )
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}

	int i;
	for(i = 0; i<argc; i++)
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
			write(fout, buffer, nr);
		}

		close(fd);

	}

	close (fout);
	return 0;

}
