#include "product.h"
 
int selectMenu(){
   int menu;
   printf("\n***********\n");
   printf("1. 상품 조회\n");
   printf("2. 상품 추가\n");
   printf("3. 상품 수정\n");
   printf("4. 상품 삭제\n");
   printf("0. 종료\n\n");
   printf("=> 원하는 메뉴는? ");
   scanf("%d", &menu);
   return menu;
}
 
int create_product(Product *s){
       
       getchar();
 
       printf("추가할 제품의 이름을 입력해주세요!\n");
       fgets(s->product_name,sizeof(s->product_name),stdin);
       s->product_name[strlen(s->product_name)-1] = '\0';
 
       printf("추가할 제품의 설명을 입력해주세요!\n");
       fgets(s->product_explain,sizeof(s->product_explain),stdin);
       s->product_explain[strlen(s->product_explain)-1] = '\0';
 
       printf("추가할 제품의 중량을 입력해주세요!\n");
       fgets(s->weight,sizeof(s->weight),stdin);
       s->weight[strlen(s->weight)-1] = '\0';
       
       printf("추가할 제품의 판매가격을 입력해주세요!\n");
       scanf("%d%*c",&s->price);
       
       printf("추가할 제품의  배송방법을 입력해주세요!  (1:새벽배송 /2:택배배송)\n");
       scanf("%d",&s->method);
 
       return 1;
}
int update_product(Product *s){
 
       getchar();
 
       printf("수정할 제품의 이름을 입력해주세요!\n");
       fgets(s->product_name,sizeof(s->product_name),stdin);
       s->product_name[strlen(s->product_name)-1] = '\0';
 
       printf("수정할 제품의 설명을 입력해주세요!\n");
       fgets(s->product_explain,sizeof(s->product_explain),stdin);
       s->product_explain[strlen(s->product_explain)-1] = '\0';
 
       printf("수정할 제품의 중량을 입력해주세요!\n");
       fgets(s->weight,sizeof(s->weight),stdin);
       s->weight[strlen(s->weight)-1] = '\0';
       
       printf("수정할 제품의 판매가격을 입력해주세요!\n");
       scanf("%d%*c",&s->price);
       
       printf("수정할 제품의  배송방법을 입력해주세요!  (1:새벽배송 /2:택배배송)\n");
       scanf("%d",&s->method);
 
       return 1;
}
void read_product(Product s){
 
 char method_name[2][30] = {"새벽배송","택배배송"};
 printf(" 제품 이름: %s \n 제품 설명: %s \n 중량: %s \n 판매 가격: %d \n 배송방법: %s\n",s.product_name,s.product_explain,s.weight,s.price,method_name[s.method-1]);
 
}
int delete_product(Product *s){
 
 s->price = -1;//가격이 음수인 거는 말이 되지 않음
 return 1;
 
}
 
int main(void){
   Product s;
   int count = 0, menu;
 
   while (1){
       menu = selectMenu();
       if (menu == 0) break;
       if (menu == 1){
           if(count>0){
             if(s.price>0) read_product(s);
             else printf("상품이 없음!\n");
             }
           else printf("상품이 없음!\n");
       }
       else if (menu == 2){
           count += create_product(&s);
           printf("상품을 추가!\n");
       }
       else if (menu == 3){
           if(update_product(&s)) printf("=> 수정 성공!\n");
       }
       else if (menu == 4){
           if(delete_product(&s)) printf("=> 삭제 성공!\n");
       }
 
   }
   printf("종료됨!\n");
   return 0;
}
