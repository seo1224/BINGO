#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo (int (*bingom)[N], int (*bingoc)[N]){
	
	int num [N*N]; // 빙고판에 각각 다른 숫자를 넣기 위한 배열 선언 
	int bingnum; // 랜덤 함수를 적용할 변수
	int n = 0, i = 0, j = 0;
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num 배열 정의
	
	for(i = 0; i < N; i++){
		for(j= 0; j < N; j++){
			bingnum = rand()%(N*N);
			
			if (num[bingnum] == 0)
			{
				j--;
			}
			else
			{
				bingom[i][j] = num[bingnum];
                num[bingnum] = 0; 
			}// 임의의 숫자가 뽑히면 그것을 빙고판에 적용하고 이에 해당하는 num 배열을 0으로 바꾸어 중복을 피한다 
			}
		} // 사용자 빙고판  
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num 배열 정의
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			bingnum = rand()%(N*N);
			
			if (num[bingnum] == 0)
			{
				j--;
			}
			else
			{
				bingoc[i][j] = num[bingnum];
                num[bingnum] = 0;
			}
			}
		}// 컴퓨터 빙고판
		
	return 0;
}

int print_bingo(int (*bingom)[N], int (*bingoc)[N]){
	int i = 0, j = 0;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("|  %2d  |", bingom[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j< N; j++){
			printf("|  %2d  |", bingoc[i][j]); 
		}
		printf("\n");
	} // 완성된 프로그램에서 지울 것임  
	
	return 0;
}

int get_number_byMe(int (*bingom)[N], int (*bingoc)[N]){
	
	int count = 0;
    int num = 0; // 입력된 수를 가리키는 변수 
    int i = 0, j = 0, k = 0, l = 0; // 반복문을 위한 변수 
    
    printf("당신의 선택 : ");
    scanf("%d", &num);
    
    if(num<=N*N && num>=1){
    	for(i = 0; i<N; i++){
    		for(j = 0; j<N; j++){
    			if(bingom[i][j] == num || bingoc[i][j] == num){
    				for(k = 0; k < N; k++){
    					for(l = 0; l < N; l++){
    						if(bingom[k][l]==num){
    							bingom[k][l] = -1;}
    						if(bingoc[k][l]==num){
    							bingoc[k][l] = -1;}	
						}
					} // 배열을 한 칸씩 확인하면서 입력된 숫자를 -1로 바꿈  
				}
				else {
					count++;} 
			}
		}
	}
	else {
		printf("빙고 범위를 넘어선 숫자 입니다. 다시 입력해 주세요\n");
		get_number_byMe(bingom, bingoc); // 빙고 숫자의 범위를 넘어서 숫자를 입력할 경우 다시 처음으로 돌아가게 만듬  
	}
	if(count == N*N ){
		printf("이미 입력한 숫자 입니다. 다시 입력해 주세요\n");
        count = 0;
        get_number_byMe(bingom, bingoc); // count가 N*N이 될 경우는 배열을 확인할 때 겹치는 숫자가 없었다는 뜻이므로 그 숫자는 이미 입력된 숫자임을 알 수 있음  
	}
	
	return 0;
}

int get_number_byCom(int (*bingom)[N], int(*bingoc)[N]){
	
    int count = 0;
    int num = 0;
    int i = 0, j = 0, k = 0, l = 0;
    
    num = rand()%(N*N); // 컴퓨터가 랜덤으로 숫자를 출력하게 만듬 
    
    if(num<=N*N && num>=1){
    	for(i = 0; i<N; i++){
    		for(j = 0; j<N; j++){
    			if(bingom[i][j] == num || bingoc[i][j] == num){
    				for(k = 0; k < N; k++){
    					for(l = 0; l < N; l++){
    						if(bingom[k][l]==num){
    							bingom[k][l] = -1;}
    						if(bingoc[k][l]==num){
    							bingoc[k][l] = -1;}	
						}
					}
				}
				else {
					count++;}
			}
		}
	}
	else {
		get_number_byCom(bingom, bingoc);
	}
    if(count == N*N ){
    	count = 0;
        get_number_byCom(bingom, bingoc); 
    } // 방식은 get_number_byMe와 동일  
        
    printf(" 컴퓨터의 선택 : %d\n", num);
    
    return 0;
} // get_number 함수와 process_bingo 함수를 합침 


int main(int argc, char *argv[]) {
	
	int bingo_me[N][N]={0};
    int bingo_com[N][N]={0};
    
    srand(time(NULL)); // 난수를 초기화해주는 함수  
    
    initiate_bingo(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
    
    get_number_byMe(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
    get_number_byCom(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
    
	return 0;
}
