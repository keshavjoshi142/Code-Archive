#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

#define LIMIT 256 // max number of tokens for a command
#define MAXLINE 1024 // max number of characters from user input

void type_prompt()
{
	static int first_time = 1;
	if(first_time)
	{
		const char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
		write(STDOUT_FILENO , CLEAR_SCREEN_ANSI , 12);
		first_time = 0;
	}

	printf("#");
}



void pipeHandler(char * args[])
{
	int fd1[2];
	int fd2[2];
	int num_cmd = 0;

	char *command[256];

	pid_t pid;

	int end =0;
	int i=0;
	int j=0;
	int k=0;
	int l=0;

	while(args[l] != NULL)
	{
		if(strcmp(args[l] ,"|") == 0)
		{
			num_cmd++;
		}
		l++;
	}

	num_cmd++;


	while(args[j] != NULL && end !=1)
	{
						k = 0;

						while(strcmp(args[j] , "|")!=0)
						{

							printf("%s\n",args[j]);
							command[k] = args[j];
							j++;

							if(args[j] == NULL)/////////to break the loop when no command is found
							{
								end = 1;
								k++;
								break;
							}

							k++;
						}

						command[k] = NULL;
						j++;



						if( i&1 ){/////for odd i
							pipe(fd1);
						}
						else{
							pipe(fd2);////for even i
						}

						pid = fork();
						if(pid == -1)
						{
								if( i != num_cmd-1)
								{
										if( i&1 )
											close(fd1[1]);
										else
											close(fd2[1]);
								}

								printf("error");
								return;
						}
						if(pid == 0)
						{		

								if(i == 0)///////////////////first command can only write
								{
									dup2(fd2[1] , STDOUT_FILENO);
								}
								else if(i == num_cmd-1)///////////////for last command , change only read discriptor
								{
									if( num_cmd&1)
										dup2(fd1[0] , STDIN_FILENO);
									else
										dup2(fd2[0] , STDIN_FILENO);
								}
								else
								{
									if( i&2 )
									{
										dup2(fd2[0] , STDIN_FILENO);
										dup2(fd1[1] , STDOUT_FILENO);
									}
									else{
										dup2(fd1[0] , STDIN_FILENO);
										dup2(fd2[1] , STDOUT_FILENO);
									}
								}

						if(execvp(command[0] , command)==-1){
							kill(getpid() , SIGKILL);
						}

					}






	
					if(i ==0)
						close(fd2[1]);
					else if(i == num_cmd-1)
					{
						if(num_cmd&1)
							close(fd1[0]);
						else
							close(fd2[0]);
					}
					else{
						if(i&2)
						{
							close(fd2[0]);
							close(fd1[1]);
						}
						else{
							close(fd1[0]);
							close(fd2[1]);
						}
					}

					printf("kkkkkkkkkkkkkk\n");
					waitpid(pid , NULL , 0);

					i++;

	}
}





void fileIO(char *args[] , char * inputFile,  char* outputFile , int option)
{
	int fileDes;
	int pid;
	if((pid = fork())==-1)
		{
			printf("error");
			return;
		}
	if(pid ==0)
	{
		if(option == 0)//////////////////////////////////////////////output redirection
		{
			fileDes = open(outputFile ,O_CREAT | O_TRUNC | O_WRONLY, 0600);

			dup2(fileDes , STDOUT_FILENO);

			close(fileDes);
		}
		if(option == 1)
		{
			fileDes = open(inputFile , O_RDONLY , 0600);

			dup2(fileDes , 0);

			close(fileDes);
		}

		execvp(args[0] , args);
	}

	waitpid(pid , NULL ,0);



}

int Handlecommand(char * args[])
{	
	int i=0;
	int j=0;
	int k;////==aux
	int flag = 0;
	char * args2[256];

	while(args[j] != NULL)
	{	
	//printf("%s\n","kkkkkkkkkkkkk\n");
			if((strcmp(args[j] , ">") == 0) || (strcmp(args[j] ,"<")==0) || (strcmp(args[j] ,">>") == 0) || (strcmp(args[j] , "|")) == 0)
			{
				flag = 1;
				break;
			}

			args2[j] = args[j];

			j++;
	}

	if(strcmp(args[0] , "exit") == 0)exit(0);///////////////////////////// for exit command

	else if(flag == 0)//////////////////////////////////////////////////// use of fork and execve 
	{
		char *envp [] = {(char*) " PATH=/bin" , 0};
		char cmd[100];

		if(fork()!=0)
		{
				wait(NULL);
				printf("pid == %d\n", getpid());
		}
		else
		{
			strcpy(cmd , "/bin/");
			strcat(cmd , args[0]);
			//printf("this is %s\n", parameters[0]);
			execve(cmd , args , envp);
		}
	}
	else if(flag == 1)
	{	
		while(args[i] != NULL)
		{
			if(strcmp(args[i] , ">") == 0)
			{
				
				if(args[i+1] == NULL){
					printf("No output file");
					return -1;
				}

				printf("%s\n", "jjjjjjjjjjjj\n");
				fileIO(args2 , NULL , args[i+1] , 0);

			}

			if(strcmp(args[i] , "<") == 0)
			{
				if(args[i+1] == NULL){
					printf("No input file");
					return -1;
				}

				fileIO(args , args[i+1], NULL , 1);

			}
			if(strcmp(args[i],"|")==0)
			{
				pipeHandler(args);
				return 1;
			}

			i++;
		}
	}

}




void read_command(char cmd[] , char * par[])
{
	char line[MAXLINE];
	int count = 0;
	int j=0;
	int i=0;
	char * tokens[100];
	char *pch;
	int numTokens;
	memset(line , '\0' , MAXLINE);

	fgets(line ,MAXLINE , stdin);

	if((tokens[0] = strtok(line ," \n\t"))==NULL)return;

	numTokens = 1;

	while((tokens[numTokens] = strtok(NULL ," \n\t")) != NULL)numTokens++;

	// printf("%d\n", numTokens);
	// for(int i=0;i<numTokens;i++)
	// 	printf("kk%s\n",tokens[i]);

	Handlecommand(tokens);

}

int main()
{

	char cmd[100], command[100] , *parameters[20];

	char *envp [] = {(char*) " PATH=/bin" , 0};
	
	while(1)
	{
		type_prompt();


		read_command(command , parameters);
	}

	return 0;
}
