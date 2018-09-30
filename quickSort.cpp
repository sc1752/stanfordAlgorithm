#include "strMath.h"
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

enum partitionType {first, median, last};

void readFile (int list[], int counter);
void printArray (int list[], int start, int end);
void quickSort(int A[], int l, int r, partitionType pType);
int partition(int A[], int l, int r, partitionType pType);

int partitionFirst(int A[], int l, int r);
int partitionLast(int A[], int l, int r);
int partitionMid(int A[], int l, int r);

//unsigned long long int count = 0;
//float count = 0;
string sCount = "0";

//TODO: seperate out
void readFile (int list[], int counter)
{
    std::ifstream file;
    file.open("QuickSort.txt");
    int i = 0; 
    while (i < counter)
    {
        file >> list[i];
        i++;
    }
    file.close();
}

void printArray (int list[], int start, int end)
{
    int i = start;
    while (i <= end)
    {
        cout << list[i] << " ";
        i++;
    }
    std::cout <<  std::endl;
}

void quickSort(int A[], int l, int r, partitionType pType)
{
    if(l >= r || l < 0)
    {
        return;
    }
    else 
    {
        int p = partition(A, l, r, pType);
        
        quickSort(A, l, p - 1, pType);
        quickSort(A, p + 1, r, pType);
    }
}

int partition(int A[], int l, int r, partitionType pType)
{

    if(pType == partitionType::first)
    {

    }
    else if (pType == partitionType::last)
    {
        std::swap(A[l], A[r]);
    }
    else if (r - l > 1 && pType == partitionType::median)
    {
        int first = A[l];
        int last = A[r];
        int mid = A[(r + l)/2];
        if ((last > mid && last < first) || last < mid && last > first)
        {
            std::swap(A[r], A[l]);
        }
        else if ((mid < last && mid > first) || mid > last && mid < first)
        {
            std::swap(A[(r+l)/2], A[l]);
        }
    }
    
    int p = l;
    int pivot = A[l];

    int i = l + 1;
    for (int j = l + 1; j <= r; j++)
    {
        if(A[j] < pivot)
        {
            std::swap(A[j], A[i]);
            i++;
            //printArray (A, 0, 4);

        }
        //count++;
        //
    }
    sCount = add(sCount, std::to_string(r - l));
    
    std::swap(A[p], A[i-1]);
    //printArray (A, 0, 4);
    
    return i - 1;
}

int main()
{
    int size = 10000;
    int list [size];
    readFile(list, size);
    //printArray (list, 0, size -1);
    quickSort(list, 0, size - 1, partitionType::first);
    //printArray (list, 0, size -1);
    //std::cout << count << endl;
    std::cout << sCount << endl;

    readFile(list, size);
    sCount = "0";
    quickSort(list, 0, size - 1, partitionType::last);
    std::cout << sCount << endl;
    
    readFile(list, size);
    sCount = "0";
    quickSort(list, 0, size - 1, partitionType::median);
    std::cout << sCount << endl;

    return 0;
}
