__attribute__((cdecl)) int foo(int a, int b, int c) {
    return a + b + c;
}

int main(int argc) {
    foo(1, 2, 3);
}