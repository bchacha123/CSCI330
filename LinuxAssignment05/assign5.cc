/*
 Brayan Chacha
 Course: CSCI Linux330
 Assi #:  Assignment05
 DUE: 3/16/20

PURPOSE: Using fork, pipe, and dup system calls. Giving an insight of 
	 input and output redirection

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	// Creating command1 & command2
	string command1, command2;
	
	// quit = exit program
	char quit[] = "quit";

	// User entering command #1
	cout << "command1? ";
	cin >> command1;

	// if "quit" is not typed in command line, user will enter command #2
	while (command1 != "quit", command2 != "quit")
	{
		// command #2 
		cout << "command2? ";
		cin >> command2;

		// Creating my pipe 
		int pipefd[2];
		int rs = pipe(pipefd);

		// If pipe fails
		if (rs == -1)
		{
			perror("Piping has fail!");
			// Exit the program 
			exit(EXIT_FAILURE);

		}

		// Creating my fork to 2 processes
		rs = fork();


		// If fork fails 
		if (rs == -1)
		{
			perror("Piping has fail");
			// Exit the program
			exit(EXIT_FAILURE);

		}

		//Once fork, child is created 
		if (rs == 0)
		{

			//  Always close the read end of the pipe
			//  to avoid ForkBomb, the write end will 
			//  be left open
			close(pipefd[0]);

			// Closing stdout
			close(1);

			//  Creating a duplicate (dup) to place into
			//  the write end of the pipe to stdout(1)
			dup(pipefd[1]);

			//  Closing the wight end of the pipe
			close(pipefd[1]);

			//  Command1 will be run using execlp
			rs = execlp(command1.c_str(), command1.c_str(), (char*)NULL);

			// If execlp fails display message to user
			if (rs == -1)
			{
				perror("Execlp has failed!");
				// Exit the program
				exit(EXIT_FAILURE);

			}


		}


		// This is the parent process
		else
		{
			// Closing write end of the pipe and leaving 
			// read open
			close(pipefd[1]);
			
			// Close stdout
			close(0);

			// Creating a duplicate (dup) to place into 
			// the read end of the pipe to stdin(0)
			dup(pipefd[0]);

			// Closing the read end of the pipe
			close(pipefd[0]);

			// Forking into 2 processes again
			rs = fork();

			// If fork() fails display message to user
			if (rs == 1)
			{
				perror("Parent fork has failed!");
				exit(EXIT_FAILURE);
			}


			// You are in child process #2
			// Here we will run command2 
			if (rs == 0)
			{
				//Running command2
				rs == execlp(command2.c_str(), command2.c_str(), (char*)NULL);

				// If execlp fails display message to user
				if (rs == -1)
				{
					perror("Child2 execlp has faild");
					exit(EXIT_FAILURE);
				}


			}


			// Inside the parent process
			else 
			{	
				wait(NULL);
				wait(NULL);
				break;
			}


		}


		cout << "command1? ";
		cin >> command1;
	}

	return 0;
}













