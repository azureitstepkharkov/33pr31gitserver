#pragma once
class BoardMatrix
{
protected:
	int ** matrix;
	const int N = 3;
public:
	BoardMatrix()
	{
		matrix = new int *[N];
		for (int i(0); i < N; i++)
		{
			matrix[i] = new int[N];
		}
		for (int i(0); i < N; i++)
		{
			for (int j(0); j < N; j++)
			{
				matrix[i][j] = 2;
			}

		}


	};
	virtual ~BoardMatrix() {
		for (int i(0); i < N; i++)
		delete[] matrix[i];
	};

	int ** GetDoard()
	{
		return matrix;
	}
};

