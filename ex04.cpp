#include <stdio.h>

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap vao so phan tu va tung phan tu\n");
    printf("2. In ra cac phan tu la so chan\n");
    printf("3. In ra cac phan tu la so nguyen to\n");
    printf("4. Dao nguoc mang\n");
    printf("5. Sap xep mang\n");
    printf("   1. Tang dan\n");
    printf("   2. Giam dan\n");
    printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
    printf("7. Thoat\n");
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inputArray(int **arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    *arr = (int *)malloc(*n * sizeof(int));
    printf("Nhap cac phan tu: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void printEvenNumbers(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void printPrimeNumbers(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void reverseArray(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Mang sau khi dao nguoc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int *arr, int n, bool ascending) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchElement(int *arr, int n) {
    int element;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &element);
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Phan tu %d duoc tim thay tai vi tri %d.\n", element, i);
            return;
        }
    }
    printf("Phan tu %d khong ton tai trong mang.\n", element);
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&arr, &n);
                break;
            case 2:
                printEvenNumbers(arr, n);
                break;
            case 3:
                printPrimeNumbers(arr, n);
                break;
            case 4:
                reverseArray(arr, n);
                break;
            case 5:
                {
                    int sortChoice;
                    printf("Chon lua chon sap xep:\n");
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &sortChoice);
                    if (sortChoice == 1) {
                        sortArray(arr, n, true);
                    } else if (sortChoice == 2) {
                        sortArray(arr, n, false);
                    } else {
                        printf("Lua chon khong hop le!\n");
                    }
                }
                break;
            case 6:
                searchElement(arr, n);
                break;
            case 7:
                free(arr);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }

    return 0;
}

