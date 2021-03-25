/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author <Bella Sabeva>
* @idnumber <62188>
* @task <2>
* @compiler < GCC >
*
*/

#include <cstring>
#include <iostream>
using namespace std;
void searchString(char* B, char* C, int* countMax, int* indexMax)
{
    if (B == nullptr)
        return;
    if (C == nullptr)
        return;
    unsigned int count = 0;
    unsigned int index = 0;
    unsigned int diff = 0;
    if (strlen(C) > strlen(B)) {
        (*countMax) = 0;
        (*indexMax) = -1;
        return;
    }

    for (unsigned int i = 0, j = 0; i < strlen(B); i++) {
        if (B[i] == C[j]) {
            if (count == 0) {
                index = i;
            }
            j++;
            count++;
            if (j == strlen(C)) {
                j = 0;
            }
        }
        else {
            diff = count % strlen(C);
            if (diff > 0) {
                count -= diff;
            }

            if ((*countMax) < count && count >= strlen(C)) {

                (*countMax) = count;
                (*indexMax) = index;
            }
            count = 0;
            j = 0;
        }
    }

    diff = count % strlen(C);

    if (diff > 0) {
        count -= diff;
    }

    if ((*countMax) < count && count >= strlen(C)) {

        (*countMax) = count;
        (*indexMax) = index;
    }
}

int main()
{
    char B[100];
    cout << "Input B..";
    cin.getline(B, 100, '\n');
    if(!cin)
    {
        return 1;
    }
    char C[100];
    cout << "Input C..";
    cin.getline(C, 100, '\n');
    if(!cin)
    {
        return 1;
    }
    int countMax = 0;
    int indexMax = -1;
    searchString(B, C, &countMax, &indexMax);
    cout << "Index: " << indexMax << endl;
    cout << "Length: " << countMax;
    return 0;
}
