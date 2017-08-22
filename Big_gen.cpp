#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <mutex>

using namespace std;
// 
mutex Main_Lock;
ofstream myfile;
const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void Higher_generate(unsigned int length, char* s)
{
	if (length == 0)
	{
		//Main_Lock.lock(); 
#ifdef _DEBUG
		cout << s << '\n';
#endif
		myfile << s << '\n';
		//Main_Lock.unlock();
		return;

	}

	for (unsigned int i = 0; alphabet[i]; i++) //itterate though alaphabet 
	{
		s[length-1] = alphabet[i];
		Higher_generate(length - 1, s);
	}
}



#define MAX_LENGTH 16
int main()
{
	myfile.open("strings.txt");
	
	for(auto i = 1; i < MAX_LENGTH; i++)
	{
		char* string = new char[i+1]; //pushes this to the heap, then gets removed making the program quicker and no memory leak 
		string[i] = '\0';
		Higher_generate(i, string);
		delete[] string;
	}
	myfile.close();

	// fill me in// 
	return 0;
}