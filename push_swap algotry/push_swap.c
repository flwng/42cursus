#include "push_swap.h"

void	create_list_string(int **arr, t_list **a, char *argv, int *len)
{
	char	**split;
	int	iter;
	int	str_len;

	iter = 0;
	*len = 0;
	split = ft_split(argv, ' ');
	str_len = 0;
	if (split[str_len] == 0)
		exit(1);
	while (split[str_len++])
		(*len)++;
	*arr = malloc(sizeof(int) * str_len - 1);
	while (split[iter])
	{
		str_len = 0;
		while (split[iter][str_len])
		{
			if (!ft_isdigit(split[iter][str_len]))
				exit(1);
			str_len++;
		}
		(*arr)[iter] = ft_atoi(split[iter]);
		ft_lstadd_back(a, ft_lstnew((*arr)[iter++]));
	}
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 
// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
     
    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void timSort(int arr[], int n)
{
    // Sort individual subarrays of size 32
    for (int i = 0; i < n; i+=32)
        insertionSort(arr, i, min((i+32-1),
                                    (n-1)));
 
    // Start merging from size 32 (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = 32; size < n;
                             size = 2*size)
    {
         
        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int	order(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	algo(t_list **a, int *arr, int len)
{
	int	index;
	int	push = 0;
	int	n = 0;
	t_list	*start;
	t_list	*b;

	timSort(arr, len);
	index = 19;
	if (index >= len)
		index = len / 2;
	b = 0;
	while (!order(*a))
	{
		if ((*a)->content < arr[index])
		{
			pb(a, &b);
		/*	start = *a;
			printf("\n");
			while (*a)
			{
				printf("%d\n", (*a)->content);
				(*a) = (*a)->next;
			}
			*a = start;*/
			push++;
			n++;
		}
		else if ((*a)->content > ft_lstlast(*a)->content)
		{
			/*start = *a;
				printf("\n");
			while (*a)
			{
				printf("%d\n", (*a)->content);
				(*a) = (*a)->next;
			}
			*a = start;*/
			ra(a);
			n++;
		}
		else if ((*a)->content > (*a)->next->content)
		{
			sa(a);
			/*start = *a;
				printf("\n");
			while (*a)
			{
				printf("%d\n", (*a)->content);
				(*a) = (*a)->next;
			}
			*a = start;*/
			n++;
		}
		else
		{
			ra(a);
			/*start = *a;
				printf("\n");
			while (*a)
			{
				printf("%d\n", (*a)->content);
				(*a) = (*a)->next;
			}
			*a = start;*/
			n++;
		}	
	}
	while (b)
	{
		if ((*a)->content == arr[index - 1])
			index--;
		if (b->content == arr[index - 1] && (*a)->content > arr[index - 1])
		{
			pa(a, &b);
			index--;
			n++;
		}
		else if (b->content != arr[index - 1] && (*a)->content < arr[index - 1])
		{
			rr(a, &b);
			n++;
		}
		else if ((*a)->content < arr[index - 1])
		{
			ra(a);
			n++;
		}
		else
		{
			rb(&b);
			n++;
		}
	}
	while ((*a)->content != arr[0])
	{
		rra(a);
		n++;
	}
	start = *a;
	while (*a)
	{
		printf("%d\n", (*a)->content);
		(*a) = (*a)->next;
	}
	*a = start;
	printf("moves = %d\n", n);
	printf("\n");
	int i = 0;
	while (i < len)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_list	*a;
	int	i;
	int	*arr;
	int	iter;
	int	len;

	if (argc <= 1)
		exit(1);
	if (argc > 2)
	{
		len = argc - 1;
		arr = malloc(sizeof(int) * (argc - 1));
		i = 1;
		iter = 0;
		while (argv[i])
		{
			if (!ft_isdigit(*argv[i]))
				exit(1);
			arr[iter++] = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
		}
	}
	if (argc == 2)
		create_list_string(&arr, &a, argv[1], &len);		
	algo(&a, arr, len);
}
