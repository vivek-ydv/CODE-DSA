#include <iostream>

using namespace std;

int checksort(int *A, int i, int n)
{
    if (i == n)
    {
        return 1;
    }
    if (A[i] < A[i + 1] || A[i] == A[i + 1])
    {
        i++;
        return checksort(A, i, n);
    }
    else
        return -1;
}
int main()
{
    int A[] = {1, 2, 2, 3, 4, 5, 61, 16};
    int n = ((sizeof(A) / sizeof(A[0])) - 1);
    cout << checksort(A, 0, n);

    return 0;
}
