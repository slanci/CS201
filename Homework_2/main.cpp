/**
* Title : Algorithm Analysis
* Author : Sila Inci
* ID: 21602415
* Section : 1
* Assignment : 2
* Description : main function
*/


#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>

using namespace std;


static void swap( int& n1, int& n2 ) {

    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void solution1( int input[], const int n, const int k, int output[] ) {

    int maxIndex, maxValue;
    for ( int i = 0; i < k; i++ ) {
        maxIndex = i;
        maxValue = input[i];
        for ( int j = i+1; j < n; j++ ) {
            if ( input[j] >= maxValue ) {
                maxIndex = j;
                maxValue = input[ j ];
            }
        }
        swap( input[i], input[maxIndex] );
        output[i] = input[i];
    }
}

static int partition( int input[], int p, int r ) {

    int x = input[ r ], i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[i+1], input[r] );
    return i + 1;
}

static void quickSort( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition( input, p, r );
        quickSort( input, p, q - 1 );
        quickSort( input, q + 1, r );
    }
}

void solution2( int input[], const int n, const int k, int output[] ) {

    quickSort( input, 0, n - 1 );
    for ( int i = 0; i < k; i++ ) {
        output[i] = input[i];
    }
}

static int partition2( int input[], int a, int p, int r ) {

    int x = a, i = p - 1;
    for ( int j = p; j < r; j++ ) {
        if ( input[ j ] == x ) {
            swap( input[ j ], input[ r ] );
        }
        if ( input[ j ] >= x ) {
            i = i + 1;
            swap( input[i], input[j] );
        }
    }
    swap( input[ i + 1 ], input[ r ] );
    return i + 1;
}

static void quickSort2( int input[], int p, int r ) {

    int q;
    if ( p < r ) {
        q = partition2( input, input[ r ], p, r );
        quickSort2( input, p, q - 1 );
        quickSort2( input, q + 1, r );
    }
}

static int findMin( int n1, int n2 ) {

    if ( n1 <= n2 )
        return n1;
    else
        return n2;
}

static int select( int input[], int n, int k, int start, int end, int flag ) {

    if ( n <= 5 ) {
        quickSort2( input, start, end );
        return input[ start + k - 1 ];
    }
    int i = start, numGroups = (int) ceil( ( double ) n / 5 ), numElements; //j = 0;
    int *medians = new int[numGroups];
    while ( i <= end ) {
        numElements = findMin( 5, end - i + 1 );
        medians[( i - start ) / 5] = select( input, numElements, (int) ceil( ( double ) numElements / 2 ), i, i + numElements - 1, 1 );
        i = i + 5;
    }
    int M = select( medians, numGroups, (int) ceil( ( double ) numGroups / 2 ), 0, numGroups - 1, 1 );
    delete[] medians;
    if ( flag == 1 )
        return M;
    int q = partition2( input, M, start, end );
    int m = q - start + 1;
    if ( k == m )
        return M;
    else if ( k < m )
        return select( input, m - 1, k, start, q - 1, 0 );
    else
        return select( input, end - q, k - m, q + 1, end, 0 );
}

void solution3( int input[], const int n, const int k, int output[] ) {

    select( input, n, k, 0, n - 1, 0 );
    for( int i = 0; i < k; i++ )
        output[i] = input[i];
}

int main()
{
    int size = 100000;
    cout << "Algortihm Analysis for arrays with size " << size << ":" << endl;

    int test[size];
    int test1[size];
    int test2[size];
    int test3[size];
	for (int i = 0; i < size; ++i)
	{
		test[i] = 0 + (rand() % static_cast<int>(size - 0 + 1));
		cout << test[i] << " ";
	}
	for(int i = 0; i < size; ++i)
	{
        test1[i] = test[i];
        test2[i] = test[i];
        test3[i] = test[i];
    }
    cout << endl;

    cout << "Test 1 for Algorithm 1: \n";

	cout << "\n";
	int output1[size];

    // Store the starting time
	double duration;
	clock_t startTime = clock();
	// Code block
	solution1(test1,size,size,output1);

    //Compute the number of milliseconds that passed since the starting time
	duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
	cout << "Execution took " << duration << " milliseconds." << endl;

	cout << "\n";
	cout << "Sorted with Solution1: \n";
	cout << "\n";
	cout << "\n";

	cout << "Test 2 for Algorithm 2: \n";

    	cout << "\n";
	int output2[size];

	 // Store the starting time
	double duration2;
	clock_t startTime2 = clock();
	// Code block

	solution2(test2,size,size,output2);

	//Compute the number of milliseconds that passed since the starting time
	duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
	cout << "Execution took " << duration2 << " milliseconds." << endl;

	cout << "\n";
	cout << "Sorted with Solution2: \n";
	cout << "\n";
	cout << "\n";

	cout << "Test 3 for Algorithm 3: \n";

    	cout << "\n";

	int output3[size];

	 // Store the starting time
	double duration3;
	clock_t startTime3 = clock();
	// Code block

	solution3(test3,size,size,output3);

	//Compute the number of milliseconds that passed since the starting time
	duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
	cout << "Execution took " << duration3 << " milliseconds." << endl;

	cout << "\n";
	cout << "Sorted with Solution3: \n";
	cout << "\n";

    return 0;
}
