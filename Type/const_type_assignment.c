
foo(const char **p) {}
bar(const char *p) {}

int main(int argc, char **argv) 
{
    char * s;
    foo(argv);
    bar(s);
    return 0;
}

