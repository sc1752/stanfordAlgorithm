#include <iostream>
#include <string>
#include <algorithm>
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

string dePadding(string x)
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

void split(string x, string result[])
{
   // string result [2];
    int length = x.length();
    int offset = 0;
    if(length % 2 == 1)
    {
        offset = 1;
    }
    
    if(length <= 1)
    {
        result[0] = "0";
        result[1] = x;
    }
    else
    {
        result[0] = dePadding(x.substr(0,length/2 + offset));
        result[1] = dePadding(x.substr(length/2 + offset, length - length/2));
    }
}

string padding (string x, int zeros, bool suffix)
{
    string result = "";
    ///if(x.compare("0") != 0)
    //{
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
   // }
    //else
  //  {
    //    result = x;
   // }
    
    return  result;
}

string add(string x, string y)
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
string sub(string x, string y)
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

string karatsuba (string x, string y, int m)
{
    //cout << "x: " << x << " y: " << y  << " m: " << m << endl;
    
    if(m == 0)
    //if(x.length() == 1 && y.length() == 1)
    {
        return std::to_string(toInt(x[0]) * toInt(y[0]));
    }
    else if(x.compare("0") == 0 || y.compare("0") == 0)
    {
        return "0";
    }
    else
    {
        string result = "";
        string ab [2]; 
        string cd [2];
        int maxLen = std::max(x.length(), y.length());
        x = padding(x, maxLen - x.length(), false);
        y = padding(y, maxLen - y.length(), false);
        split(x, ab);
        split(y, cd);
        string ac = karatsuba(ab[0], cd[0], std::max(ab[0].length()/2, cd[0].length()/2));
        //cout << "ac: " << ac << endl;
        string bd = karatsuba(ab[1], cd[1], std::max(ab[1].length()/2, cd[1].length()/2));
        //cout << "bd " << bd << endl;
        string aPlusb = add(ab[0], ab[1]);
        //cout << "a+b " << aPlusb << endl;
        string cPLusd = add(cd[0], cd[1]);
        //cout << "c+d " << cPLusd<< endl;
        int m2 = std::max(aPlusb.length()/2, cPLusd.length()/2);
        string abcd = karatsuba(aPlusb, cPLusd, m2);
        string step3 = sub(abcd, ac);
        step3 = sub(step3, bd);

        if(ac.compare("0") != 0)
        {
            ac = padding(ac, m + m, true);
        }
        
        //cout << "ac padding: " << ac << endl;
        //cout << "bd " << bd << endl;
        //cout << "step3 " << step3 << endl;
        if(step3.compare("0") != 0)
        {
            step3 = padding(step3, m, true);
        }
        
        //cout << "step3 padding " << step3 << endl;
        result = add(add(ac, bd), step3); 
        
        //cout<< "result " << result << endl;
        return result;
        
    }

}

int TestSplit(string thing)
{
    string result[2];
    split(thing, result);
    std::cout << thing << " to become a: " << result[0] << " b: " << result[1] << std::endl;
}

int main()
{
    //string x = "3";
    //padding(&x, 0);
    string x = "3141592653589793238462643383279502884197169399375105820974944592";
    
    string y = "2718281828459045235360287471352662497757247093699959574966967627";
    //TestSplit("13433");
    cout << karatsuba(x, y, 32);
    //cout << dePadding("022003");
    //string result = karatsuba("1111","1001", 1);
    //cout << result;
    
    //cout << karatsuba("46", "134", 1) ;
    //cout << karatsuba("1234", "5678", 2) ;
    return 0;
}