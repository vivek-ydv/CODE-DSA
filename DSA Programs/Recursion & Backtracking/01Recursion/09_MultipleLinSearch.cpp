#include <iostream>
#include <vector>

using namespace std;
vector<int> v; // To store the multiple index, creating a global vector.

void findindex(int *A, int i, int target, int n)
{
    if (i == n)
    {
        return;
    }
    if (A[i] == target)
    {
        v.push_back(i);
    }
    findindex(A, i + 1, target, n);
}
int main()
{

    int A[] = {4, 2, 3, 1, 4, 4, 5};
    int target = 4;
    int n = (sizeof A / sizeof A[0]);

    findindex(A, 0, target, n);

    cout << "Indexes are :";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
