#include "io.h"

void takeInput(State startState, State finalState) {

	ifstream file("input.txt");

	int *** startStateSpace = startState.space;
	int *** finalStateSpace = finalState.space;

	if (file.is_open()) {
		
		int value = 0;

		while (!file.eof()) {
			
			//read start state from file
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						file >> value;
						startStateSpace[i][j][k] = value;
					}
				}
			}   
			
			//read start state from file
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{

						file >> value;
						finalStateSpace[i][j][k] = value;
					}
				}
			}   
		}
		
	}
	else cout << "Cannot open file" << endl;
}

void print(int*** arr){
	cout << "Printing " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				
				cout<< arr[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

