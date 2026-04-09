// 1. Relational Operations
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("a < b  = %d\n", a < b);
    printf("a > b  = %d\n", a > b);
    printf("a == b = %d\n", a == b);
    printf("a <= b = %d\n", a <= b);
    printf("a >= b = %d\n", a >= b);
    printf("a != b = %d\n", a != b);

    return 0;
}


// 2. Character Classification using Ternary Operator
#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    (ch >= '0' && ch <= '9') ? printf("Digit\n") :
    ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) ? printf("Vowel\n") :
    ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? printf("Consonant\n") :
    printf("Special Symbol\n");

    return 0;
}


========================

// a. Pattern
// ****
// *  *
// *  *
// ****
#include <stdio.h>

int main() {
    int i, j;

    for(i = 1; i <= 4; i++) {
        for(j = 1; j <= 4; j++) {
            if(i == 1 || i == 4 || j == 1 || j == 4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}


// b. Pattern
// 01010
// 01010
// 01010
// 01010
#include <stdio.h>

int main() {
    int i, j;

    for(i = 1; i <= 4; i++) {
        for(j = 1; j <= 5; j++) {
            if(j % 2 == 1)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }

    return 0;
}

=========================

// 1. Concatenate strings without using inbuilt function
#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i = 0, j = 0;

    printf("Enter first string: ");
    scanf(" %[^\n]", str1);

    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    // move to end of str1
    while (str1[i] != '\0') {
        i++;
    }

    // concatenate str2 to str1
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}

// 2. Check Identity Matrix
#include <stdio.h>

int main() {
    int a[10][10], i, j, n, flag = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && a[i][j] != 1)
                flag = 0;
            if(i != j && a[i][j] != 0)
                flag = 0;
        }
    }

    if(flag == 1)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}

=========================

// 1. Access array elements using function pointer
#include <stdio.h>

void display(int *arr, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[100], n, i;
    void (*fp)(int *, int);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    fp = display;   // function pointer assignment
    fp(arr, n);     // function pointer call

    return 0;
}


// 2. Count even and odd numbers using pointers
#include <stdio.h>

int main() {
    int arr[100], n, i;
    int even = 0, odd = 0;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    for(i = 0; i < n; i++) {
        if(*(ptr + i) % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even count = %d\n", even);
    printf("Odd count = %d\n", odd);

    return 0;
}

=========================

// Nested Structures: Student with Address (3 students)
#include <stdio.h>

struct Address {
    int house_no;
    char street[50];
    char city[50];
    char state[50];
    int pin;
};

struct Student {
    int roll;
    char name[50];
    struct Address addr;
};

int main() {
    struct Student s[3];
    int i;

    // Input
    for(i = 0; i < 3; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("House No: ");
        scanf("%d", &s[i].addr.house_no);

        printf("Street: ");
        scanf(" %[^\n]", s[i].addr.street);

        printf("City: ");
        scanf(" %[^\n]", s[i].addr.city);

        printf("State: ");
        scanf(" %[^\n]", s[i].addr.state);

        printf("PIN: ");
        scanf("%d", &s[i].addr.pin);
    }

    // Output
    printf("\n--- Student Details ---\n");
    for(i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Address: %d, %s, %s, %s - %d\n",
               s[i].addr.house_no,
               s[i].addr.street,
               s[i].addr.city,
               s[i].addr.state,
               s[i].addr.pin);
    }

    return 0;
}