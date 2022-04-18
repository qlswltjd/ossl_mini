#include "manager.h"

int selectMenu(){ 
    int menu;
    printf("\n*********************************\n");
    printf("1. 상품 조회\n"); 
    printf("2. 상품 추가\n"); 
    printf("3. 상품 수정\n"); 
    printf("4. 상품 삭제\n"); 
    printf("5. 저장\n");
    printf("6. 상품명 검색\n");
    printf("7. 제품가격 검색\n");
    printf("8. 배송방법 검색\n");
    printf("0. 종료\n"); 
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
    
    printf("추가할 제품의 배송방법을 입력해주세요! (1:새벽배송 /2:택배배송)\n");
    scanf("%d",&s->method);
    
    return 1; 
}
int update_product(Product *s){ getchar();

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

    printf("수정할 제품의 배송방법을 입력해주세요! (1:새벽배송 /2:택배배송)\n");
    scanf("%d",&s->method); 

    return 1;
}
void read_product(Product s){
    char method_name[2][30] = {"새벽배송","택배배송"};
    printf("%-10s %-15s %s %d %s\n",s.product_name,s.product_explain,s.weight,s.price,method_name[s .method-1]);
}
int delete_product(Product *s){
    s->price = -1;//가격이 음수인 거는 말이 되지 않음 return 1;
    return 1;
}
int selectNum(Product *s,int count){//번호를 선택하는 거
    int num;
    list_product(s,count);//s는 Product *s를 의미
    printf("원하는 번호는 (취소 :0)? ");
    scanf("%d",&num);
    return num;
}
void list_product(Product *s,int count){
    printf("\t제품명\t\t설명\t\t\t중량\t판매가격 배송방법\n");
    printf("*********************************\n");

    for(int i=0; i<count; i++){
        if(s[i].price==-1) continue;
        printf("%2d \t",i+1);
        read_product(s[i]);
    }
    printf("\n");
}
