#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#define interval 20
int min = -2500;
int max = 2500;
void output(int *array,const int a){
    int i = 0;
	for(i = 0;i < a;i++){
        printf("%d ",*(array+i));
    }
    printf("\n");
}
void normal(int *array,const int a)
{
    int i,c;
    c = min;
    int shag = (max - min) / a;
    for (i = 0; i < a;i++)
    {
        *(array + i) = c;
        c += shag;
    }
}
void unnormal(int *array,const int a)
{
    int i, c;
    c = max;
    int shag = (max - min) / a;
    for (i = 0; i < a; i++)
    {
        *(array+i) = c;
        c -= shag;
    }
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
int s = 0;
void Shell(int *array,const int a){
    int i,j,step,tmp;
    s = 0;
    for(step = 1;step <= a;step = 3*step + 1){
        for(i = step;i < a;i++){
            tmp = *(array + i);
            for(j = i;j >= step ;j -= step){
                if(tmp < *(array + j - step)){
                    *(array + j) = *(array + j - step);
                    s++;
                }
                else{
                	s++;
                    break;
                }
            }
            *(array + j) = tmp;
        }
    }
}
void choise(int *array,const int a){
    int minPosition,buf,i,j;
    s =0;
    for(i = 0;i < a;i++){
        minPosition = i;
        for(j = i + 1;j < a;j++){
            if(*(array + minPosition) > *(array + j)){
                minPosition = j;
            }
            buf = *(array + minPosition);
            *(array + minPosition) = *(array + i);
            *(array + i) = buf;
            s++;
        }     
    }
}
void lsd(int *array,const int a){
    int maxnumb = 0;
    int i,j;
    int c = 0;
    s = 0;
    char zn;
    char buffzn1[10],buffzn2[10];
    int buff;
    for(i = 0;i < a;i++){
        if(*(array + i) > maxnumb){
            maxnumb = *(array+i);
            s++;
        }
    }
    itoa(maxnumb,&zn,10);
	for(i = 0;i < a;i++){
		for(j = 0;j < a;j ++){
			itoa(*(array + i),buffzn1,10);
			itoa(*(array + j),buffzn2,10);
			if(strlen(buffzn1) < strlen(buffzn2)){
				buff = *(array + j);
				*(array + j) = *(array + i);
				*(array + i) = buff;
				s++;
			}
			else if(strlen(buffzn1) == strlen(buffzn2)){
				if(buffzn1[c] < buffzn2[c]){
					buff = *(array + j);
					*(array + j) = *(array + i);
					*(array + i) = buff;
					s++;
				}
                else{
                    c++;
                    goto *126;
                }
                c = 0;
			}
		}
	}
}
float tn(void func(),const int a,int *array){

	long double result = 0;
    long double start = clock();
	func(array,a);
    result = (clock() - start)/CLOCKS_PER_SEC;
	return result;
}
int main(){
    int t,r;
    double a;
    int *ptr = NULL;
    FILE *fp;
    fp = fopen("shell.txt","w");
    for(int i = 5000;i <= 50000;i+=5000)
    {
        ptr = realloc(ptr,i * sizeof(int));
        normal(ptr,i);
        a = tn(Shell,i,ptr);
        r = s;
        fprintf(fp,"%d.shell/normal time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        unnormal(ptr,i);
        a = tn(Shell,i,ptr);
        r = s;
        fprintf(fp,"%d.shell/unnormal time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        random(ptr,i);
        a = tn(Shell,i,ptr);
        r = s;
        fprintf(fp,"%d.shell/random time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        steirs(ptr,i);
        a = tn(Shell,i,ptr);
        r = s;
        fprintf(fp,"%d.shell/steirs time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    fclose(fp);
    fp = fopen("choise.txt","w");
    for(int i = 5000;i <= 50000;i+=5000)
    {
        ptr = realloc(ptr,i * sizeof(int));
        normal(ptr,i);
        a = tn(choise,i,ptr);
        r = s;
        fprintf(fp,"%d.choise/normal time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        unnormal(ptr,i);
        a = tn(choise,i,ptr);
        r = s;
        fprintf(fp,"%d.choise/unnormal time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        random(ptr,i);
        a = tn(choise,i,ptr);
        r = s;
        fprintf(fp,"%d.choise/random time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    for(int i = 5000;i <= 50000;i+=5000){
        ptr = realloc(ptr,i * sizeof(int));
        steirs(ptr,i);
        a = tn(choise,i,ptr);
        r = s;
        fprintf(fp,"%d.choise/steirs time ====== %f  s ======= %d \n",i,a,r);
        min -=2500;
        max += 2500;
    }
    min = -2500;
    max = 2500;
    fclose(fp);
    // fp = fopen("lsd.txt","w");
    // for(int i = 5000;i <= 50000;i+=5000)
    // {
    //     ptr = realloc(ptr,i * sizeof(int));
    //     normal(ptr,i);
    //     a = tn(lsd,i,ptr);
    //     r = s;
    //     fprintf(fp,"%d.lsd/normal time ====== %f  s ======= %d \n",i,a,r);
    //     min -=2500;
    //     max += 2500;
    // }
    // min = -2500;
    // max = 2500;
    // for(int i = 5000;i <= 50000;i+=5000){
    //     ptr = realloc(ptr,i * sizeof(int));
    //     unnormal(ptr,i);
    //     a = tn(lsd,i,ptr);
    //     r = s;
    //     fprintf(fp,"%d.lsd/unnormal time ====== %f  s ======= %d \n",i,a,r);
    //     min -=2500;
    //     max += 2500;
    // }
    // min = -2500;
    // max = 2500;
    // for(int i = 5000;i <= 50000;i+=5000){
    //     ptr = realloc(ptr,i * sizeof(int));
    //     random(ptr,i);
    //     a = tn(lsd,i,ptr);
    //     r = s;
    //     fprintf(fp,"%d.lsd/random time ====== %f  s ======= %d \n",i,a,r);
    //     min -=2500;
    //     max += 2500;
    // }
    // min = -2500;
    // max = 2500;
    // for(int i = 5000;i <= 50000;i+=5000){
    //     ptr = realloc(ptr,i * sizeof(int));
    //     steirs(ptr,i);
    //     a = tn(lsd,i,ptr);
    //     r = s;
    //     fprintf(fp,"%d.lsd/steirs time ====== %f  s ======= %d \n",i,a,r);
    //     min -=2500;
    //     max += 2500;
    // }
    // min = -2500;
    // max = 2500;
    fclose(fp);
    free(ptr);
    system("pause");
    return 0;
}

    