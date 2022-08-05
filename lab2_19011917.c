
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
    int N,**matris,i,j;
    srand(time(NULL));
    printf("Matrisin boyutunu giriniz: ");
    scanf(" %d",&N);
    matris = ((int**)malloc(N*sizeof(int*)));
    if(matris == NULL)
	{
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
    for(i = 0; i < N; i++)
	{
		matris[i] = (int*)malloc(N*sizeof(int));
		if(matris[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            matris[i][j]=1+rand()%100;
            printf("Matris[%d][%d]= %d \t",i,j,matris[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    matris = ((int**)realloc(matris,(N+1)*sizeof(int*)));
    if(matris == NULL)
	{
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
    
    for(i = 0; i < N+1; i++)
	{
		matris[i] = ((int*)realloc(matris[i],(N+1)*sizeof(int)));
		if(matris[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
    int tmp,tmp2;
    for(i=0;i<N;i++){
        tmp=0;
        tmp2=0;
        for(j=0;j<N;j++){
            tmp+=matris[i][j];
            tmp2+=matris[j][i];

        }
        matris[i][N]=tmp;
        matris[N][i]=tmp2;
    }
    tmp=0;
    for(i=0;i<N;i++){
        tmp+=matris[i][N]+matris[N][i];
        
    }
    matris[N][N]=tmp;

    for(i=0;i<N+1;i++){
        for(j=0;j<N+1;j++){

            printf("Matris[%d][%d]= %d\t",i,j,matris[i][j]);
        }
        printf("\n");
    }
  
    free(matris);
    
return 0;


}