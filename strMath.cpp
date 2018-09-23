#include "strMath.h"
#include <string>
using namespace std;

//assume all imput char are numbers
int toInt(char a)
{
    return a - '0';
}

char c(int i)
{
    return i + '0';
}

std::string dePadding(std::string x)
{
    int numZero;
    for (numZero = 0; numZero < x.length() - 1; numZero++)
    {
        if(x[numZero] != '0')
        {
            break;
        }
    }
    
    x = x.substr(numZero, x.length() - numZero);
    
    return x;
}

std::string padding (std::string x, int zeros, bool suffix)
{
    string result = "";
    
    for (int i = 0; i < zeros; i++)
    {
        result += "0";
    }
    if(!suffix)
    {
        result += x;
    }
    else
    {
        result = x + result;
    }
    
    return  result;
}

std::string add(std::string x, std::string y)
{
    string result = "";
    int n = std::max(x.length(), y.length());
    string X = padding(x, n - x.length(), false);
    string Y = padding(y, n - y.length(), false);
    int extra = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int add = toInt(X[i]) + toInt(Y[i]) + extra;
        extra = 0;
        if(add >= 10)
        {
            add -= 10;
            extra = 1;
        }
        result = std::to_string(add) + result;
    }
    
    if(extra > 0)
    {
        result = "1" + result;
    }
    
    return result;
}

//assume a > b
std::string sub(std::string x, std::string y)
{
    string result = "";
    int n = std::max(x.length(), y.length());
    string X = padding(x, n - x.length(), false);
    string Y = padding(y, n - y.length(), false);
    int extra = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        int sub = toInt(X[i]) - toInt(Y[i]) - extra;
        extra = 0;
        if(sub < 0)
        {
            sub += 10;
            extra = 1;
        }
        result = std::to_string(sub) + result;
    }
    
    result = dePadding(result);
    
    return result;
}
