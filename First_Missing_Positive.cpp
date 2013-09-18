/*
   from anson, great. index and value, return index, who knows.
 */
int firstMissingPositive(int A[], int n) {
    int i = 0;
    while (i < n) {
        if (A[i] != i + 1 && A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i] - 1]);
        } else
            i++;
    }
    for (i = 0; i < n; i++)
        if (A[i] != i + 1)
            break;
    return i + 1;
}

// second try, almost same, not that better
int firstMissingPositive(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    for(int i=0;i<n;i++)
    {
        if(A[i]<=0||A[i]>n||A[i]-1==i||A[A[i]-1]==A[i])continue;
        else
        {
            int tmp=A[A[i]-1];
            A[A[i]-1]=A[i];
            A[i]=tmp;
            i--;
        }
    }
    int i=1;
    for(int j=0;j<n;j++)
    {
        if(A[j]==i)
        {
            i++;
        }
        else
        {
            return j+1;
        }
    }
    return i;
}
