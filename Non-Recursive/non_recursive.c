#include <stdio.h>
int findDominator(int A[], int N)
{

    int candidate = A[0];
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (count == 0)

        {
            candidate = A[i];
            count = 1;
        }
        else if (A[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int occurrences = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == candidate)
        {
            occurrences++;
        }
    }
    if (occurrences > N / 2)
    {
        return candidate;
    }
    return -1;
}

int main(void)
{
    int N;
    printf("Enter array size N: ");
    scanf("%d", &N);
    if (N == 0)
    {
        printf("No dominator found.\n");
        return 0;
    }
    int A[N];
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int dominator = findDominator(A, N);
    if (dominator != -1)
    {
        printf("\nDominator value : %d\n", dominator);

        printf("Found at indices: ");

        for (int i = 0; i < N; i++)
        {
            if (A[i] == dominator)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }
    else
    {
        printf("\n%d",dominator);
        printf("\nNo dominator");
    }
    return 0;
}
