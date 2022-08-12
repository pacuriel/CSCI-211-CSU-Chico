unsigned int product(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n >= 1) {
        return (n * product(n - 1));
    }
}
