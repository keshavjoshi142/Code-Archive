#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

#define LIMIT 256 
#define MAXLINE 1024 

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



void pipeHandler(char * args[]){
	
	int fd[2]; 
	int fd2[2];
	
	int num_cmds = 0;
	
	char *command[256];
	
	pid_t pid;
	
	int err = -1;
	int end = 0;
	
	
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	
	while (args[l] != NULL)
	{
		
		if (strcmp(args[l],"|") == 0){
			num_cmds++;
		}
		l++;
	}
	num_cmds++;
	
	
	while (args[j] != NULL && end != 1){
		k = 0;
		
		while (strcmp(args[j],"|") != 0)
		{
			command[k] = args[j];
			

			j++;	
			if (args[j] == NULL){
				
				end = 1;
				k++;
				break;
			}
			k++;
		}

		command[k] = NULL;
		j++;		
		
		
		if (i % 2 != 0){
			pipe(fd); // for odd i
		}else{
			pipe(fd2); // for even i
		}
		
		pid=fork();
		//printf("%d\n" , pid);
		
		if(pid==-1){			
			if (i != num_cmds - 1){
				if (i % 2 != 0){
					close(fd[1]); // for odd i
				}else{
					close(fd2[1]); // for even i
				} 
			}			
			printf("Child process could not be created\n");
			return;
		}
		if(pid==0){
			// If we are in the first command
			if (i == 0){
				dup2(fd2[1], STDOUT_FILENO);
			}
	
			else if (i == num_cmds - 1){
				if (num_cmds % 2 != 0){ // for odd number of commands
					dup2(fd[0],STDIN_FILENO);
				}else{ // for even number of commands
					dup2(fd2[0],STDIN_FILENO);
				}
	
			}else{ 
				if (i % 2 != 0){
					dup2(fd2[0],STDIN_FILENO); 
					dup2(fd[1],STDOUT_FILENO);
				}else{ // for even i
					dup2(fd[0],STDIN_FILENO); 
					dup2(fd2[1],STDOUT_FILENO);					
				} 
			}
			
			if (execvp(command[0],command) ==err){
				kill(getpid(),SIGTERM);
			}		
		}
				
		
		if (i == 0){
			close(fd2[1]);
		}
		else if (i == num_cmds - 1){
			if (num_cmds % 2 != 0){					
				close(fd[0]);
			}else{					
				close(fd2[0]);
			}
		}else{
			if (i % 2 != 0){					
				close(fd2[0]);
				close(fd[1]);
			}else{					
				close(fd[0]);
				close(fd2[1]);
			}
		}
				
		waitpid(pid,NULL,0);
				
		i++;	
	}
}
		

void new_operator(char * args[])
{
	int fd[2];

	pid_t pid;
	int err = -1;
	char * command[256];

	command[0] = args[0];
	command[1] = args[1];
	command[2] = args[3];
	command[3] = args[4];
	command[4] = args[6];
	command[5] = args[7];


	int i=0;

	pipe(fd);

	pid = fork();

	while( i < 3)
	{
		if(pid == 0)
		{
			if(i==0)
			{
				dup2(fd[1] , STDOUT_FILENO);

				if(execvp(command[i], command)==err)
				{
					kill(getpid() , SIGTERM);
				}
			}
			else
			{
				dup2(fd[0] , STDIN_FILENO);

				if(execvp(command[0], command)==err)
				{
					kill(getpid() , SIGTERM);
				}
			}



		}

		if(i==0)
			close(fd[0]);
		else 
			close(fd[1]);

		waitpid(pid , NULL , 0);
		i++;
		
	}



}

int changeDirectory(char* args[]){
	
	if (args[1] == NULL) {
		chdir(getenv("HOME")); 
		return 1;
	}
	
	else{ 
		if (chdir(args[1]) == -1) {
			printf(" %s: no such directory\n", args[1]);
            return -1;
		}
	}
	return 0;
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
			if((strcmp(args[j] , ">") == 0) || (strcmp(args[j] ,"<")==0) || (strcmp(args[j] ,">>") == 0) || (strcmp(args[j] , "|")) ==0 ||(strcmp(args[j] , "||"))  == 0)
			{
				
				flag = 1;
				break;
			}

			args2[j] = args[j];

			j++;
	}

	
	if(strcmp(args[0] , "exit") == 0)exit(0);///////////////////////////// for exit command
	else if(strcmp (args[0] , "cd") == 0)changeDirectory(args);
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
			if(strcmp(args[i] ,"||")==0)
			{	
				
				new_operator(args);
				return 1;
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
