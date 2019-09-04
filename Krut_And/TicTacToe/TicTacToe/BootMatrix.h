#pragma once
class BootMatrix
{
protected:
	int **matrix;
	const int N = 3;
public:
	BootMatrix()
	{
		matrix = new int *[N];

		for (int i = 0; i < N; i++)
		{
			matrix[i] = new int[N];
		}
		//Начальное заполнение 2 ( "_" )
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[i][j] = 2;
			}
		}
	};

	virtual ~BootMatrix()
	{
		for (int i = 0; i < N; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	};

	int** getBoardMatrix()
	{
		return matrix;
	}
};

