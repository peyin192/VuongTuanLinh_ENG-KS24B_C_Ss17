#include <bits/stdc++.h>
int main(){
	int arr[1000];
	int choose;
	int num=0;
	int sum=0;
	int max=arr[0];

	while(1){
 
    	printf("\n1. Nhap vao so phan tu va tung phan tu \n");
		printf("2. Hien thi cac phan tu trong mang \n");
		printf("3. Tinh do dai mang \n");
		printf("4. Tinh tong cac phan tu trong mang \n");
		printf("5. Hien thi phan tu lon nhat \n");
		printf("6. Thoat \n");
		
		printf("Nhap lua chon: ");
		scanf("%d",&choose);
		
		switch(choose){
			case 1:
				printf("Nhap vao so phan tu: ");
				scanf("%d",&num);
				
				for(int i=0;i<num;i++){
					printf("Nhap phan tu thu %d: ",i+1);
					scanf("%d",&arr[i]);
				}
			break;
			case 2:
				for(int i=0;i<num;i++){
					printf("Phan tu thu %d la: %d \n",i+1,arr[i]);
				}
			break;
			case 3:
				printf("Do dai cua mang la %d",num);
				break;
			case 4:
				for(int i=0;i<num;i++){
					sum +=arr[i];
				}
			    printf("Tong cua mang la: %d",sum);
			    break;
			case 5:
			    for(int i=0;i<num;i++){
				    if(arr[i]>max){
					max = arr[i];
				}
			}
			printf("%d\n",max);
			break;
			case 6:
				return 0;
			    
		}

	}
}
