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
