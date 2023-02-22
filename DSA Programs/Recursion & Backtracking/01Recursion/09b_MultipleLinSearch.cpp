#include <iostream>
#include <vector>

using namespace std;
// In same problem we will do it with the the another method
// i.e. returning the vector itself to the calling function by passing the vector in the argument

vector<int> findindex(int *A, int i, int target, int n, vector<int> vec)
{
    if (i == n)
    {
        return vec;
    }
    if (A[i] == target)
    {
        vec.push_back(i);
    }
    return findindex(A, i + 1, target, n, vec);
}
int main()
{
    int A[] = {4, 2, 3, 1, 4, 4, 5};
    vector<int> vec; // creating the empty vector
    int n = (sizeof A / sizeof A[0]);
    int target = 4;

    vector<int> res = findindex(A, 0, target, n, vec); // Calling and storing the result in the variable of return data type

    cout << "Indexes are :";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
