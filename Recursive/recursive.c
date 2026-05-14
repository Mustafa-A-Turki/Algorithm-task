#include <stdio.h>
#include <stdlib.h>

int countOccurrences(int A[], int index, int N, int cand)
{
    if (index == N)
    {
        return 0;
    }

    if (A[index] == cand)
    {
        return 1 + countOccurrences(A, index + 1, N, cand);
    }

    return countOccurrences(A, index + 1, N, cand);
}

int findDominator(int A[], int i, int N, int *cand, int *cnt)
{
    if (i == N)
    {
        int occurrences = countOccurrences(A, 0, N, *cand);

        if (occurrences > N / 2)
        {
            return *cand;
        }

        return -1;
    }

    if (*cnt == 0)
    {
        *cand = A[i];
        *cnt = 1;
    }
    else if (A[i] == *cand)
    {
        (*cnt)++;
    }
    else
    {
        (*cnt)--;
    }

    return findDominator(A, i + 1, N, cand, cnt);
}

int main()
{
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    if (N == 0)
    {
        printf("No dominator found.\n");
        return 0;
    }

    int *A = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    int cand = 0, cnt = 0;

    int dominator = findDominator(A, 0, N, &cand, &cnt);

    if (dominator != -1)
    {
        printf("\nDominator = %d\n", dominator);

        printf("Indices: ");

        for (int i = 0; i < N; i++)
        {
            if (A[i] == dominator)
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        printf("\n%d", dominator);
        printf("\nNo dominator");
    }

    return 0;
}
