#include"myMatrix.h"

using namespace std;

/* TRANSPUESTA DE UNA MATRIZ M*N */ 

void transponer(matrix *mat)
{
	float ** aux;
	float ** Transpuesta=new float * [mat->nCol];
	
	for (int j = 0; j < mat->nCol; j++) 
	{
		Transpuesta[j] = new float[mat->nRow];
		for(int i=0;i<mat->nRow;i++)
		{
			Transpuesta[j][i] = mat->values[i][j];
		}
	}

	aux = mat->values;
	mat->values = Transpuesta;

	for(int i=0;i<mat->nRow;i++)
	{
		delete[] aux[i];
	}
	delete aux;

	int aux2 = mat->nCol;
	mat->nCol = mat->nRow;
	mat->nRow = aux2;
}

/*        PRODUCTO ENTRADA A ENTRADA*/

matrix * ProductoEntrada(matrix *A, matrix * B)
{
   if(A->nCol!=B->nCol | A->nRow != B->nRow)
   {
	   cout << "Las dimensiones no permiten el producto";
	   return NULL;
   }else 
   {
	   matrix *mat = new matrix;
	   mat->nCol = A->nCol;
	   mat->nRow = A->nRow;

	   mat->values = new float *[mat->nRow];
	   for (int i = 0; i < mat->nRow; i++)
	   {
		   mat->values[i] = new float[mat->nCol];
		   for (int j = 0; j < mat->nCol; j++)
		   {

			   mat->values[i][j] = A->values[i][j]* B->values[i][j];
		   }
	   }
	   return mat;

   }

}

/* PRODUCTO MATRICIAL*/

matrix * ProductoMatricial(matrix *A, matrix * B)
{
	if (A->nCol != B->nRow)
	{
		cout << "Las dimensiones no permiten el producto";
		return NULL;
	}
	else
	{
	
		matrix *mat = new matrix;
		mat->nCol = B->nCol;
		mat->nRow = A->nRow;
		float aux = 0;

		mat->values = new float *[mat->nRow];
		for (int i = 0; i < mat->nRow; i++)
		{
			mat->values[i] = new float[mat->nCol];
			for (int j = 0; j < mat->nCol; j++)
			{

				for (int k=0;k<A->nCol;k++)
				
				{
					aux += A->values[i][k] * B->values[k][j];
				}
				mat->values[i][j] = aux;
				aux = 0;
			}
		}
		return mat;
	}
}
