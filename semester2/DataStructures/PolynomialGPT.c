#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term of the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Term* polynomial = NULL;

    // Insert some terms into the polynomial
    insertTerm(&polynomial, 3, 4);
    insertTerm(&polynomial, -2, 3);
    insertTerm(&polynomial, 5, 2);
    insertTerm(&polynomial, 7, 0);

    // Display the polynomial
    displayPolynomial(polynomial);

    // Free memory
    while (polynomial != NULL) {
        Term* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}
