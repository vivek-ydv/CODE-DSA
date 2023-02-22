#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> MarksMap;

    MarksMap["Harry"] = 98;
    MarksMap["Akash"] = 95;
    MarksMap["Vivek"] = 99;

    MarksMap.insert({{"Saurabh", 100}, {"Shashank", 97}}); // For the insertion of the element
  
    map<string, int>::iterator iter;
    for (iter = MarksMap.begin(); iter != MarksMap.end(); iter++)
    {
        cout << (*iter).first << ": " << (*iter).second << endl;
    }

    // Simply we can use range based loop for acessing the loop :--
    // for (auto &&i : MarksMap)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    cout << "The size of map is: " << MarksMap.size() << endl;
    cout << "The max size of map is: " << MarksMap.max_size() << endl;
    cout << "The empty's return value is: " << MarksMap.empty() << endl;
    return 0;
}