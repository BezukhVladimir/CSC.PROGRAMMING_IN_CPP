void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void reverse(int *from, int *to) {
    while (from < to)
        swap(from++, to--);
}

void rotate(int a[],
            const unsigned &size,
            unsigned shift) {
    if (size <= 1)
        return;
    
    if (shift %= size)
    {
        reverse(a, a + shift - 1);
        reverse(a + shift, a + size - 1);
        reverse(a, a + size - 1);
    }
}