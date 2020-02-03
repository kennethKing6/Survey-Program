
/**
* Name: Kouadio Kenneth
* Student Number: T00633691
* Assignment Number: 1
* Due Date:  eg January 22, 2020
*
*Program Description: This program displays the different houselholds and different information about those 
*                     houselholds. and finally comments them based on how much they make
**/

#include <stdio.h>


#define SIZE 13 // Hold the number of households



#define NO_OF_HOUSEHOLD_CHAR 9 //holds the number of characters in the household title
#define NO_OF_INCOME_CHAR 6 //holds the number of characters in the income title
#define NO_OF_MEMBERS_CHAR 7 //holds the number of characters in the members title
#define NO_OF_COMMENTS_CHAR 8 //holds the number of characters in the comments title



	int main(void){
		const char*  household[] = {"Armstrong","Burns","Cousins","Duggan","Evans","Field","Garnett",
									"Hadfield","Johnston","Lovett","McDonald","Petersen","Singh"};
		
		int income[] = {25295,35178,66711,10455,28943,43226,30869,21143,26444,33777,17551,41323,39117};
		int members[] = {7,3,5,1,3,3,4,5,3,4,1,4,2}; 
		
		//Titles
		char houseHoldTt[NO_OF_HOUSEHOLD_CHAR + 1] = "Household";
		char incomeTt[NO_OF_INCOME_CHAR + 1] = "Income";
		char membersTt[NO_OF_MEMBERS_CHAR + 1] = "Members";
		char commentsTt[NO_OF_COMMENTS_CHAR + 1] = "Comments";
		
		//Display the titles 
		printf("%s%15s%15s%15s\n\n",houseHoldTt,incomeTt,membersTt,commentsTt);
		
		
		
		
		
		//Calculate average income
		int totalIncome = 0;
		for(size_t i = 0; i < SIZE; i++){
			totalIncome += income[i];
		}
		double averageIncome = ((double)totalIncome) / SIZE;
		
		
		
		
		
		// Number of households below poverty level
		int HouseHoldPovertyLevelNum = 0; 
		
		
		
		
		
		//Display the table data
		for(size_t i = 0; i < SIZE; ++i){
			
			
			/**
			*Count the number of characters of each data in household array at each index to determine the appropriate spacing 
			**/
			int inc = 0; // The number of characters of the household name
			for(size_t z = 0; z < household[i][z] != '\0'; ++z){
				inc++;
			}
			
			
			
			
			//How much spacing is remaining to align the income values in the income,the members and the comments columns for each data so that it remains
			//well spaced out 
			int remainingIncomespace = (NO_OF_HOUSEHOLD_CHAR + 15) - (inc + 1);
			int remainingMembersspace = 15 - 4;
			int remainingCommentsSpace = 14;
			
			
			// Printing the information while ensuring the correct spacing
			printf("%s",household[i]);
			printf("%*d",remainingIncomespace,income[i]);
			printf("%*d",remainingCommentsSpace,members[i]);	
			
			
		
			//Calculate povertyLevel
			int povertyLevel = 18000 + 1500 * (members[i] - 2);
			
			//Print out the correct comment asteriks
			if( income[i] > (averageIncome + 10000) ){
				printf("%*s",remainingCommentsSpace,"*");
				
			}else if(income[i] > averageIncome && income[i] > povertyLevel){
				
				printf("%*s",remainingCommentsSpace,"**");
				
			}
			else if(povertyLevel > income[i] && income[i] > (povertyLevel - 5000) ){
				
				printf("%*s",remainingCommentsSpace,"***");
				++HouseHoldPovertyLevelNum;

			}else if(income[i] < povertyLevel ){
				
				printf("%*s",remainingCommentsSpace,"****");
				++HouseHoldPovertyLevelNum;

			}
			
			
			printf("\n");
			
		}
		printf("\n");

		//Print out the legend
		printf("%s","*    -Very High Income (income is more than $10,000 above the average)\n");
		printf("%s","**   -Above Average Income\n");
		printf("%s","***  -Income is below the Poverty Level\n");
		printf("%s","**** -Extreme Poverty (more than $5,000 below the poverty level)\n\n");
		
		//Print out the final result
		printf("%s%.0f","The average income of the households surveyed is $",averageIncome);
		puts("");
		printf("%s %.0f%s","The percentage of households below the poverty level is",(((double)HouseHoldPovertyLevelNum) / SIZE) * 100,"%");
		
		
		return 0;
	}
