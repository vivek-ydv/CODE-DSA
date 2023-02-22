#include <iostream>
using namespace std;

int main()
{
    cout << "About Containers";
    /*
    ----------------------------------------------------------------------------------------------------
    Containers:-Object which stores data
    Types of Containers:-
                       ------------------------------------------------------------------- 
                       1.Sequence containers :>Data in linear fashion:-
                                                                      1.Vector
                                                                      2.List 
                                                                      3.Deque 
                       ------------------------------------------------------------------- 
                       2.Associative containers :>Data in key-value pair fashion and support
                                                  Fast lookup(Direct acess):-
                                                                            1.Set
                                                                            2.Multiset
                                                                            3.Map
                                                                            4.Multimap
                       ------------------------------------------------------------------- 
                       3.Derived Containers :>Deriverd from Seq or Assoc Containers 
                                              Real world modelling:-
                                                                   1.Stack
                                                                   2.Queue
                                                                   3.Priority_queue
                       -------------------------------------------------------------------
    NOTE:- The sequence and assssociative containers are collectively referred as "First Class Containers"
    --------------------------------------------------------------------------------------
    ********************************When to use Which!?********************************
    --------------------------------------------------------------------------------------
    1.Sequence Containers:- 
                         1.Vectors:
                                  ->Random Acess - Fast
                                  ->Insertion/Deletion in Middle/Random Position - Slow
                                  ->Insertion/Deletion at End - Fast
                         2.List:
                               ->Random Acess - Slow     
                               ->Insertion/Deletion in Middle/Random Position - Fast
                               ->Insertion/Deletion at End - Slow
    ----------------------------------------------------------------------------------------                           
    2.Associative Containers:- All Opertions are Fast except the Random Acess
    ----------------------------------------------------------------------------------------                           
    3.Derived Containers:- Depends on the Data Structure
    ----------------------------------------------------------------------------------------------------
    */
    return 0;
}