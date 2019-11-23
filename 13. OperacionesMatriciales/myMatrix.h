#pragma once
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<time.h>


using namespace std;

/* Definimos estructura tipo matrix*/



struct matrix
{
	int nRow;
	int nCol;
	float **values;

};

typedef struct matrix matrix;

/* Crear matrix aleatoria dado n y m*/


matrix * makeMatrix(int Rows, int Cols = NULL)
{
	matrix * mat = new matrix;
	mat->nRow = Rows;
	float aux;
	if (Cols == NULL)
	{
		mat->nCol = Rows;
	}
	else {
		mat->nCol = Cols;
	}

	mat->values = new float *[mat->nRow];
	for (int i = 0; i < mat->nRow; i++)
	{
		mat->values[i] = new float[mat->nCol];
		for (int j = 0; j < mat->nCol; j++)
		{

			mat->values[i][j] = 1.0*(rand() % mat->nRow);
		}
	}
	return mat;

}




void printMatrix(matrix  *mat)
{

	cout << "Dimensiones de la matrix: (" << mat->nRow << "," << mat->nCol << ")" << endl << endl;
	for (int i = 0; i < mat->nRow; i++)
	{
		for (int j = 0; j < mat->nCol; j++)
		{
			cout << mat->values[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

