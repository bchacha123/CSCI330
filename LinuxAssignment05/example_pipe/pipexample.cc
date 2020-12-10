/*
 
Purpose: UNDERSTANDING PIPE AND CREATING ONE 

Dont forge to include the header 
	#include <unistd.h>

	int pipe(int pipefd[2]);

	read side pipe[0]

	write side pipe[1]


*/   

#include <iostream>
#include <unistd.h>

using namespace std;

int main(){

	cout << "Before pipe\n";

	// Declaring my pipe
	int pipefd[2], rs;
	// Creating my buffer
	char buffer[256];


	// piping 
	rs = pipe(pipefd);
	if (rs < 0 )
	{
		perror("error pipe");
		exit(EXIT_FAILURE);
	}
	
	// writing = pipe[1]
	write(pipefd[1], "Hello", 6);

	read(pipefd[0], buffer, sizeof(buffer));

	cout << "Pipe contained: " << buffer << endl;


	return 0;
}




