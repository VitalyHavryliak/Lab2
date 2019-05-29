#include <omp.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

int i, j, n = 10;
double A[n][n], B[n][n];
int C[n], D[n];

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			A[i][j]=rand()%2-1;
			B[i][j]=rand()%2-1;
			cout<<A[i][j]<<' ';
		}
		cout<<endl;
	}

	cout<<endl;

	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			cout<<B[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
int count = 0;
#pragma omp parallel for schedule(dynamic, 4) private(i,j)
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(A[i][j] == 0){
				count = count + 1;
			}
		}
	C[i] = count;
	count = 0;
	printf("Count of zero in line %d = %d, thread - %d\n", i, C[i], omp_get_thread_num());
	}
	cout << endl;
#pragma omp parallel for schedule(guided, 6) private(i,j)
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			if(B[i][j] == 0){
				count ++;
				}
			}
	D[i] = count;
	count = 0;
	printf("Count of zero in line %d = %d, thread - %d\n", i, D[i], omp_get_thread_num());
	}
	return 0;
}