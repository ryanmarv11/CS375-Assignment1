#include <ctime>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

int max(int a, int b);
int LCS(string a, string b, int ** matrix);

int main(int argv, char **args)
{
	ifstream inputFile1, inputFile2;
	ofstream outputFile;
	int i = sizeof(inputFile1);
	clock_t timer = clock();

	/* this block checks that the following things are true:
	the number of inputs are correct
	filex.txt can be opened and is valid filey.txt can be opened and is vaild
	output1.txt can be opened and is valid
	*/
	if(argv != 4){ //check for correct amount of inputs
		cerr << "Improper amount of arguments." << endl;
		return -1;
	}

	inputFile1.open("filex.txt");
	if(!inputFile1.is_open()){
		inputFile1.close();
		cerr << "There is an issue with filex.txt." << endl;
		return -1;
	}

	inputFile2.open("filey.txt");
	if(!inputFile2.is_open()){
		inputFile1.close();
		inputFile2.close();
		cerr << "There is an issue with filey.txt." << endl;
		return -1;
	}

	outputFile.open("output1.txt");
	if(!outputFile.is_open()){
		inputFile1.close();
		inputFile2.close();
		outputFile.close();
		cerr << "There is an issue with output1.txt." << endl;
		return -1;
	}

	//reads in the values from the now opened files
	string firstString, secondString; 
	getline(inputFile1, firstString);
	getline(inputFile2, secondString);


	int **matrix = new int* [firstString.length() + 1];
  	for(int i = 0; i <= firstString.length(); i++) 
  	{
    	matrix[i] = new int[secondString.length() + 1];
    	for(int j  = 0; j < secondString.length(); j++)
    		matrix[i][j] = 0;
    	
  	}

 	int maxLength;
	if(firstString == "" || secondString == "")
		maxLength = 0;
	else
		maxLength = LCS(firstString, secondString, matrix);

	if(firstString.length() <= 10 && secondString.length() <= 10){
		for(int i = 0; i < firstString.length()+1; i++){
			for(int j = 0; j < secondString.length()+1; j++){
				outputFile << matrix[i][j] << " ";
			}
			outputFile << endl;
		}
	}

	outputFile << "LCS Recursion Solution: " << maxLength << endl;
	timer = clock() - timer; //stops the timer
	outputFile << "Runitme: " << timer << " microseconds (1E-6)." << endl;
	return 0;
}

int max(int a, int b)  
{  
   return (a > b)? a : b;  
} 

int LCS(string a, string b, int ** matrix){ 

	for(int i = 1; i < a.length() + 1; i++) 
	{
		for(int j = 1; j < b.length() + 1; j++)
		{
			if(a[i-1] == b[j-1]) 
				matrix[i][j] = matrix[i-1][j-1] + 1;
			else if(matrix[i-1][j] >= matrix[i][j-1])
				matrix[i][j] = matrix[i-1][j];
			else 
				matrix[i][j] = matrix[i][j-1];
		}
	}
	return matrix[a.length()][b.length()];
}