/*
Syed Aalyan Raza Kazmi
22i-0833
Section A
*/
#pragma once
#include <iostream>
using namespace std;


//      Question 1
// Part A
template <class t>
class ArrayBasics
{
public:
    static t findMax(t(A)[], int i, int j)
    {
        static t max = A[i];
        for (int start = i; start < j; start++)
        {
            if (A[start] > max)
                max = A[start];
        }
        return max;
    }
    static int findMaxPos(t(A)[], int i, int j)
    {
        t max = A[i];
        static int place = 0;

        for (int start = i; start <= j; start++)
        {
            if (A[start] > max)
            {
                max = A[start];
                place = start;
            }
        }
        return place;
    }
    static t findMin(t(A)[], int i, int j)
    {
        static t min = A[i];
        for (int start = i; start < j; start++)
        {
            if (A[start] < min)
                min = A[start];
        }
        return min;
    }
    static int findMinPos(t(A)[], int i, int j)
    {
        t min = A[i];
        static int place = 0;

        for (int start = i; start < j; start++)
        {
            if (A[start] < min)
            {
                min = A[start];
                place = start;
            }
        }
        return place;
    }
    static void swap(t(A)[], int i, int j)
    {
        t temp = 0;
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    static void shiftRight(t(A)[], int i, int j)
    {
        for (int start = j; start > i; start--)
        {
            A[start] = A[start - 1];
        }
    }
    static void shiftLeft(t(A)[], int i, int j)
    {
        for (int start = i; start < j; start++)
        {
            A[start] = A[start + 1];
        }
    }
    static t* createRandomArray(int size, int min, int max)
    {
        t* resultant = new t[size];
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int start = 0; start < size; start++)
        {
            resultant[start] = min + (rand() % (max - min));
        }
        return resultant;
    }
    static t** createRandomMatrix(int rows, int cols, int min, int max)
    {
        t** resultant = new t * [rows];
        srand(static_cast<unsigned int>(time(nullptr)));

        for (int i = 0; i < rows; i++)
        {
            resultant[i] = new t[cols];
            for (int j = 0; j < cols; j++)
                resultant[i][j] = min + (rand() % (max - min));
        }
        return resultant;
    }
    static t* copyArray(t(A)[], int size)
    {
        t* copier = new t[size];
        for (int i = 0; i < size; i++)
        {
            copier[i] = A[i];
        }
        return copier;
    }
    static int** copyMatrix(t** (A), int rows, int cols)
    {
        t** resultant = new t * [rows];

        for (int i = 0; i < rows; i++)
        {
            resultant[i] = new t[cols];
            for (int j = 0; j < cols; j++)
                resultant[i][j] = A[i][j];
        }
        return resultant;
    }
    static int findInArray(t(A)[], t q, int size)
    {
        int position = -1;
        for (int i = 0; i < size; i++)
        {
            if (A[i] == q)
            {
                position = i;
                break;
            }
        }
        return position;
    }
    static int findInSortedArray(t(A)[], t q, int size) // Binary Search
    {
        int start = 0;
        int end = size - 1;

        while (start <= end)
        {
            int middle = start + (end - start) / 2;

            if (A[middle] == q)
                return middle; // Element found at index 'middle'
            else if (A[middle] < q)
                start = middle + 1;
            else
                end = middle - 1;
        }
        return -1;
    }
    static int findFirstInSortedArray(t(A)[], t q, int size)
    {
        int ans = -1;
        int start = 0;
        int end = size - 1;

        while (start <= end)
        {
            int middle = start + (end - start) / 2;

            if (A[middle] == q)
            {
                ans = middle; // Element found at index 'middle'
                break;
            }
            else if (A[middle] < q)
                start = middle + 1;
            else
                end = middle - 1;
        }
        if (ans >= 0)
        {
            while ( A[ans - 1] == A[ans])
                ans--;
        }
        return ans;
    }

};

// Part B
template <class t>
class ArrayUtility
{
public:
    static void maxSortWithShiftRight(t A[], int size)
    {
        t max;
        int position;
        for (int i = 0; i < size; i++)
        {
            max = 0;
            for (int j = i; j < size; j++)
            {
                if (A[j] > max)
                {
                    position = j;
                    max = A[j];
                }
            }
            ArrayBasics<int>::shiftRight(A, i, position);
            A[i] = max;
        }
    }
    static void maxSortWithSwap(t A[], int size)
    {
        t max;
        int position;
        for (int i = 0; i < size; i++)
        {
            max = A[i];
            position = i;
            for (int j = i+1; j < size; j++)
            {
                if (A[j] > max)
                {
                    position = j;
                    max = A[j];
                }
            }
            if (i != position)
                ArrayBasics<int>::swap(A, i, position);
        }
    }
};
// Equation for Max Sort with Right shift is T(n)= 8n^2 + 2n +4
// Equation for Max Sort with Swap is T(n)=  5n^2 +9n +4
// Both these lines intersect at 3. Meaning before this line Right shift sort has less time complexity whereas after it it time complexity is greater than that of swap sort.
// For n=(10, 100, 100), Time Complexity of Right Shift Sort is ( 824, 80804, 8008004) adn that of Swap Sort is (594, 50904, 5009004)


//      Question 2
template <class t>
class WarehouseAlgorithm
{
public:
    static bool hasClosePair(t arr[], t num, t ream)
    {
        for (int i = 0, j = 1; i < num+1-num/10; i++, j++)
        {
            if (arr[i] + arr[j] == ream)
                return true;
            else if ((j - i + 1) <= num / 10 && j < num)
                i--;
            else
                j = i + 1;
        }
        return false;
    }
};
// The worst r<n^2 O(n) algorithm would be that iterates through the whole array and gives the latest pair in the array that sums to be equal to r

//      Question 3
template <class t>
t maximizeProfit(int m, int n, int a[], int p[], int s)
{   
    int answer;
    int size = n;
    size++;
    int** maxProfitDP = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        maxProfitDP[i] = new int[m + 1];
    }
    size--;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) 
        {
            maxProfitDP[i][j] = 0;
            size++;
        }
    }
    int currentBarrels, currentProfit, fillProfit, notFillProfit;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            currentBarrels = a[i - 1];
            currentProfit = p[i - 1];
            size--;
            fillProfit = (currentBarrels <= j) ? (maxProfitDP[i - 1][j - currentBarrels] + currentProfit) : 0;
            notFillProfit = maxProfitDP[i - 1][j];
            size++;
            maxProfitDP[i][j] = (fillProfit > notFillProfit) ? fillProfit : notFillProfit;
        }
    }

    answer = maxProfitDP[n][m];
    size--;
    int barrelsSold = m;
    int storageCostAmount = 0;
    size++;
    for (int i = m; i >= 0; i--) {
        if (maxProfitDP[n][i] != maxProfitDP[n][i - 1]) {
            barrelsSold = i;
            break;
        }
    }

    storageCostAmount = (m - barrelsSold) * s;
    answer -= storageCostAmount;

    // Delete dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        delete[] maxProfitDP[i];
    }
    delete[] maxProfitDP;

    return answer;
}


//      Question 4
template<class t>
t** mergeBookingSchedules( int R1[][2], int n1, int R2[][2],int  n2,t mergedSchedule[][3], int m)
{
    int** arr = new int* [50];
    for (int i = 0; i < 50; i++)
        arr[i] = new int[3];
    
    int max=0;
    for (int i = 0; i < n1 + n2; i++)
    {
        if (i < n1)
        {
            arr[i][0] = 1;
            arr[i][1] = R1[i][0];
            arr[i][2] = R1[i][1];
            if (R1[i][1] > max)
                max = R1[i][1];
        }
        else
        {
            arr[i][0] = 2;
            arr[i][1] = R2[i-n1][0];
            arr[i][2] = R2[i - n1][1];
            if (R2[i][1] > max)
                max = R2[i][1];
        }
    }
    
    int** array = new int* [max];
    for (int i = 0; i < max; i++)
    {
        array[i] = new int[3];
        array[i][0] = 0;
        array[i][1] = i;
        array[i][2] = i+1;
    }

    for (int i = 0; i < n1 + n2; i++)
    {
        for (int j = arr[i][1]; j < arr[i][2]; j++)
            array[j][0]++;
    }

    for (int i = 0; i < max; i++)
        cout << array[i][0] << ',' << array[i][1] << ',' << array[i][2] << endl;

    t** ptr = new t* [50];
    for (int i = 0; i <= 50; i++) 
        ptr[i] = new t[3];
    
    return ptr;        
}

template<class t>
void makeBookingSchedules(int R1[][2], int n1, t Schedule[][3], int m)
{
}