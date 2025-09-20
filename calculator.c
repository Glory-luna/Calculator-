#include <stdio.h>
#include <math.h>

void Addition(int digits[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += digits[i];
    printf("Result = %d\n", sum);
}

void Subtraction(int digits[], int n) {
    int sub = digits[0];
    for(int i = 1; i < n; i++)
        sub -= digits[i];
    printf("Result = %d\n", sub);
}

void Multiplication(int digits[], int n) {
    double mul = digits[0];
    for(int i = 1; i < n; i++)
        mul *= digits[i];
    printf("Result = %.2f\n", mul);
}

void Division(int digits[], int n) {
    double div = digits[0];
    for(int i = 1; i < n; i++) {
        if(digits[i] == 0) {
            printf("Error: Division by zero!\n");
            return;
        }
        div /= digits[i];
    }
    printf("Result = %.2f\n", div);
}

void Modular(int digits[], int n) {
    int mod = digits[0];
    for(int i = 1; i < n; i++) {
        if(digits[i] == 0) {
            printf("Error: Modulo by zero!\n");
            return;
        }
        mod %= digits[i];
    }
    printf("Result = %d\n", mod);
}

void Power(int digits[], int n) {
    double p = digits[0];
    for(int i = 1; i < n; i++)
        p = pow(p, digits[i]);
    printf("Result = %.2f\n", p);
}

int main() {
    int choice, n, con;
    int digits[100]; // Fixed max size to prevent crash

    do {
        printf("\nMENU:\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n5. MODULAR\n6. POWER\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        printf("ENTER HOW MANY NUMBERS YOU WANT TO INSERT: ");
        scanf("%d", &n);

        if(n <= 0 || n > 100) {
            printf("Invalid number of inputs!\n");
            continue;
        }

        for(int i = 0; i < n; i++) {
            printf("Enter number %d: ", i+1);
            scanf("%d", &digits[i]);
        }



        
        switch(choice) {
            case 1: Addition(digits, n); break;
            case 2: Subtraction(digits, n); break;
            case 3: Multiplication(digits, n); break;
            case 4: Division(digits, n); break;
            case 5: Modular(digits, n); break;
            case 6: Power(digits, n); break;
            default: printf("INVALID CHOICE!\n"); break;
        }

        printf("PRESS 1 IF YOU WANT TO CONTINUE: ");
        scanf("%d", &con);

    } while(con == 1);

    return 0;
}
