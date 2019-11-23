#include"myMatrix.h"
#include"OperSeq.h"




int main()
{
	matrix * Mat_prueba= new matrix;

	Mat_prueba = makeMatrix(10,20);
	
	printMatrix(Mat_prueba);

	transponer(Mat_prueba);
	
	printMatrix(Mat_prueba);

	matrix * Mat_prueba2 = new matrix;
	matrix * Mat_prueba3 = new matrix;
	matrix * Mat_prueba4 = new matrix;
	matrix * Mat_prueba5 = new matrix;
	matrix * Mat_prueba6 = new matrix;

	Mat_prueba2 = makeMatrix(8, 6);
	Mat_prueba3 = makeMatrix(8, 6);
	Mat_prueba4 = makeMatrix(6, 4);

	Mat_prueba5 = ProductoEntrada(Mat_prueba2, Mat_prueba3);
	Mat_prueba6 = ProductoMatricial(Mat_prueba3, Mat_prueba4);

	cout << "Producto Entrada a Entrada" << endl<< endl;
	printMatrix(Mat_prueba2);
	printMatrix(Mat_prueba3);

	cout << "Producto:" << endl;
	printMatrix(Mat_prueba5);

	cout << "Producto Matricial" << endl << endl;

	printMatrix(Mat_prueba3);
	printMatrix(Mat_prueba4);

	cout << "Producto:" << endl;
	printMatrix(Mat_prueba6);



	delete (Mat_prueba);
	delete (Mat_prueba2);
	delete (Mat_prueba3);
	delete (Mat_prueba4);
	delete (Mat_prueba5);
	delete (Mat_prueba6);
	cout << endl << endl;
	system("pause");
	return 0;
}
