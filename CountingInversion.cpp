#include "strMath.h"
#include <fstream>
#include <iostream>
using namespace std;

void readFile (int list[], int counter);
void printArray (int list[], int start, int end);
//int sortAndCount(int list[], int start, int end);
//int mergeAndCount(int list[], int start, int mid, int end);
//int countInversions(int list[], int size);
void countInversions(int list[], int size);
string sortAndCount(int list[], int start, int end);
string mergeAndCount(int list[], int start, int mid, int end);

void readFile (int list[], int counter)
{
    std::ifstream file;
    file.open("IntegerArray.txt");
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

/*
int sortAndCount(int list[], int start, int end)
{
    int inversions = 0; 
    
    if(start == end)
    {
        
    }
    else
    {
        //int length = end - start;
        int mid = (end + start) / 2;
        inversions += sortAndCount(list, start, mid);
        inversions += sortAndCount(list, mid + 1, end);
        inversions += mergeAndCount(list, start, mid, end);
    }
    
    return inversions;
}
*/

string sortAndCount(int list[], int start, int end)
{
    string inversions = "0"; 
    
    if(start == end)
    {
        
    }
    else
    {
        //int length = end - start;
        int mid = (end + start) / 2;
        inversions = add(inversions, sortAndCount(list, start, mid));
        inversions = add(inversions, sortAndCount(list, mid + 1, end));
        inversions = add(inversions, mergeAndCount(list, start, mid, end));
    }
    
    return inversions;
}

/*
int mergeAndCount(int list[], int start, int mid, int end)
{
    int i = start;
    int iRemain = mid - start + 1;
    int j = mid + 1;
    int jRemain = end - mid; 
    int k = 0; 
    int sorted [end + 1 - start];
    int inversions = 0;
    
    for (k = 0; k <= end - start; k++)
    {
        if(iRemain <= 0)
        {
            sorted[k] = list[j];
            j++;
            jRemain --;
        }
        else if (jRemain <= 0)
        {
            sorted[k] = list[i];
            i++;
            iRemain--;
        }
        else
        {
            if(list[i] < list[j])
            {
                sorted[k] = list[i];
                i++;
                iRemain--;
            }
            else
            {
                sorted[k] = list[j];
                j++;
                jRemain--;
                inversions += iRemain;
            }
        }
    }
    
    for (k = 0; k <= end - start; k++)
    {
        list[start + k] = sorted[k];
    }
    
    return  inversions;
}
*/

string mergeAndCount(int list[], int start, int mid, int end)
{
    int i = start;
    int iRemain = mid - start + 1;
    int j = mid + 1;
    int jRemain = end - mid; 
    int k = 0; 
    int sorted [end + 1 - start];
    string inversions = "0";
    
    for (k = 0; k <= end - start; k++)
    {
        if(iRemain <= 0)
        {
            sorted[k] = list[j];
            j++;
            jRemain --;
        }
        else if (jRemain <= 0)
        {
            sorted[k] = list[i];
            i++;
            iRemain--;
        }
        else
        {
            if(list[i] < list[j])
            {
                sorted[k] = list[i];
                i++;
                iRemain--;
            }
            else
            {
                sorted[k] = list[j];
                j++;
                jRemain--;
                string remain = std::to_string(iRemain);
                inversions = add(inversions, remain);
            }
        }
    }
    
    for (k = 0; k <= end - start; k++)
    {
        list[start + k] = sorted[k];
    }
    
    return  inversions;
}


void testCases()
{
    int test1 [] = {5, 4, 3, 2, 1};
    std::cout << sortAndCount(test1, 0, 4) << std::endl;
    
    int test2[] = { 9, 12, 3, 1, 6, 8, 2, 5, 14, 13, 11, 7, 10, 4, 0 };
    std::cout << sortAndCount(test2, 0, 14) << std::endl;
    
    int test3[] = { 3, 1, 2 };
    std::cout << sortAndCount(test3, 0, 2) << std::endl;
    
    int test4[] = { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4,
      28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 
      9, 49, 22, 23, 30, 45 };
    std::cout << sortAndCount(test4, 0, 49) << std::endl;
}

/*
int countInversions(int list[], int size)
{
    return sortAndCount(list, 0, size - 1);
}
*/

void countInversions(int list[], int size)
{
    std::cout << sortAndCount(list, 0, size - 1);
}

int main()
{
    testCases();
    int size = 100000;
    int arrayList [size];
    readFile(arrayList, size);
    countInversions(arrayList, 100000);

}