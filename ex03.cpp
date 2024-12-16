#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap vao chuoi\n");
    printf("2. In ra chuoi dao nguoc\n");
    printf("3. Dem so luong tu trong chuoi\n");
    printf("4. Nhap vao chuoi khac, so sanh do dai voi chuoi ban dau\n");
    printf("5. In hoa tat ca chu cai trong chuoi\n");
    printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
    printf("7. Thoat\n");
}

void inputString(char str[1000]) {
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
}

void printReversedString(char str[1000]) {
    if (str == NULL || str[0] == '\0') {
        printf("Chua nhap chuoi!\n");
        return;
    }
    int len = strlen(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void countWords(char str[1000]) {
    if (str == NULL || str[0] == '\0') {
        printf("Chua nhap chuoi!\n");
        return;
    }
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    printf("So luong tu trong chuoi: %d\n", count);
}

void compareStringLength(char str1[1000]) {
    if (str1 == NULL || str1[0] == '\0') {
        printf("Chua nhap chuoi ban dau!\n");
        return;
    }
    char str2[1000];
    printf("Nhap chuoi khac de so sanh: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  

    if (strlen(str2) < strlen(str1)) {
        printf("Chuoi khac ngan hon chuoi ban dau.\n");
    } else if (strlen(str2) > strlen(str1)) {
        printf("Chuoi khac dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void toUpperCase(char str[1000]) {
    if (str == NULL || str[0] == '\0') {
        printf("Chua nhap chuoi!\n");
        return;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    printf("Chuoi in hoa: %s\n", str);
}

void appendString(char str1[1000]) {
    char buffer[1000];
    printf("Nhap chuoi khac de them: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  

    strcat(str1, buffer);
    printf("Chuoi sau khi them: %s\n", str1);
}

int main() {
    char str[1000] = "";  
    int choice;

    while (1) {
        displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputString(str);
                break;
            case 2:
                printReversedString(str);
                break;
            case 3:
                countWords(str);
                break;
            case 4:
                compareStringLength(str);
                break;
            case 5:
                toUpperCase(str);
                break;
            case 6:
                appendString(str);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}

