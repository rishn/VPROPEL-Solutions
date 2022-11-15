//INPUT
/*
5
1
3
4
2
1
3
1
2
4
*/

//OUTPUT
/*
1
1
2
4
3

*/

//ALGORITHM/PSEUDOCODE
/*
Depend_Sort(int array A, int array B, int m, int n)
{
	m <- size of A
	n <- size of B
	k <- 0
	i <- 0
	until (i >= n)
	{
		j <- 0
		until (j >= m)
		{
			if (a[j] == b[i])
			{
				swap a[j] and a[k]
				k += 1
			}
			j += 1
		}
		i += 1
	}
	i <- k
	until (i >= m)
	{
		min <- a[i]
		j <- i + 1
		until (j >= m)
		{
			if (a[j] < min)
			{
				min <- a[j]
				index <- j
			}
			j += 1
		}
		swap a[i] and a[index]
		i += 1
	}
	return a
}
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int *depend_sort(int *a, int *b, int m, int n)
{
	int i, j, min, temp, k = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (a[j] == b[i])
			{
				temp = a[k];
				a[k++] = a[j];
				a[j] = temp;
			}
	for (i = k; i < m; i++)
	{
		min = a[i];
		for (j = i + 1; j < m; j++)
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
	return a;
}
int main()
{
	int i, m, n;
	scanf("%d", &m);
	int *a = (int *)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	a = depend_sort(a, b, m, n);
	for (i = 0; i < m; i++)
		printf("%d", a[i]);
	return 0;
}