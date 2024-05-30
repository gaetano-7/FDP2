// C++ recursive function to
// solve tower of hanoi puzzle
// using stacks (and printing stacks)
#include <iostream>
using namespace std;
#include <stack>

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;


    int x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";


    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

void print_rods_in_order(const stack<int> & from_rod,
                         const stack<int> & to_rod, const stack<int> & aux_rod, char f, char t, char a){
    if (f=='A') {cout<<"A | ";PrintStack(from_rod); cout<<endl;}
    else if (t=='A') { cout<<"A | ";PrintStack(to_rod); cout<<endl;}
    else if (a=='A') {cout<<"A | ";PrintStack(aux_rod); cout<<endl;}

    if (f=='B') {cout<<"B | ";PrintStack(from_rod); cout<<endl;}
    else if (t=='B')  {cout<<"B | ";PrintStack(to_rod); cout<<endl;}
    else if (a=='B') {cout<<"B | ";PrintStack(aux_rod); cout<<endl;}

    if (f=='C') {cout<<"C | ";PrintStack(from_rod); cout<<endl;}
    else if (t=='C')  {cout<<"C | ";PrintStack(to_rod); cout<<endl;}
    else if (a=='C') {cout<<"C | ";PrintStack(aux_rod); cout<<endl;}

    cout<<endl;

    return;
}

void towerOfHanoi(int n, stack<int> & from_rod,
                  stack<int> & to_rod, stack<int> & aux_rod, char f, char t, char a)
{
   // cout<<n<<" "<<f<<" "<<t<<" "<<a<<endl;
    if (n==1)
    {   to_rod.push(from_rod.top());
        from_rod.pop();
        print_rods_in_order(from_rod,to_rod,aux_rod,f,t,a);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,f,a,t);
    to_rod.push(from_rod.top());
    from_rod.pop();
    print_rods_in_order(from_rod,to_rod,aux_rod,f,t,a);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,a,t,f);
}

// Driver code
int main()
{
    stack<int> s,d,a;
	int n;
	cout<<"Set number of disks ";
	cin>>n;
	for (int i=n; i>=1; i--) s.push(i);
    cout<<"Stato iniziale"<<endl;
    cout<<"A | ";PrintStack(s); cout<<endl;
    cout<<"B | ";PrintStack(a); cout<<endl;
    cout<<"C | ";PrintStack(d); cout<<endl<<endl;
    towerOfHanoi(s.size(), s, d, a,'A','C','B'); // A, B and C are names of rods
    return 0;
}