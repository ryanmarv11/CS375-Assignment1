#include <ctime>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector>
#include <string>

using namespace std;


int max(int a, int b);


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

	string firstString, secondString; 
	getline(inputFile1, firstString);
	int maxLength = LCS(firstString, secondString);
	outputFile << "LCS Recursion Solution: " << maxLength << endl;
	timer = clock() - timer;
	outputFile << "Runitme: " << timer << " microseconds (1E-6)." << endl;

	return 0;
}


int max(int a, int b)  
{  
   return (a > b)? a : b;  
}  