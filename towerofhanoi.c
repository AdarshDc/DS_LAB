#include <stdio.h>
#include <math.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, int source, int temp, int dest)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, source, dest, temp);
    printf("\nMove disc %d from %c to %c ", n, source, dest);
    towerOfHanoi(n - 1,temp, source, dest);
}
void main()
{
    int n, res;
    printf("\n enter the number of disc:\n");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    res = pow(2, n) - 1;
    printf("the total number of moves are : %d", res);
}
