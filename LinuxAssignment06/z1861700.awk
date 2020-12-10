#!/bin/bash

####################################################################################
# Name: Brayan Chacha G
# Cour: 330 Unix Prog and Net
# Pro:  Professor Lehuta 
# Asig: Assignment 7
# INPUT FILE  salesdb 
# command line: awk -f z1861700.awk salesdb 
####################################################################################

BEGIN{
      # First, changing the input field seperator to -> : <-#
      FS=":";

      # Displaying header  
      printf("\n%35s\n", "No-Op Computing");
      printf("%39s", "---------------------\n");
      printf ("%40s"," 2018 Sales Associates\n");
      printf ("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

      # Displaying title
      printf("%-20s %-15s %15s\n", "Name", "Position", "Sales Amount");

      # Breal
      print "=======================================================";
}

{

     # if field #4 -> product information
     if(NF == 4)
     	{

	# ProductID 
	proID = $1;

	# Product Category 
	proCate = $2;

	# Product Description
	proDesc = $4;

	# Product price 
	proprice = $4;

	# Product Cost 
	procost[$1] = $4;
	}

	# if field #3 -> Associte  information
	else if(NF == 3)
	{

		# Associte ID
		AssoID = $1;

		# Assicute name -> ex: Brayan, Chacha
		AssoName = $2; -split(AssoName, a," "); AssoName = a[1]", "a[2];

		# Associates position
		AssoPosi = $3;

		# Setting Associte variable 
		Associte[AssoID] = AssoName ":" AssoPosi;
	}
	
	#if field #5 -> product sale information 
		else if(NF == 5)
		{

			# Transaction ID
			saleID = $2;

			# Quantity
			salesqnt = $3;

			# Sale date 
			saledate = $4;

			# Associte ID - > when the sale was made 
			saID = $5;
			
			# setting date ->  2018
			if(saledate ~ /\/2018/)
			{
		
			# add the prodoct cost, deleclaring sales 
			if(saID in sales) 

				sales[saID] = sales[saID] + procost[saleID] * salesqnt;

			else 
				sales[saID] = procost[saleID] * salesqnt;
			}	
		}
} #END OF BEGGIN! 

END{
		# Implementing the sort() function -> descending order, creating new array sort_sales 
		asort(sales, sort_sales);

		# for loop to populate the order 
		for(i = length(sort_sales); i > 0; i--)
		{

			for(desorder in sales)
			{
		
				if (sales[desorder] == sort_sales[i])
				{
					# Seperating the data 
					split(Associte[desorder], a,":");

					# Assoname to display
					AssoName = a[1];

					# postion to display
					position = a[2];

					# printing data to user 
					printf ("%-20s %-15s % 15.2f\n", AssoName, position, sort_sales[i]);
			
					# breaking out of the loop
					break;

					
				}
			}

	
		}

}#END OF END!




