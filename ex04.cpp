#include<stdio.h>
void addArr(int *arr, int *length);
void showEvenNumber(int *arr, int length);// in số chẵn
void primeNumber(int *arr, int length);
void reverseArr(int *arr, int length);
void increaseArr(int *arr, int length);// tang
void reduceArr(int *arr, int length);// giam
void findNumber(int *arr, int length);
int main(void){
    int arr[100];
    int choose=0, flag=0, length=0;
    printf("MENU \n 1. Nhap vao so phan tu va tung phan tu \n 2. In ra cac phan tu la so chan \n 3. In ra cac pha tu la so nguyen to \n 4. Dao nguoc mang \n 5. Sap xep mang \n 6. Nhap vao 1 phan tu va tim kiem phan tu trong mang \n 7. Thoat \n");
    do {
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                flag=1;
                addArr(arr, &length);
                break;
            case 2:
                if(flag==1){
                    printf("Cac phan tu la so chan la: ");
                    showEvenNumber(arr, length);
                    printf("\n");
                }else{
                    printf("Ban chu khoi tao mang \n");
                }
                break;
            case 3:
                if(flag==1){
                    printf("Cac phan tu la so nguyen to la: ");
                    primeNumber(arr, length);
                    printf("\n");
                }else{
                    printf("Ban chu khoi tao mang \n");
                }
                break;
            case 4:
                if(flag==1){
                    reverseArr(arr, length);
                    printf("\n");
                }else{
                    printf("Ban chu khoi tao mang \n");
                }
                break;
            case 5:
                if(flag==1){
                    int elect=0;
                    printf("1. Tang dan \n2. Giam dan \n");
                    do{
                        printf("Moi ban chon: ");
                        scanf("%d", &elect);
                    }while(elect!=1 && elect!=2);
                    if(elect==1){
                        increaseArr(arr, length);
                        printf("\n");
                    }else{
                        reduceArr(arr, length);
                        printf("\n");
                    }
                }else{
                    printf("Ban chu khoi tao mang \n");
                }
                break;
            case 6:
                if(flag==1){
                    findNumber(arr, length);
                    printf("\n");
                }else{
                    printf("Ban chu khoi tao mang \n");
                }
                break;
            case 7:
                printf("Ban da chon thoat \n");
                break;
            default:
                printf("Lua chon cua ban khong co trong MENU \n");
        }
    }while(choose!= 7);
    return 0;
}
void addArr(int *arr, int*length){
    printf("Moi ban nhap so phan tu: ");
    scanf("%d", &(*length));
    for(int i=0; i<*length; i++){
        printf("arr[%d]= ", i);
        scanf("%d", &(*(arr+i)));
    }
}
void showEvenNumber(int *arr, int length){
    for(int i=0; i<length; i++){
        if(*(arr +i) %2==0 ){
            printf("%d ", *(arr +i));
        }
    }
}
void primeNumber(int *arr, int length){
    for(int i=0; i<length; i++){
        int count=0;
        for(int j=1; j<=*(arr+i); j++){
            if(*(arr+i) %j==0){
                count++;
            }
        }
        if(count==2){
            printf("%d ", *(arr+i));
        }
    }
}
void reverseArr(int *arr, int length){
    for(int i=0; i<(length /2); i++){
        int temp= *(arr+i);
        *(arr+i)=*(arr+(length-i-1));
        *(arr +(length-i-1))= temp;
    }
    for(int i=0; i<length; i++){
        printf("%d ", *(arr+i));
    }
}
void increaseArr(int *arr, int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-1; j++){
            if(*(arr+j)> *(arr+(j+1))){
                int temp= *(arr+j);
                *(arr +j)= *(arr+(j+1));
                *(arr+(j+1))= temp;
            }
        }
    }
    for(int i=0; i<length; i++){
        printf("%d ", *(arr+i));
    }
}
void reduceArr(int *arr, int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-1; j++){
            if(*(arr+j)< *(arr+(j+1))){
                int temp= *(arr+j);
                *(arr +j)= *(arr+(j+1));
                *(arr+(j+1))= temp;
            }
        }
    }
    for(int i=0; i<length; i++){
        printf("%d ", *(arr+i));
    }
}
void findNumber(int *arr,int length){
    int number=0;
    printf("Moi ban nhap phan tu muon tim: ");
    scanf("%d", &number);
    printf("Phan tu %d nam o vi tri: ", number);
    for(int i=0; i<length; i++){
        if(number== *(arr+i)){
            printf("arr[%d] ", i);
        }
    }
}
