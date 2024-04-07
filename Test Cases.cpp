#pragma once
#include <iostream>
using namespace std;

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
            if (A[i] = q)
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
                ans = middle; // Element found at index 'middle'
            else if (A[middle] < q)
                start = middle + 1;
            else
                end = middle - 1;
        }
        if (ans >= 0)
        {
            while (ans > 0 && A[ans - 1] == q)
            {
                ans--;
            }
        }
        return ans;
    }

};


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
            for (int j = i; j < size; j++)
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

template <class t>
class WarehouseAlgorithm
{
public:
    static bool hasClosePair(t arr[], t num, t ream)
    {
        for (int i = 0, j = 1; i < num; i++, j++)
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

