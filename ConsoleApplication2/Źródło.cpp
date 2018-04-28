#include <cstdlib>
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <fstream>


using namespace std;

bool dostep = true;
void funkcja()
{
	fstream plik;
	string s;

	while (dostep)
	{
		system("ping -n 2 wp.pl > cos.txt");
		plik.open("cos.txt", ios::in);

		if (plik.good() == true)
		{			
			for (int i = 0; i < 3; i++)
			{
				getline(plik, s);
			}
				cout << s << "\n";
		}
		plik.close();
	}
}

int main()
{
	thread t(funkcja);
	while(getch()!=27)
	{ }
	dostep = false;
	t.join();

	return 0;
}