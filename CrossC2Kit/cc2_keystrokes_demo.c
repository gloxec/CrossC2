#include <stdio.h>

int crossc2_entry(int argc, char **argv) {
    printf("into crossc2_entry():\n");
    printf("\t-> argc = %d\n", argc);
    int i = 0;
    for (i = 0; i < argc; ++i) {
        printf("\t->%s\n", argv[i]);
    }

    printf("test demo\n");
    printf("User keyboard input: ssh root@10.14.11.32\n");
    printf("test_username\n");
    printf("pwd_123467aaa\n");
    printf("ifconfig\n");
    printf("[Ctrl-D]\n");

    return 1;
}
