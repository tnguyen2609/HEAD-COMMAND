# HEAD-COMMAND
This program will allow user to enter command works like head command in linux and system will work accordingly.
./a.out ---> To run the command:
	* head: Display the first 10 lines of the text file(s).
	* -n N : N is a positive number. Print the first N lines of file.
    	* -c N : N is a positive number. Print the first N bytes of file.
   	* -v N : Print the filename header and the content of the file. 
    	* -q   : Function will never print filename header. 

User can input multiple command and system will take the most current one to work on.
Ex: ./a.out head -q -n 5 -v -c 6 text01.txt
	--> Sytem will take -c as the command with the number of 6 bytes to read from text01.txt.
