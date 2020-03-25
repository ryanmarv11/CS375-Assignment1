#include <ctime>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector>
#include <string>

using namespace std;

int LCS(string a, string b);
int LCSHelper(string a, string b, int i, int j);
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
	output2.txt can be opened and is valid
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

	outputFile.open("output2.txt");
	if(!outputFile.is_open()){
		inputFile1.close();
		inputFile2.close();
		outputFile.close();
		cerr << "There is an issue with output2.txt." << endl;
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
int LCS(string a, string b){
	return LCSHelper(a,b,0,0);
}

int LCSHelper(string a, string b, int i, int j){
	if(a[i] == '\0' || b[j] == '\0')
		return 0;
	else if(a[i] == b[j])
		return 1 + LCSHelper(a,b,i+1, j+1);
	else
		return max(LCSHelper(a,b,i+1, j), LCSHelper(a,b,i, j+1));
}

int max(int a, int b)  
{  
   return (a > b)? a : b;  
}  