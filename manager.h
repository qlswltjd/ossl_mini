#include <stdio.h>
#include <string.h>

typedef struct {
    char product_name[100];//제품명 : 문자열
    char product_explain[100];//설명 : 문자열
    char weight[30];//중량 : 문자열
    int price;//판매가격 : 숫자
    int method;//배송방법 : 숫자 (1:새벽배송 /2:택배배송)
} Product;

int selectMenu();//0
int create_product(Product *s);//제품 추가 함수 0
void read_product(Product s );//하나의 제품 출력 함수 0
int update_product(Product *s);//상품의 내용 수정 0
int delete_product(Product *s);//제품 삭제 0
void list_product(Product *s,int count);//전체 등록된 제품 리스트 출력 0
int selectNum(Product *s,int count);//몇 번을 삭제하고 수정할 건지 할 때 사용하는 번호를 고르는 함수 0
void saveData(Product *s,int count);//제품 데이터를 파일에 저장시키는 함수 0
int loadData(Product *s);//제품 데이터를 파일에서 읽어오는 함수 0
void nameFind(Product *s,int count);// 제품명을 검색하는 함수0
void priceFind(Product *s,int count);// 제품가격을 검색하는 함수0
void methodFind(Product *s,int count);// 배송방법을 검색하는 함수0
                                                                   
