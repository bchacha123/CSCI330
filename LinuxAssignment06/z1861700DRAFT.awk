#!/bin/bash

####################################################################################
# Name: Brayan Chacha G
# Cour: 330 Unix Prog and Net
# Pro:  Professor Lehuta 
# Asig: Assignment 7 
####################################################################################
BEGIN{
      # First, changing the input field seperator to -> : <-#
      FS=":";

      # Displaying header  
      print("No-Op Computing");
      print "2018 Sales Associates";

      # Displaying title
      printf("%-20s %-15s %20s\n", "Name", "Position", "Sales Amount");

      # Breal
      print "=======================================================";
}

{

     # if field #4 -> product information
     if(NF == 4){

	# ProductID and Pric
	proID = $1;
	proprice = $4;

	procost[$1] = $4;
	}

	# if field #3 -> emplyee information
	else if(NF == 3){

		empID = $1;
		empName = $2; -split(empName, a,""); empName = a[1]", "a[2];
		empPosi = $3;

		employee[$1] = $2 ":" $3;
#		employee[empID] = empName ":" empPosi;
	}
	
	#if field #5 -> product sale information 
#		else if(NF == 5){

#			saleID = $2;
#			salesqnt = $3;
#			saledate = $4;
#			saID = $5;
			
			# sales year 2018
#			if(saledate ~ /\/2018/){
		
			# add the prodoct cost 
#			if(saID in sales) 

#				sales[saID] = sales[saID] + procost[saleID] * salesqnt;

#			else 
#				sales[saID] = procost[saleID] * salesqnt;}	
#	}


	else if (NF == 5 && $4 ~ /2018/)
	{
		if($2 in procost){
			sales[employee[$NF]] += $3 * procost[$2];
		}

	}
}


END {

#	printf "%20s %15s %20s\n", "Name", "Position","Sales Amount"

#		for(eid in sales){

#		if(eid in employee){
#			split(employee[eid], a,"-");

#			empName = a[1];

#			position = a[2];

#			printf ("%-20s %-15s % 15.2f\n", empName, position, sales[eid]);}
#		}

	asort(sales, sortSales);
	for(i = length(sortSales); i > 0; i--){
		for ( x in sales){
			if (sales[x] == sortSales[i]){
				split(x,finalData,":");
				
				# finalData[1] = -split(empName,a,":"); empName = a[1]", "a[2];

				printf("%-20s %-15s %15.2f\n",finalData[1], finalData[2], sortSales[i]);

				break;
			}
		}

	}
}

					
#END

