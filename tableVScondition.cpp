#include <iostream>

using namespace std;

int main()
{
    clock_t start1 = clock();
    int category = 0;
    for(int i = 0; i < 100000000; i++) {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;
        if ((a && !c)||(a && b && c)) {
            category = 1;
        }
        else if ((b && !a)||(a && c && !b)) {
            category = 2;
        }
        else if (c && !a && !b) {
            category = 3;
        }
        else {
            category = 0;
        } 
    }
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("The time hard condition: %f seconds\n", seconds1);
    
    static int categoryTable[2][2][2] = {
        0, 3, 2, 2,
        1, 2, 1, 1
    };

    clock_t start2 = clock();
    for(int i = 0; i < 100000000; i++) {
        int a = rand() % 2;
        int b = rand() % 2;
        int c = rand() % 2;
        category = categoryTable[a][b][c];
    }
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("The time table: %f seconds\n", seconds2);

    return 0;
}
