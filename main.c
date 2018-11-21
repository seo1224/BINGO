#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define N 5
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo (int (*bingom)[N], int (*bingoc)[N]){
	
	int num [N*N]; // �����ǿ� ���� �ٸ� ���ڸ� �ֱ� ���� �迭 ���� 
	int bingnum; // ���� �Լ��� ������ ����
	int n = 0, i = 0, j = 0;
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num �迭 ����
	
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
			}// ������ ���ڰ� ������ �װ��� �����ǿ� �����ϰ� �̿� �ش��ϴ� num �迭�� 0���� �ٲپ� �ߺ��� ���Ѵ� 
			}
		} // ����� ������  
	
	for(n = 0; n < N*N; n++){
		num[n] = n + 1;
	} // num �迭 ����
	
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
		}// ��ǻ�� ������
		
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
	
	//for(i = 0; i < N; i++){
		//for(j = 0; j< N; j++){
			//printf("|  %2d  |", bingoc[i][j]); }
		//printf("\n");} // �ϼ��� ���α׷����� ���� ����  
	
	return 0;
}

int get_number_byMe(int (*bingom)[N], int (*bingoc)[N]){
	
	int count = 0;
    int num = 0; // �Էµ� ���� ����Ű�� ���� 
    int i = 0, j = 0, k = 0, l = 0; // �ݺ����� ���� ���� 
    
    printf("����� ���� : ");
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
					} // �迭�� �� ĭ�� Ȯ���ϸ鼭 �Էµ� ���ڸ� -1�� �ٲ�  
				}
				else {
					count++;} 
			}
		}
	}
	else {
		printf("���� ������ �Ѿ ���� �Դϴ�. �ٽ� �Է��� �ּ���\n");
		get_number_byMe(bingom, bingoc); // ���� ������ ������ �Ѿ ���ڸ� �Է��� ��� �ٽ� ó������ ���ư��� ����  
	}
	if(count == N*N ){
		printf("�̹� �Է��� ���� �Դϴ�. �ٽ� �Է��� �ּ���\n");
        count = 0;
        get_number_byMe(bingom, bingoc); // count�� N*N�� �� ���� �迭�� Ȯ���� �� ��ġ�� ���ڰ� �����ٴ� ���̹Ƿ� �� ���ڴ� �̹� �Էµ� �������� �� �� ����  
	}
	
	return 0;
}

int get_number_byCom(int (*bingom)[N], int(*bingoc)[N]){
	
    int count = 0;
    int num = 0;
    int i = 0, j = 0, k = 0, l = 0;
    
    num = rand()%(N*N); // ��ǻ�Ͱ� �������� ���ڸ� ����ϰ� ���� 
    
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
    } // ����� get_number_byMe�� ����  
     
    printf("��ǻ���� ���� : %d\n", num);
    
    return 0;
} // get_number �Լ��� process_bingo �Լ��� ��ħ 

int count_bingome(int (*bingom)[N]){
	
	int countx = 0; // ���� ������ ���� ���� ����  
    int county = 0; // ���� ������ ���� ���� ����
    int countzone = 0, countztwo = 0; // countzone�� ���� ��- ������ �Ʒ� �밢��(��-�� �밢��)�� �ǹ��ϰ� countztwo�� ������ �� - ���� �Ʒ� �밢��(��-�� �밢��)�� �ǹ��Ѵ�  
    int countbingome = 0; // �� ������ ���� �ǹ��ϴ� ����  
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    
    for(i = 0; i < N; i++){
    	for(j =0; j< N; j++){
    		if(bingom[i][j] == -1)
			{
    			countx++;
			} //�����ǿ� -1�� ǥ���� ĭ�� ������ countx�� 1 �߰��Ǵ� if��  
    	}
		if(countx==N){
			countbingome++;}
		countx = 0;//  ���� �� �ٿ� N���� countx�� �����ϸ� ������ ������ �߰��ȴٴ� ���� �ǹ��ϴ� if��  
	} // ���� ���� ã�Ƴ��� ���� for��  
	
	for(k = 0; k < N; k++){
    	for(l =0; l < N; l++){
    		if(bingom[l][k] == -1)
			{
    			county++;
			}
    	}
		if(county==N){
			countbingome++;}
		county = 0;
	}// ���� ���� ã�Ƴ��� ���� for��, ����� ���� ���� ã�� ����� ����  
	
	for(m = 0; m < N; m++){
		if(bingom[m][m] == -1){
			countzone++;} // bingm [n][n]�� ��-�� �밢���� �ǹ� 
	}
	if(countzone == N)
		countbingome++;
		countzone = 0;
    //��-�� �밢�� ���� ã�Ƴ��� ���� for���� if�� 
	 
    for(n = 0; n < N; n++){
		if(bingom[n][N-n-1] == -1){
			countztwo++;}// bingm [n][N-n-1]�� ��-�� �밢���� �ǹ� 
	}
	if(countztwo == N)
		countbingome++;
		countztwo = 0;
	//��-�� �밢�� ���� ã�Ƴ��� ���� for���� if�� 
// ����� �����ǿ� ���� �� ������ ���� �Լ�
	return countbingome;
}

int count_bingocom(int (*bingoc)[N]){
	
	int countx = 0;
    int county = 0;
    int countzone = 0, countztwo = 0; // countzone�� ���� ��- ������ �Ʒ� �밢���� �ǹ��ϰ� countztwo�� ������ �� - ���� �Ʒ� �밢���� �ǹ��Ѵ�  
    int countbingocom = 0;
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    
    for(i = 0; i < N; i++){
    	for(j =0; j< N; j++){
    		if(bingoc[i][j] == -1)
				countx++;
			}
		if(countx == N){
			countbingocom++;}
		countx = 0;
	}
	
	for(k = 0; k < N; k++){
    	for(l = 0; l < N; l++){
    		if(bingoc[l][k] == -1)
			    county++;
    	}
		if(county==N){
			countbingocom++;}
		county = 0;
	}
	
	for(m = 0; m < N; m++){
		if(bingoc[m][m] == -1){
			countzone++;}
	}
	if(countzone == N)
		countbingocom++;
	countzone = 0;
    
    for(n = 0; n < N; n++){
		if(bingoc[n][N-n-1] == -1){
			countztwo++;}
	}
	if(countztwo == N)
		countbingocom++;
	countztwo = 0;
		
// ����� �����ǿ� ���� �� ������ ���� �Լ�, ����� count_bingome �� ����  
	return countbingocom;
}


int main(int argc, char *argv[]) {
	
	int bingo_me[N][N]={0};  
    int bingo_com[N][N]={0}; 
    // ������ �ʱ�ȭ  
    int turn = 1; // ���° �Ͽ� �ºΰ� �����Ǵ��� ����ϱ� ���� ����  

    srand(time(NULL)); // ������ �ֱ�ȭ ��Ű�� �Լ�  

    initiate_bingo(bingo_me, bingo_com);
    print_bingo(bingo_me, bingo_com);
   
    while(count_bingome(bingo_me) != M || count_bingocom(bingo_com) != M){
    	
    	get_number_byMe(bingo_me, bingo_com);
    	print_bingo(bingo_me, bingo_com);
        printf("���� ������ ������ ����� %d��, ��ǻ�Ͱ� %d�� �̸� %d ��°�Դϴ�.\n", count_bingome(bingo_me), count_bingocom(bingo_com),turn);
        turn++;
        
    if(count_bingome(bingo_me)==M || count_bingocom(bingo_com)==M){
        break;} // ������� �Ͽ��� M�� �����ϴ� ��츦 ����Ѵ�  

        get_number_byCom(bingo_me, bingo_com);
        print_bingo(bingo_me, bingo_com);
	    printf("���� ������ ������ ����� %d��, ��ǻ�Ͱ� %d�� �̸� %d ��°�Դϴ�.\n", count_bingome(bingo_me), count_bingocom(bingo_com),turn);
        turn++;
   } // �� �������� �ϳ��� ������ ���� M�� ������ ������ {}�� �ݺ��ϴ� while�� 
   
    if(count_bingome(bingo_me) == M || count_bingocom(bingo_com) == M){
    	if(count_bingome(bingo_me) == M && count_bingocom(bingo_com) != M){
            printf("�� turn���� ����� �¸�!");
            }// ������� �����Ǹ� M�� �����ϴ� ��� 
        if(count_bingocom(bingo_com) == M && count_bingome(bingo_me) != M){
            printf("�� turn���� ��ǻ���� �¸�!");
            }// ��ǻ���� �����Ǹ� M�� �����ϴ� ��� 
        if(count_bingome(bingo_me) == M && count_bingocom(bingo_com) == M){
        	printf("�� turn���� ���º�!");
		}// �Ѵ� M�� �����ϴ� ��� 
      }   

    return 0;
}
