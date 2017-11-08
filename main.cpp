#include <iostream>
#include <fstream>
#include <list>

#define BUFFER_SIZE 1024

bool reverse(char *buf);

using namespace std;

int main(int argc, char *argv[])
{
	char buf[BUFFER_SIZE];
	int sum = 0;
	list<int> v;
	int size = 0;
	ifstream in(argv[0], ios::in);
	if (!in)
	{
		cerr << "ERROR";
		return 1;
	}
	while (!in.eof())
	{

		in.getline(buf, sizeof buf);
		if (reverse(buf))
		{
			if (strlen(buf) % 2)
			{
				int s = strlen(buf);
				buf[s] = buf[s / 2];
				buf[s + 1] = '\0';
			}

			for (int i = 0; buf[i]; i++)
			{
				sum += (int)buf[i];
			}

			v.push_back(sum);
			sum = 0;
		}
	}

	size = v.size();
	v.unique();
	cout << size - v.size();
	in.close();
	
	return 0;

}

bool reverse(char *buf)
{
	unsigned j = 0;

	for (int i = (strlen(buf)-1); i >= 0; i--)
	{
		if (buf[j] == buf[i])
		{
			j++;
		}
		else
			return false;
	}

	return true;
}