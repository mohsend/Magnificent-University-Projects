/*
برنامه ای بنویسید که پنج عدد از کاربر دریافت کند و سپس از کاربر بپرسد مرتب نزولی باشد یا صعودی. سپس با توجه به انتخاب کاربر مرتب سازی را انجام دهد.
pointer to pointer
refrence
http://en.wikipedia.org/wiki/Selection_sort
*/

#include <iostream>

using namespace std;

int main()
{
    void input(int A[], int);
    void output(int A[], int);
    void selection_sort(int A[], int, bool(*)(int, int));
    bool ascending(int, int);
    bool descending(int, int);
    void swap(int&, int&);
	
    int A[5];
    input(A, 5);
    cout << "I'm gonna sort these values. How should I do this?\n1) Ascending\n2) Descending\nEnter your choice: ";
    int order;
    cin >> order;
    if (order == 1)
            selection_sort(A, 5, ascending);
    else 
            selection_sort(A, 5, descending);
        output(A, 5);		
	cin.ignore();
	cin.get();
    return 0;
}

void input(int A[], int n)
{
        cout << "Enter " << n << " integer numbers:\n";
        for (int i = 0; i < n; i++)
        {
                cout << i + 1 << ") ";
                cin >> A[i];
        }
}

void output(int A[], int n)
{
        cout << "Here are your sorted numbers:\n";
        for (int i = 0; i < n; i++)
                cout << i + 1 << ") " << A[i] << '\n';
}

void selection_sort(int A[], int n, bool(*fp)(int, int))
{
        for (int i = 0; i < n - 1; i++)
        {
            int index = i;
            for (int j = i; j < n; j++)
                    if ((*fp)(A[index], A[j]))
                            index = j;
            swap(A[index], A[i]);
        }
}

bool ascending(int a, int b)
{
    return (a > b);
}
bool descending(int a, int b)
{
   return (b > a);
}
void swap(int &p, int &q)
{
    int temp = q;
   q = p;
   p = temp;
}
