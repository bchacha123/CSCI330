#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

extern char ressult[700];


// CREATING BINARY FUNCTION
void binary(int argc, char * argv[])
{
	
	for (int i = 0; i <= argc; i++)
	{
		// CONVERTION TO ASCII VALUE
		// CANT DO THIS CONVERIONS *****************************
		// *****************************************************
		//   E R R O R ! 1 ! 1 :( 
		int value = argv[i];

		//ASCII TO BINRAY
		string a = "";
		while (value > 0)
		{
			(value % 2) ? a.push_back('1'):a.push_back('0');
			value /= 2;
		}

		reverse(a.begin(), a.end());

		cout << a << " ";
	}

}


// CREATING THE HEXIDECIMAL FUNCTION 
void hex(char * argv[])
{
	// ARRAY TO STORE HEX NUM 
	char hexNum[1000];

	// COUNTER FOR HEX NUM
	int i = 0;
	while (str!= 0)
	{
		//TEMPORARY VAL TO STORE THE REMAINDER
		int temp_val = 0;

		// STORING THE NUMBER 
		temp_val = str % 16;

		// CHECKING THE VALUE 
		if(temp_val < 10)
		{
			hexNum[i] = temp_val + 48;
			i++;

		}
		else 
		{
			hexNum[i] = temp_val + 55;
			i++;
		}

		str = str/16;

	}


	// PRINTING HEX NUM IN REVERSE OR
	for(int k = i - 1; k >= 0; k--)
		cout << hexNum[k];


}

// CREATING THE ENCTYPTED
char *  encry(char * argv[], int argc)
{
	string result = " ";

	//TRAVERSE THE TEXT
	for (int i = 0; i < txt.length(); i++)
	{
		if(isupper(txt[i]))
			result += char(int(txt[i] + a -65) % 26 + 65);
	
	// ELSE LOWERCASE 
		else 
			result += char(int(txt[i] + a - 97) % 26 + 97);

	}
	//RETURN AS A STRING
	return result;

}


// CREATING A VOID SHIFT FUNCTION 
void shift(char * argv[], int argc)
{
	// SHIFTING ALL BYTE TO THE RIGHT 
	for (int i = 0; str[i]; i++)
	{
	 str[i] = str[i] >> num;
	
	}
}



