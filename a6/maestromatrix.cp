#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "maestromatrix.h"

using namespace std; 

matrix::~matrix()
{
//deallocate all memory
int i;
	for(i=0;i<p;i++) {
		free(A[i]);
	}
	free(A);
	for(i=0;i<q;i++) {
		free(B[i]);
	}
	free(B);
	for(i=0;i<p;i++) {
		free(AB[i]);
	}
	free(AB);
}

void matrix::printMatrix(int **m, int a, int b)//a: rows; b: cols
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			cout<<m[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<"\n\n";
}

void matrix::printallmatrices()
{
	printMatrix(A,p,q);
	printMatrix(B,q,p);
	printMatrix(AB,p,p);
	//printMatrix(BA,q,q);
}

void matrix::startmatrix(int a, int b)
{
	p=a; q=b;
	A=(int **)malloc(p*sizeof(int *));
	int i;
	for(i=0;i<p;i++) {
		A[i]=(int *)malloc(q*sizeof(int));
	}
	B=(int **)malloc(q*sizeof(int *));
	for(i=0;i<q;i++) {
		B[i]=(int *)malloc(p*sizeof(int));
	}
	AB=(int **)malloc(p*sizeof(int *));
	for(i=0;i<p;i++) {
		AB[i]=(int *)malloc(p*sizeof(int));
	}
	/*BA=(int **)malloc(q*sizeof(int *));
	for(i=0;i<q;i++) {
		BA[i]=(int *)malloc(q*sizeof(int));
	}*/
}

void matrix::computeProducts(int i, int j, int k)
{  
		AB[i][j]+=A[i][k]*B[k][j];
}

void matrix::generateMatrixA()
{
	srand(1); 
	int i,j;
	for(i=0;i<p;i++)
		for(j=0;j<q;j++) {
		A[i][j]= rand() % 11; 
		}
}

void matrix::generateMatrixB()
{
	srand(2); 
	int i,j; 
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
		B[j][i]= rand() % 11;
		}
	}	
}
