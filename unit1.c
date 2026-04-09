// 1. Arithmetic Operations
#include <stdio.h>

int main() {
    int a, b;
    float div;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Addition = %d\n", a + b);
    printf("Subtraction = %d\n", a - b);
    printf("Multiplication = %d\n", a * b);

    if (b != 0) {
        div = (float)a / b;
        printf("Division = %.2f\n", div);
        printf("Modulus = %d\n", a % b);
    } else {
        printf("Division and Modulus not possible (division by zero)\n");
    }

    return 0;
}

// 2. Pass/Fail and Grade using Ternary Operator
#include <stdio.h>

int main() {
    int marks;
    char grade;

    printf("Enter marks: ");
    scanf("%d", &marks);

    grade = (marks >= 90) ? 'A' :
            (marks >= 80) ? 'B' :
            (marks >= 70) ? 'C' :
            (marks >= 60) ? 'D' :
            (marks >= 35) ? 'E' : 'F';

    if (marks >= 35)
        printf("Result: PASS\n");
    else
        printf("Result: FAIL\n");

    printf("Grade: %c\n", grade);

    return 0;
}

=========================

// 1. Palindrome Number
#include <stdio.h>

int main() {
    int n, original, reverse = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n = n / 10;
    }

    if (original == reverse)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}


// 2. Pattern
#include <stdio.h>

int main() {
    int i, j;

    // Row 1
    for (j = 1; j <= 5; j++)
        printf("%d", j);
    printf("\n");

    // Rows 2 to 4
    for (i = 2; i <= 4; i++) {
        printf("%d", i);
        for (j = 1; j <= 2*i - 3; j++)
            printf(" ");
        printf("%d\n", 6 - i);
    }

    // Last row
    for (j = 5; j >= 1; j--)
        printf("%d", j);

    return 0;
}

=======================

// 1. Lower Triangular Matrix (including diagonal)
#include <stdio.h>

int main() {
    int a[10][10], i, j, r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Lower triangular matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(i >= j)
                printf("%d ", a[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}



// 2. Delete an element from array
#include <stdio.h>

int main() {
    int arr[100], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position\n");

    } else {
        for(i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}


=========================

// 1. Even and Odd Numbers in a Range using Recursion
#include <stdio.h>

void printNumbers(int start, int end) {
    if (start > end)
        return;

    if (start % 2 == 0)
        printf("%d is Even\n", start);
    else
        printf("%d is Odd\n", start);

    printNumbers(start + 1, end);
}

int main() {
    int start, end;

    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

    printNumbers(start, end);

    return 0;
}


// 2. Swap using Function Pointer (without third variable)
#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x, y;
    void (*fp)(int *, int *);

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    fp = swap;   // function pointer assignment
    fp(&x, &y);  // function pointer call

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

=========================

// Nested Structure: Employee with Address
#include <stdio.h>

struct Address {
    int house_no;
    char street[50];
    char city[50];
    int pin;
    long long phone;
};

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
    struct Address addr;
};

int main() {
    struct Employee e;

    // Input Employee Details
    printf("Enter Employee ID: ");     scanf("%d", &e.id);

    printf("Enter Name: ");    scanf(" %[^\n]", e.name);

    printf("Enter Department: ");     scanf(" %[^\n]", e.department);

    printf("Enter Salary: ");    scanf("%f", &e.salary);

    // Input Address Details
    printf("Enter House Number: ");     scanf("%d", &e.addr.house_no);

    printf("Enter Street: ");    scanf(" %[^\n]", e.addr.street);

    printf("Enter City: ");     scanf(" %[^\n]", e.addr.city);

    printf("Enter PIN Code: ");    scanf("%d", &e.addr.pin);

    printf("Enter Phone Number: ");    scanf("%lld", &e.addr.phone);

    // Output
    printf("\n--- Employee Details ---\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Department: %s\n", e.department);
    printf("Salary: %.2f\n", e.salary);

    printf("\n--- Address Details ---\n");
    printf("House No: %d\n", e.addr.house_no);
    printf("Street: %s\n", e.addr.street);
    printf("City: %s\n", e.addr.city);
    printf("PIN: %d\n", e.addr.pin);
    printf("Phone: %lld\n", e.addr.phone);

    return 0;
}

=========================