/*
 There is a method to check whether the given state is solvable or not.
 
 Problem State:
 
 1|2|3
 -+-+-
 4|5|6
 -+-+-
 |8|7
 Write it in a linear way, 1,2,3,4,5,6,8,7 - Ignore the blank tile
 
 Now find the number of inversion, by counting tiles precedes the another tile with lower number.
 
 In our case, 1,2,3,4,5,6,7 is having 0 inversions, and 8 is having 1 inversion as it's preceding the number 7.
 
 Total number of inversion is 1 (odd number) so the puzzle is insolvable.
 
 Let's take another example,
 
 5|2|8
 -+-+-
 4|1|7
 -+-+-
 |3|6
 5 precedes 1,2,3,4 - 4 inversions
 2 precedes 1 - 1 inversion
 8 precedes 1,3,4,6,7 - 5 inversions
 4 precedes 1,3 - 2 inversions
 1 precedes none - 0 inversions
 7 precedes 3,4 - 2 inversions
 3 precedes none - 0 inversions
 6 precedes none - 0 inversions
 
 total inversions 4+1+5+2+0+2+0+0 = 14 (Even Number) So this puzzle is solvable.
 
 https://math.stackexchange.com/questions/293527/how-to-check-if-a-8-puzzle-is-solvable
 */

#include <iostream>
using namespace std;

int inversionCount(int arr[])
{
    int counter = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i+1; j < 9; j++) {
            if (arr[j] != 0 && arr[i] != 0 &&  arr[i] > arr[j]) {
                counter++;
            }
        }
    
    return counter;
}

bool isSolvable(int puzzle[3][3]) {
    return (inversionCount((int *)puzzle)%2 == 0);
}

void inputPuzzle(int puzzle[][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            cout << "Enter: puzzle[" << i << "][" << j << "] = ";
            cin >> puzzle[i][j];
        }
}

int main()
{
    int puzzle[3][3];
    int destinationPuzzle[3][3];
    
    cout << "Enter init state: " << endl;
    inputPuzzle(puzzle);
    
    //TODO: check with destinationPuzzle
    cout << "Enter goal state: " << endl;
    inputPuzzle(destinationPuzzle);
    
    cout << "Result: " << isSolvable(puzzle) << endl;
    
    return 0;
}


