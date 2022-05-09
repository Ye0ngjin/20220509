#include <iostream>

#define MAX 52

using namespace std;

int main()
{
	int A[MAX] = { 0, };
	int SplitCard[52];
	int Deck[6] = { 0 , };
	int Player[3] = { 0, };
	int AI[3] = { 0, };
	int PlayerSum = 0;
	int AISum = 0;

	srand((unsigned int)time(0));


	//Initialize
	for (int i = 0; i < MAX; ++i)
	{
		A[i] = i;
	}

	//shuffle
	for (int i = 0; i < MAX * 2; ++i)
	{
		int FirstNumber = rand() % MAX;
		int SecondNumber = rand() % MAX;

		//Swap
		int Temp = A[FirstNumber];
		A[FirstNumber] = A[SecondNumber];
		A[SecondNumber] = Temp;
	}

	//split
	for (int i = 0; i < 6; ++i)
	{
		SplitCard[i] = A[i];
	}
	
	cout << "Player" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int Type = SplitCard[i] / 13;
		int Number = SplitCard[i] % 13 ;

		switch (Type)
		{
		case 0:
			cout << "♥" << " ";
			break;
		case 1:
			cout << "♠" << " ";
			break;
		case 2:
			cout << "♣" << " ";
			break;
		case 3:
			cout << "◆" << " ";
			break;
		}
		switch (Number)
		{
		case 10:
			cout << "J";
			Number = 10;
			break;
		case 11:
			cout << "Q";
			Number = 10;
			break;
		case 12:
			cout << "K";
			Number = 10;
			break;
		case 0:
			cout << "A";
			Number = 1;
			break;
		default:
			Number = Number + 1;
			cout << Number;
			break;
		}
		cout << endl;



		Deck[i] = Number;

/*		잘못만든것
		if (i < 3)
		{
			Player[i] = Number;
			cout << Player[i] << "  ";
		}


		if ( i >= 3 )
		{
			int j = i - 3;
			AI[j] = Number;
			cout << AI[j] << "  ";
		}
*/
	}

	cout << endl << "AI" << endl;
	for (int i = 3; i < 6; ++i)
	{
		int Type = SplitCard[i] / 13;
		int Number = SplitCard[i] % 13;

		switch (Type)
		{
		case 0:
			cout << "♥" << " ";
			break;
		case 1:
			cout << "♠" << " ";
			break;
		case 2:
			cout << "♣" << " ";
			break;
		case 3:
			cout << "◆" << " ";
			break;
		}

		switch (Number)
		{
		case 10:
			cout << "J";
			Number = 10;
			break;
		case 11:
			cout << "Q";
			Number = 10;
			break;
		case 12:
			cout << "K";
			Number = 10;
			break;
		case 0:
			cout << "A";
			Number = 1;
			break;
		default:
			Number = Number + 1;
			cout << Number;
			break;
		}

		cout << endl;

		Deck[i] = Number;

	}
	cout << endl;

	for (int i = 0; i < 3; ++i)
	{
		Player[i] = Deck[i];
		AI[i] = Deck[i + 3];
	}


	for (int i = 0; i < 3; ++i)
	{
		PlayerSum += Player[i];
		AISum += AI[i];
	}
	cout << "Player : " << PlayerSum << endl << "AI : " << AISum << endl << endl;

	if (PlayerSum == AISum)
	{
		cout << "Player Win!";
	}
	else if(AISum > 21)
	{
		cout << "Player Win!";
	}
	else if ((PlayerSum <= 21) && (AISum < 21) && (PlayerSum > AISum))
	{
		cout << "Player Win!";
	}
	else
	{
		cout << "AI Win!";
	}
	cout << endl;
	
	return 0;
}