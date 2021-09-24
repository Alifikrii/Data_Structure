#include <iostream> 
using namespace std; 

int main()
{
	int array[5]={1,2,3,4,5};

	cout<<"Output of begin and end: ";
	for (int i = 0; i < 5; i++)
	{				
		cout<<array[i]<<" ";
	}
	cout << endl;


	cout<<"Output of rbegin and rend: ";
	for (int i = 4; i >= 0; i--)
	{				
		cout<<array[i]<<" ";
	}
	cout<<endl;


	return 0;
}

