#include <iostream>
using namespace std;

int main()
{

	cout << "   -------------------------------  ";
	if (0)
	{
		cout << "P" << endl;
	}
	else
	{
		cout << " " << endl;
	}
	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			cout << "  |   |XXX|   |XXX|   |XXX|   |XXX| ";
			cout << endl;
			cout << (8 - i) << " |   |X X|   |X X|   |X X|   |X X| " 
				<< endl 
				<< "  |   |XXX|   |XXX|   |XXX|   |XXX| " 
				<< endl;
		}
		else
		{
			cout << "  |XXX|   |XXX|   |XXX|   |XXX|   | " << endl
				 << (8 - i) << " |X X|   |X X|   |X X|   |X X|   | " << endl 
				<< "  |XXX|   |XXX|   |XXX|   |XXX|   | " << endl;
		}
		if (i < 7)
		cout << "  |---|---|---|---|---|---|---|---| " << endl;
	}
	cout << "   -------------------------------  " << endl << "    a   b   c   d   e   f   g   h   " << endl;
	if (0)
	{
		cout << "P" << endl;
	}
	else
	{
		cout << " " << endl;
	}
	

	return 0;
}