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
#include "assignment04h.h"


using namespace std;


int main(int argc, char** argv ){


	//CREATING SWITCHES FOR THE WHILE/GETOPT LOOP
	bool chan_size = false;
	bool chan_byte = false;
	bool encry     = false;
	bool shift     = false;
	bool hex       = false;
	bool binary    = false;

	// CREATING AN INT OPTION TO USE ON THE GETOPT
	int option;

	// CREATING GETOPT OPTIONS ( -s , -n , -c , -r , -x , -b )
		while((option = getopt(argc, argv, "s:n:c:r:x:b")) !=-1){
		switch(option) {
			case 's' :
				chan_size = true;
				break;
			case 'n' :
				chan_byte = true;
				break;
			case 'c' :
				encry = true;
				break;
			case 'r' : 
				shift = true;
				break;
			case 'x' :
				hex = true;
				break;
			case 'b' :
				binary = true;
				break;
		}
	}



	//CREATING A FILE DESCRIPTOPR 
	int fd;

	char BUFFER [1000];

	// INITIAZLING THE CHANGE OF  THE BUFFER ( -b )
	ssize_t BUFF_SIZE {1024};

	// NUMBER OF BYES TO READ 
	size_t bytesRead { 500 };

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
				// ADDED BUFF_SIZE TO CHANGE THE BUFFER
				while((numread = read(fd, BUFFER, BUFF_SIZE)) > 0)
				{
					// ADDED bytesRead TO READ THE NUMBER OF BYTES
					write (STDOUT_FILENO, BUFFER, bytesRead);

				}

		// CLEAN AFTER MYSELF
		// AND CLOSING THE FILE
		close(fd);
	}


	return 0;
}




