To compile and run the source code, I would advise doing the following:

g++ program3.cpp -o program3
./program3 filex.txt filey.txt output3.txt

output.txt will contain the length of the LCS on the first line, followed by the run time in microseconds on the second line.

When listing a string in filex.txt and filey.txt, make sure that there are no extra whitespaces or extra lines as this may result in an unwanted value. 
