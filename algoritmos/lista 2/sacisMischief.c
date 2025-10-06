#include <stdio.h>

struct Student {
    char name[20];
    int grade;
    int age;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    struct Student students[5];
    
    for (int i = 0; i < 5; i++) {
      fgets(students[i].name, 20, stdin);
      students[1].name[strcspn(students[i].name, "\n")] = '\0';
      scanf("%f %d", &students[i].grade, &students[i].age);
      getchar();
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {

        }
    }
    
    for (int i = 0; i < 4; i++) {
        
    }

    return 0;
}