#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


void Scrie(int fisier, char *text)
{
	write(fisier, text, strlen(text));
}

void ScrieFisierMake(int fisier, char *M, char *m)
{
	char buffer[400];
	int len = snprintf(buffer, sizeof(buffer), 
	"%s:%s.o %s.o\n\t"
	"clang -Wall %s.o %s.o -o %s\n\n"
	"%s.o:%s.c %s.h\n\t"
	"clang -c -Wall %s.c %s.o\n\n"
	"%s.o:%s.c %s.h\n\t"
	"clang -c -Wall %s.c %s.o\n\n"
	".PHONY:clean\nclean:\n\t"
	"rm %s\n\t"
	"rm -f *.o",
   	M, M, m,
   	M, m, M,
	M, M, m,
	M, m,
	m, m, m,
	m, m,
	M
	);
	printf("\n%s", buffer);
	Scrie(fisier, buffer);

}



int main(int argc, char** argv)
{

	if(argc == 1)
	{
		printf("\nAi accesat optiunea de ajutor pentru ca nu ai specificat niciun argument!\nForma acceptata: ./main -M nume_main -m nume_modul\n");
		
	}

	char* nume_main;
	char* nume_modul;
	int i = 0;
	
	for(i = 1; i<argc; i++)
	{
		if(strcmp(argv[i], "-h")==0)
		{
			printf("Ai accesat optiunea de ajutor!\nForma acceptata: ./main -M nume_main -m nume_modul\n");
			exit(0);
		}
	}


	
	for(i = 1; i<argc; i++)
	{

		if(strcmp(argv[i], "-m")==0)
		{	
			if(i<argc)
			{
				nume_modul = (char*)malloc(strlen(argv[i+1]) * sizeof(char));
				strcpy(nume_modul, argv[i+1]);
				printf("\nNume modul: %s", nume_modul); 
			}
		}
		else if(strcmp(argv[i], "-M")==0)
		{	
			if(i<argc)
			{
				nume_main = (char*)malloc(strlen(argv[i+1]) * sizeof(char));
				strcpy(nume_main, argv[i+1]);
				printf("\nNume modul: %s", nume_main); 
			}
		}
	}

	char *nume_fisier = 0;
	nume_fisier = (char*) malloc ((strlen(nume_main)+3) * sizeof(char));//Am adaugat 3 pentru extensia .mk
	
	if(nume_fisier == 0)
	{
		fprintf(stderr, "Eroare la alocarea de memorie a nume_fisier");
		exit(EXIT_FAILURE);
	}

	strcpy(nume_fisier, nume_main);
	strcat(nume_fisier, ".mk");


	int fd = open(nume_fisier, O_RDWR | O_FSYNC | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE | S_IRGRP | 0666);
	{
		if (fd == -1)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	


	ScrieFisierMake(fd, nume_main, nume_modul);

	close(fd);	



	return 0;

}
//TASKURI RAMASE:

//Fa DEALOCARILE DE MEMORIE

