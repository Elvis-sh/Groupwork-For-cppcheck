// Extra bad test: many uninitialized uses

int test_simple_uninit_extra() {
    int x;
    int y = x + 1;  // ERROR: x is uninitialized
    return y;
}

int test_repeated_use_extra() {
    int u;
    int v = u + u; // two uses of 'u'
    return v;
}

int test_many_repeats_extra() {
    int d;
    int e = d + d + d; // three uses of 'd'
    return e;
}

int test_param_extra2();
void use_value(int val);
void test_param_extra() {
    int a;
    use_value(a);  // ERROR
}

int test_multiple_extra() {
    int m, n;
    m = 10;
    int p = n + m; // ERROR: n
    return p;
}

// Combined to reach many warnings
int test_combined() {
    int A;
    int B = A + A; // two uses
    int C;
    int D = C; // one use
    return B + D;
}
