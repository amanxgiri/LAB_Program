#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;         // Coefficient of the term
    int exp;           // Exponent of the term
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
} Node;

// Function to create a new node
Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a term in polynomial (in descending order of exponents)
Node *insertTerm(Node *head, int coeff, int exp)
{
    // Skip terms with zero coefficient
    if (coeff == 0)
        return head;

    Node *newNode = createNode(coeff, exp);
    if (newNode == NULL)
        return head;

    // If list is empty or new term has highest exponent
    if (head == NULL || head->exp < exp)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    // Find the correct position to insert
    Node *current = head;
    while (current->next != NULL && current->next->exp > exp)
    {
        current = current->next;
    }

    // If term with same exponent exists, add coefficients
    if (current->exp == exp)
    {
        current->coeff += coeff;
        free(newNode);

        // If coefficient becomes zero, remove the term
        if (current->coeff == 0)
        {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;

            free(current);
        }
        return head;
    }

    // Insert the new node
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;

    return head;
}

// Function to display a polynomial
void displayPolynomial(Node *head, char polyName)
{
    if (head == NULL)
    {
        printf("Polynomial %c: 0\n", polyName);
        return;
    }

    printf("Polynomial %c: ", polyName);
    Node *current = head;
    int isFirst = 1;

    while (current != NULL)
    {
        if (current->coeff != 0)
        {
            // Handle sign
            if (!isFirst)
            {
                if (current->coeff > 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            else if (current->coeff < 0)
            {
                printf("-");
            }

            // Handle coefficient
            int absCoeff = abs(current->coeff);
            if (absCoeff != 1 || current->exp == 0)
            {
                printf("%d", absCoeff);
            }

            // Handle exponent
            if (current->exp > 1)
            {
                printf("x^%d", current->exp);
            }
            else if (current->exp == 1)
            {
                printf("x");
            }

            isFirst = 0;
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *p1 = poly1;
    Node *p2 = poly2;

    // Traverse both polynomials
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            // Same exponent - add coefficients
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) // Only insert if coefficient is non-zero
            {
                result = insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            // p1 has higher exponent
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else
        {
            // p2 has higher exponent
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // Add remaining terms from poly1
    while (p1 != NULL)
    {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Add remaining terms from poly2
    while (p2 != NULL)
    {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to create polynomial from user input
Node *createPolynomial(int polyNum)
{
    Node *head = NULL;
    int n, coeff, exp;

    printf("\n=== Creating Polynomial %d ===\n", polyNum);
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of terms!\n");
        return NULL;
    }

    printf("Enter terms (coefficient exponent):\n");
    printf("Note: Terms will be automatically sorted by exponent\n");

    for (int i = 0; i < n; i++)
    {
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &coeff);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &exp);

        if (exp < 0)
        {
            printf("Warning: Negative exponents not typically used in polynomials\n");
        }

        head = insertTerm(head, coeff, exp);
    }

    return head;
}

// Function to free memory of polynomial
void freePolynomial(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to validate polynomial structure (for debugging)
int validatePolynomial(Node *head)
{
    if (head == NULL)
        return 1;

    Node *current = head;
    while (current->next != NULL)
    {
        // Check if exponents are in descending order
        if (current->exp < current->next->exp)
        {
            printf("Error: Polynomial not in descending order!\n");
            return 0;
        }

        // Check if prev pointers are correct
        if (current->next->prev != current)
        {
            printf("Error: Incorrect prev pointer!\n");
            return 0;
        }

        current = current->next;
    }
    return 1;
}

// Function to get degree of polynomial
int getDegree(Node *head)
{
    if (head == NULL)
        return -1;
    return head->exp; // First term has highest exponent
}

// Function to evaluate polynomial at given value of x
double evaluatePolynomial(Node *head, double x)
{
    double result = 0.0;
    Node *current = head;

    while (current != NULL)
    {
        double term = current->coeff;
        for (int i = 0; i < current->exp; i++)
        {
            term *= x;
        }
        result += term;
        current = current->next;
    }

    return result;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;
    int choice;
    double x, value;

    printf("=== Polynomial Addition using Doubly Linked Lists ===\n");

    while (1)
    {
        printf("\n=== Menu ===\n");
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Display Result\n");
        printf("7. Get degrees of polynomials\n");
        printf("8. Evaluate polynomials\n");
        printf("9. Validate polynomial structure\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            if (poly1 != NULL)
            {
                freePolynomial(poly1);
            }
            poly1 = createPolynomial(1);
            if (poly1 != NULL)
            {
                printf("Polynomial 1 created successfully!\n");
                displayPolynomial(poly1, '1');
            }
            break;

        case 2:
            if (poly2 != NULL)
            {
                freePolynomial(poly2);
            }
            poly2 = createPolynomial(2);
            if (poly2 != NULL)
            {
                printf("Polynomial 2 created successfully!\n");
                displayPolynomial(poly2, '2');
            }
            break;

        case 3:
            displayPolynomial(poly1, '1');
            break;

        case 4:
            displayPolynomial(poly2, '2');
            break;

        case 5:
            if (poly1 == NULL || poly2 == NULL)
            {
                printf("Please create both polynomials first!\n");
                break;
            }

            if (result != NULL)
            {
                freePolynomial(result);
            }

            result = addPolynomials(poly1, poly2);
            printf("\n=== Polynomial Addition ===\n");
            displayPolynomial(poly1, '1');
            displayPolynomial(poly2, '2');
            printf("Sum:\n");
            displayPolynomial(result, 'R');
            break;

        case 6:
            if (result == NULL)
            {
                printf("No result available. Please add polynomials first!\n");
            }
            else
            {
                displayPolynomial(result, 'R');
            }
            break;

        case 7:
            printf("Degree of Polynomial 1: %d\n", getDegree(poly1));
            printf("Degree of Polynomial 2: %d\n", getDegree(poly2));
            printf("Degree of Result: %d\n", getDegree(result));
            break;

        case 8:
            printf("Enter value of x: ");
            scanf("%lf", &x);

            if (poly1 != NULL)
            {
                value = evaluatePolynomial(poly1, x);
                printf("Polynomial 1 at x=%.2f: %.2f\n", x, value);
            }

            if (poly2 != NULL)
            {
                value = evaluatePolynomial(poly2, x);
                printf("Polynomial 2 at x=%.2f: %.2f\n", x, value);
            }

            if (result != NULL)
            {
                value = evaluatePolynomial(result, x);
                printf("Result at x=%.2f: %.2f\n", x, value);
            }
            break;

        case 9:
            printf("Polynomial 1 validation: %s\n",
                   validatePolynomial(poly1) ? "Valid" : "Invalid");
            printf("Polynomial 2 validation: %s\n",
                   validatePolynomial(poly2) ? "Valid" : "Invalid");
            printf("Result validation: %s\n",
                   validatePolynomial(result) ? "Valid" : "Invalid");
            break;

        case 0:
            printf("Freeing memory and exiting...\n");
            freePolynomial(poly1);
            freePolynomial(poly2);
            freePolynomial(result);
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}