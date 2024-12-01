#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{

	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

void FillMatrixWithRandomNumbers(short Arr[3][3] , short Rows , short Cols)
{
	for (int i = 0 ; i < Rows ; i++)
	{
		for (int j = 0 ; j < Cols ; j++)
		{
			Arr[i][j] = RandomNumber(1,100);
		}
	}
}

void PrintMatrixElements(short Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] <<"\t";
		}
		cout << "\n";
	}
}

short ColSum(short Arr[3][3] , short Row, short ColNumber)
{
	short Sum = 0;
	for (short j = 0; j < Row ; j++)
	{
		Sum += Arr[j][ColNumber];
	}
	return Sum;
}

void CalculateColsSumToArray(short Arr[3][3] , short SumArray[3] , short Rows, short Cols)
{
	for (short i = 0 ; i < Cols ; i++)
	{
		SumArray[i] = ColSum(Arr , Rows , i);
	}
}

void PrintSumArrayElements(short Arr[3] , short Rows)
{
	cout << "\n the 3x3 matrix Columns Sum\n";

	for (short i = 0 ; i < Rows ; i++)
	{
		printf(" Sum of column [%d] = %d\n" , i + 1 , Arr[i]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	short Arr[3][3];

	short SumArray[3];

	FillMatrixWithRandomNumbers(Arr , 3 , 3);

	cout << "\n the 3x3 matrix randomized elements\n";
	PrintMatrixElements(Arr, 3, 3);

	CalculateColsSumToArray(Arr, SumArray , 3, 3);

	PrintSumArrayElements(SumArray , 3);

	return 0;
}

