#include <iostream>
using namespace std;
 
template <typename T>
class GenericCalc
{
public:
    static T sum(T arg1, T arg2)
    {
        return arg1 + arg2;
    }
     
    static T subtract(T arg1, T arg2)
    {
        return arg1 - arg2;
    }
     
    static T divide(T arg1, T arg2)
    {
        return arg1 / arg2;
    }
     
    static T multiply(T arg1, T arg2)
    {
        return arg1 * arg2;
    }
};
 
int main()
{
    int i1;
    string segno;
    int i2;
    cin>>i1;
    cin>>segno;
    cin>>i2;
    if(segno=="+"){
        int isum = GenericCalc<int>::sum(i1, i2);
        cout << i1 << " + " << i2 << " = " << isum << "\n";
    }
    if(segno=="-"){
        int isum = GenericCalc<int>::subtract(i1, i2);
        cout << i1 << " - " << i2 << " = " << isum << "\n";
    }
    if(segno=="/"){
        int isum = GenericCalc<int>::divide(i1, i2);
        cout << i1 << " / " << i2 << " = " << isum << "\n";
    }
    if(segno=="*"){
        int isum = GenericCalc<int>::multiply(i1, i2);
        cout << i1 << " * " << i2 << " = " << isum << "\n";
    }
    return 0;
}