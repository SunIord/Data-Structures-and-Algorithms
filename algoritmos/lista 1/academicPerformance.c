// cd "algoritmos\lista 1"
// g++ academicPerformance.c -o academic
// ./academic

#include <stdio.h>

struct Student {
    char name[100];
    char course[100];
    int age;
    float grade;
};

void readStudent(struct Student *s) {
    fgets(s->name, sizeof(s->name), stdin);
    fgets(s->course, sizeof(s->course), stdin);
    scanf("%d", &s->age);
    scanf("%f", &s->grade);
    getchar();
}

void printStudent(struct Student s, int number) {
    printf("Estudante %d:\n", number);
    printf("Nome: %s", s.name);
    printf("Curso: %s", s.course);
    printf("Idade: %d\n", s.age);
    printf("Nota: %.1f\n\n", s.grade);
}

int main() {
    struct Student s1, s2;
    float average;

    readStudent(&s1);
    readStudent(&s2);

    average = (s1.grade + s2.grade) / 2;

    printStudent(s1, 1);
    printStudent(s2, 2);

    printf("Media geral: %.1f\n", average);

    return 0;
}