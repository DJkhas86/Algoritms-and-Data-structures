#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define interval 5
int max = 2500;
int min = -2500;
int s =0;
void output(int *array,const int a){
    int i = 0;
	for(i = 0;i < a;i++){
        printf("%d ",*(array+i));
    }
    printf("\n");
}
void random(int *array,const int a)
{
    int i, c;
    c = rand() % (max - min) + min;
    for (i = 0; i < a; i++)
    {
        *(array + i) = c;
        c = rand() % (max - min) + min;
    }
}
void steirs(int *array,const int a)
{
    int k,i,h;
    int c = 0;
    k = (a / interval);
    h = (max - min) / k;
    for (i = 0; i < a; i++)
    {
        if (i % interval == 0)
        {
            c++;
        }
        *(array + i)= min + (h * c);
    }
}
int defaultSearch(int *a,int size,int key){
    s = 0;
   for(int i = 0;i < size;i++){
    s++;
        if(*(a+i) == key){
            return i;
        }
   }
   return 0; 
}
int jumpSearch(int *a,int size,int key){
    int jump = 0;
    s = 0;
    int sq = (int)sqrt(size);
    while(*(a + jump) < key){
        s++;
        jump += sq;
    }
    for(int i = jump-sq;i < jump;i++){
        s++;
        if(*(a + i) == key){
            return 1;
        }
    }
    return 0;
}
int binarySearch(int *a,int size,int key){
    int mid = size/2;
    int r = 0;
    int l = 0;
    int f = 0;
    s = 0;
    while(f != 1){
        s++;
        if((*(a + (mid - l)) == key) || (*(a + (mid + r)) == key)){
            f = 1;
            return 1;
        }
        else{
            r++;
            l++;
        }
        if (r > mid || l < 0){
            f = 1;
        }
    }
    return 0;
}
int main(){
    int size = 5000;
    int po = 500;
    int *ptr = calloc(size,sizeof(int));
    int r = 0;
    FILE *fp = fopen("laba3.txt","w");
    for(int i = 0;i<5;i++){
        random(ptr,size);
        r = defaultSearch(ptr,size,po);
        fprintf(fp,"%d udachnii s ==== %d \n",po,s);
        po += 500;
    }
    for(int i = 0;i<5;i++){
        random(ptr,size);
        r = defaultSearch(ptr,size,2501);
        fprintf(fp,"%d neudachnii s ==== %d \n",i,s);
    }
    po = 250;
    for(int i = 0;i<5;i++){
        steirs(ptr,size);
        r = jumpSearch(ptr,size,po);
        fprintf(fp,"%d %d udachnii s ==== %d \n",po,r,s);
        po += 500;
    }
    for(int i = 0;i<5;i++){
        steirs(ptr,size);
        r = jumpSearch(ptr,size,2501);
        fprintf(fp,"%d %d neudachnii s ==== %d \n",i,r,s);
    }
    po = 250;
    for(int i = 0;i<5;i++){
        steirs(ptr,size);
        r = binarySearch(ptr,size,po);
        fprintf(fp,"%d %d udachnii s ==== %d \n",po,r,s);
        po += 500;
    }
    for(int i = 0;i<5;i++){
        steirs(ptr,size);
        r = binarySearch(ptr,size,2501);
        fprintf(fp,"%d %d neudachnii s ==== %d \n",i,r,s);
    }
    fclose(fp);
    free(ptr);
    system("pause");
    return 0;
}