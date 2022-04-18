#include "manager.h"

int main(void){
    Product s[20];
    int count = 0, menu;
    int index=0;

    count = loadData(s);
    index = count;

    #ifdef DEBUG
    printf("==> DEBUG MODE!!\n");
    #endif

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                list_product(s,index);
            }
            else printf("상품이 없습니다!!\n");
        }
        else if (menu == 2){
            if(count<20){
                count += create_product(&s[index++]);
                printf("상품을 추가!\n");
            }
            else printf("상품을 추가할 수 없습니다!!\n");
        }
        else if (menu == 3){
            int num;

            num = selectNum(s,count);
            #ifdef DEBUG
            char method_name[2][30] = {"새벽배송","택배배송"};
            printf("\n==> DEBUG\n");
            printf("수정하기 전 %d번의 원래 정보\n",num);
            printf("제품 이름:%s\n 제품 설명:%s\n 중량:%s\n 판매 가격:%d원\n 배송방법: %s\n\n",s[num-1].product_name,s[num-1].product_explain,s[num-1].weight,s[num-1].price,method_name[s[num-1].method-1]);
            printf("\n수정과정!\n");
            #endif

            if(update_product(&s[num-1])) printf("=> 수정 성공!\n");

            #ifdef DEBUG
            printf("\n==> DEBUG\n");
            printf("수정하기 전 %d번의 원래 정보\n",num);
            printf("제품 이름:%s\n 제품 설명:%s\n 중량:%s\n 판매 가격:%d원\n 배송방법: %s\n\n",s[num-1].product_name,s[num-1].product_explain,s[num-1].weight,s[num-1].price,method_name[s[num-1].method-1]);
            #endif
        }
        else if (menu == 4){
            int num;
            int delete;
            num = selectNum(s,count);
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d",&delete);
            if(delete==1){
                delete_product(&s[num-1]);
                printf("=> 삭제 성공!\n");
                count--;
            }
            else{
                printf("삭제가 취소되었습니다!!\n");
            }
        }
        else if (menu == 5){
            if(count==0){
                printf("==> 데이터 없음!\n");
            }
            else{
                saveData(s,index);
            }
        }
        else if (menu == 6){
            if(count==0){
                printf("==> 데이터 없음!\n");
            }
            else{
                nameFind(s,index);
            }
        }
        else if (menu == 7){
            if(count==0){
                printf("==> 데이터 없음!\n");
            }
            else{
                priceFind(s,index);
            }
        }
        else if (menu == 8){
            if(count==0){
                printf("==> 데이터 없음!\n");
            }
            else{
                methodFind(s,index);
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}

