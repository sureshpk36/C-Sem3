#include <stdio.h>

struct employee {
    char name[10];
    int eid;
    float salary;
};

int main() {
    struct employee e[5];

    for (int i = 0; i < 5; i++) {
        scanf("%s", e[i].name);
        scanf("%d", &e[i].eid);
        scanf("%f", &e[i].salary);
    }

    for (int i = 0; i < 5; i++) {
        printf("%s ", e[i].name);
        printf("%d ", e[i].eid);
        printf("%f\n", e[i].salary);
    }

    return 0;
}
