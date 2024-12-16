#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayMenu() {
    printf("MENU\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In chuoi\n");
    printf("3. Dem chu cai\n");
    printf("4. Dem chu so\n");
    printf("5. Dem ky tu dac biet\n");
    printf("6. Thoat\n");
}

void inputString(char **str) {
    int capacity = 1000;
    int length = 0;
    *str = (char *)malloc(capacity * sizeof(char));

    if (*str == NULL) {
        printf("Khong cap phat duoc bo nho\n");
        exit(1);
    }

    printf("Nhap chuoi: ");
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        (*str)[length++] = ch;
        
        if (length >= capacity) {
            capacity *= 2;
            *str = (char *)realloc(*str, capacity * sizeof(char));
            if (*str == NULL) {
                printf("Khong cap phat duoc bo nho.\n");
                exit(1);
            }
        }
    }
    (*str)[length] = '\0';
}

void printString(char *str) {
    if (str) {
        printf("Chuoi: %s\n", str);
    } else {
        printf("Chua nhap chuoi!\n");
    }
}

void countChars(char *str, const char *type) {
    if (str) {
        int count = 0;
        for (int i = 0; str[i]; i++) {
            if (*type == 'L' && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
                count++;
            } else if (*type == 'D' && (str[i] >= '0' && str[i] <= '9')) {
                count++;
            } else if (*type == 'S' && !((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')) {
                count++;
            }
        }
        if (*type == 'L') {
            printf("So chu cai: %d\n", count);
        } else if (*type == 'D') {
            printf("So chu so: %d\n", count);
        } else if (*type == 'S') {
            printf("So ky tu dac biet: %d\n", count);
        }
    } else {
        printf("Chua nhap chuoi!\n");
    }
}

int main() {
    char *str = NULL;
    int choice;

    while (1) {
        displayMenu();
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                inputString(&str);
                break;
            case 2:
                printString(str);
                break;
            case 3:
                countChars(str, "L");
                break;
            case 4:
                countChars(str, "D");
                break;
            case 5:
                countChars(str, "S");
                break;
            case 6:
                free(str);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}

