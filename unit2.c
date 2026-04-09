// 1. Area & Perimeter of Rectangle and Area & Circumference of Circle
#include <stdio.h>

int main() {
    float length, breadth, radius;
    float area_rect, perimeter_rect, area_circle, circumference;

    // Rectangle
    printf("Enter length and breadth of rectangle: ");
    scanf("%f %f", &length, &breadth);

    area_rect = length * breadth;
    perimeter_rect = 2 * (length + breadth);

    // Circle
    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    area_circle = 3.14 * radius * radius;
    circumference = 2 * 3.14 * radius;

    printf("\nRectangle Area = %.2f\n", area_rect);
    printf("Rectangle Perimeter = %.2f\n", perimeter_rect);
    printf("Circle Area = %.2f\n", area_circle);
    printf("Circle Circumference = %.2f\n", circumference);

    return 0;
}

====

// 2. Calculator using Ternary Operator
#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("Enter expression (e.g., 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);

    (op == '+') ? printf("Result = %.2f\n", a + b) :
    (op == '-') ? printf("Result = %.2f\n", a - b) :
    (op == '*') ? printf("Result = %.2f\n", a * b) :
    (op == '/') ? (b != 0 ? printf("Result = %.2f\n", a / b)
                          : printf("Division by zero error\n")) :
                  printf("Invalid operator\n");

    return 0;
}

================================

// 1. Armstrong Numbers from 1 to 500
#include <stdio.h>
#include <math.h>

int main() {
    int i, n, temp, sum, digits, remainder;

    printf("Armstrong numbers between 1 and 500:\n");

    for (i = 1; i <= 500; i++) {
        n = i;
        temp = n;
        sum = 0;
        digits = 0;

        // count digits
        while (temp != 0) {
            digits++;
            temp /= 10;
        }

        temp = n;

        // compute sum of powers
        while (temp != 0) {
            remainder = temp % 10;
            sum += pow(remainder, digits);
            temp /= 10;
        }

        if (sum == n)
            printf("%d ", n);
    }

    return 0;
}



// 2. Perfect Number Check
#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }

    if (sum == n)
        printf("Perfect Number\n");
    else
        printf("Not a Perfect Number\n");

    return 0;
}

================================

// 1. Reverse a String without using inbuilt functions
#include <stdio.h>

int main() {
    char str[100], rev[100];
    int i = 0, len = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    // find length
    while (str[len] != '\0') {
        len++;
    }

    // reverse
    for (i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';

    printf("Reversed string: %s\n", rev);

    return 0;
}

// 2. Average of n Marks using Arrays
#include <stdio.h>

int main() {
    int n, i;
    float marks[100], sum = 0, avg;

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("Enter marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    avg = sum / n;

    printf("Average = %.2f\n", avg);

    return 0;
}

================================

// 1. Maximum element in an array using pointers
#include <stdio.h>

int main() {
    int arr[100], n, i, max;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ptr = arr;       // pointer to first element
    max = *ptr;

    for(i = 1; i < n; i++) {
        if(*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    printf("Maximum element = %d\n", max);

    return 0;
}

// 2. Sum of digits using recursion
#include <stdio.h>

int sumDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Sum of digits = %d\n", sumDigits(num));

    return 0;
}

================================

// Array of Structures: Store, Display, Average, Sort by Roll No
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[5], temp;
    int i, j;
    float sum = 0, avg;

    // Input
    for(i = 0; i < 5; i++) {
        printf("Enter Roll No, Name, Marks for student %d:\n", i + 1);
        scanf("%d", &s[i].roll);
        scanf(" %[^\n]", s[i].name);
        scanf("%f", &s[i].marks);
        sum += s[i].marks;
    }

    // Average
    avg = sum / 5;
    printf("\nAverage Marks = %.2f\n", avg);

    // Sorting by Roll Number (Ascending)
    for(i = 0; i < 4; i++) {
        for(j = i + 1; j < 5; j++) {
            if(s[i].roll > s[j].roll) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display
    printf("\nStudent Details (Sorted by Roll No):\n");
    for(i = 0; i < 5; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }

    return 0;
}