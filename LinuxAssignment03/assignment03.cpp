/*
Name:	Bryan Chacha
Prof:	Mr.Lehuta
Clas:	CSCI 330 Linix and Net
Assg:	Assig03 - Creating the 
	    cat command using C++ 
*/

#include<iostream> 
#include<cstring> 
#include<fcntl.h> 
#include<iomanip> 
#include<unistd.h>
#include<stdlib.h>

using namespace std;


int main(int argc, char** argv ){

	//CREATING A FILE DESCRIPTOPR 
	int fd;

	char BUFFER [1000];

	// NUMBER OF BYTES TO READ
	ssize_t numread = 0;

//***************************************************************************
//***** CREATING A FOR LOOP THAT WILL OPEN ANY FILE IN YOU CURRENT **********
//***** DIRECTORY AND ALSO WILL PRINT ERROR IF THERE ISNT A FILE ************
//**************************************************************************

	for (int i = 1; i < argc; i++)
	{
	// SYSTEM CALL TO OPEN FILE
	fd = open(argv[i],O_RDONLY);


			if ( fd == -1 )
			{

			perror("cat: Error file or directory ");
			return 3;

			}	
			// IF USER PLACES " - " IT WILL
			// READ THE DATA FROM STANDARD OUTPUT

			else if (strcmp (argv[i], "-") == 0)
			{ 
				fd = STDIN_FILENO;
			}
				
				// READ THE FILE AND DISPLAY ON SHELL
				while((numread = read(fd, BUFFER, 1000)) > 0)
				{
					write (STDOUT_FILENO, BUFFER, numread);

				}

		// CLEAN AFTER MYSELF
		// AND CLOSING THE FILE
		close(fd);
	}


	return 0;
}




