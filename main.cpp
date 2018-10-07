// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

// Already implemented

void createMatrix (int row, int col, int num[], matrix& mat);

void print(matrix, matrix, matrix );
matrix createMatrix(matrix mat1);


// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int num;
    matrix mat1, mat2, mat3;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);

    print( mat1, mat2, mat3);



    cout <<"matrix1 + matrix3 "<<endl<< mat1 + mat3 <<endl;

    try
    {
        cout <<" matrix3 + matrix2 "<<endl;
        cout<< (mat3 + mat2) << endl;
    }

    catch (const char* except)
    {
        cout<<except<<endl;
    }

    cout <<" matrix3 - matrix3 "<<endl<< (mat3 - mat3) << endl;

    cout <<" matrix3 * matrix1 "<<endl;
    if(mat3.col==mat1.row)
    {
        cout <<mat3 * mat1 << endl;
    }
    else
    {
        cout<<"can't be multiplied as 1st matrix column and 2nd matrix row aren't equal"<<endl;
    }

    cout <<" matrix3 * matrix2 "<<endl<< (mat3 * mat2) << endl;


    cout<<"matrix3 + number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat3+num;

    cout<<"matrix1 - number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat1-num;

    cout<<"matrix3 * number "<<endl<<"Enter a number: ";
    cin>>num;
    cout<<endl<<mat3*num;


    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}

ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            out<<mat.data[i*mat.col+j]<<" ";

        }
        out<< endl;

    }
    return out;
}


//print the three matrices
void print(matrix mat1, matrix mat2, matrix mat3)
{

    cout<<"MATRIX 1:"<<endl;
    cout << mat1 << endl;
    cout<<"MATRIX 2:"<<endl;
    cout << mat2 << endl;
    cout<<"MATRIX 3:"<<endl;
    cout << mat3 << endl;
}

// add a matrix to another
matrix operator+  (matrix mat1, matrix mat2)
{
    if (mat1.row==mat2.row  && mat1.col==mat2.col)
    {
        matrix mat=createMatrix( mat1);

        for(int i=0; i<mat1.row*mat1.col; i++)
        {

            mat.data[i]=mat1.data[i]+mat2.data[i];
        }
        return mat;
    }
    else
    {
        throw "can't be added as the dimensions aren't the same";
    }

}

// subtract a matrix from another and return new one
matrix operator-  (matrix mat1, matrix mat2)
{
    matrix mat=createMatrix( mat1);
    if (mat1.row==mat2.row  && mat1.col==mat2.col)
    {



        for(int i=0; i<mat1.row*mat1.col; i++)
        {

            mat.data[i]=mat1.data[i]-mat2.data[i];
        }
        return mat;
    }
    else
    {
        cout<< "can't be subtracted as the dimensions aren't the same";
    }
    //return mat;
}

//multiplying two matrices and returning new matrix
matrix operator*  (matrix mat1, matrix mat2)
{
    int sum;
    matrix mat3;
    mat3.row=mat1.row;
    mat3.col=mat2.col;
    mat3.data=new int[mat3.row*mat3.col];
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat2.col; j++)
        {

            sum=0;
            for(int k=0; k<mat1.col; k++)
            {

                sum+=mat1.data[i*mat1.col+k]*mat2.data[k*mat2.col+j];
            }
            mat3.data[i*mat3.col+j]=sum;
        }

    }

    return mat3;
}

//add a number to matrix returning a new matrix
matrix operator+  (matrix mat1, int scalar)
{
    matrix mat=createMatrix( mat1);
    for(int i=0; i<mat1.row*mat1.col; i++)
    {
        mat.data[i]=mat1.data[i]+scalar;

    }
    return mat;
}

//subtract a number form matrix returning new matrix
matrix operator-  (matrix mat1, int scalar)
{
    matrix mat=createMatrix( mat1);
    for(int i=0; i<mat1.row*mat1.col; i++)
    {
        mat.data[i]=mat1.data[i]-scalar;

    }
    return mat;
}


//multiply matrix by number returning a new matrix
matrix operator*  (matrix mat1, int scalar)
{
    matrix mat=createMatrix(mat1);
    for(int i=0; i<mat1.row*mat1.col; i++)
    {
        mat.data[i]=mat1.data[i]*scalar;

    }
    return mat;
}
//function overloading to create a new empty matrix
matrix createMatrix(matrix mat1)
{
    matrix mat;
    mat.row=mat1.row;
    mat.col=mat1.col;
    mat.data=new int[mat.row*mat.col];
    return mat;
}

