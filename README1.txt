To compile and run the source code, I would advise doing the following:

g++ program1.cpp -o program1
./program1 filex.txt filey.txt output1.txt

output1.txt will contain the matrix of lenLCS values if both strings have a length <= 10
After the matrix, it will contain the length of the LCS, followed by the run time in microseconds.

When listing a string in filex.txt and filey.txt, make sure that there are no extra whitespaces or extra lines as this may result in an unwanted value. 
