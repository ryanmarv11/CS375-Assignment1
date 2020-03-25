#include <ctime>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

int max(int a, int b);
int LCS(string firstString, string secondString, int **matrix);
int LCSHelper(string firstString, string secondString, int i, int j, int **matrix);

int main(int argv, char **args)
{
	ifstream inputFile1, inputFile2;
	ofstream outputFile;
	int i = sizeof(inputFile1);
	clock_t timer = clock();

	/* this block checks that the following things are true:
	the number of inputs are correct
	filex.txt can be opened and is valid filey.txt can be opened and is vaild
	output3.txt can be opened and is valid
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

	outputFile.open("output3.txt");
	if(!outputFile.is_open()){
		inputFile1.close();
		inputFile2.close();
		outputFile.close();
		cerr << "There is an issue with output3.txt." << endl;
		return -1;
	}


	//reads in the values from the now opened files
	string firstString, secondString; 
	getline(inputFile1, firstString);
	getline(inputFile2, secondString);

	int** matrix = new int*[firstString.length()];
	for(int i = 0; i < firstString.length(); i++){
		matrix[i] = new int[secondString.length()];
		for(int j = 0; j < secondString.length(); j++){
			matrix[i][j] = INT_MIN;
		}
	}
	int maxLength;
	if(firstString == "" || secondString == "")
		maxLength = 0;
	else
		maxLength = LCS(firstString, secondString, matrix);
	outputFile << "LCS Recursion Solution: " << maxLength << endl;
	timer = clock() - timer;
	outputFile << "Runitme: " << timer << " microseconds (1E-6)." << endl;

	return 0;
}

int max(int a, int b)  
{  
   return (a > b)? a : b;  
} 

int LCS(string firstString, string secondString, int **matrix)
{
	return LCSHelper(firstString, secondString, firstString.length()-1, secondString.length()-1, matrix);
}
 
int LCSHelper(string firstString, string secondString, int i, int j, int **matrix) 
{
	if(i < 0 || j < 0)
		return 0;
	if(matrix[i][j] != INT_MIN) 
		return matrix[i][j];
	if(firstString[i] == secondString[j]) 
	{
		matrix[i][j] = LCSHelper(firstString, secondString, i-1, j-1, matrix) + 1;
		return matrix[i][j];
	} 
	else 
	{
		matrix[i][j] = max(LCSHelper(firstString, secondString, i-1, j, matrix), LCSHelper(firstString, secondString, i, j-1, matrix));
		return matrix[i][j];
	}
}