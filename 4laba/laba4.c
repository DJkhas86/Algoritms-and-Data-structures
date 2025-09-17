#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include  <locale.h>
int hashSearch(char text[],char pattern[],int t,int p){
    int i,j;
    int flag = 0;
    int result =0;
    for(i = 0;i<t-1;i++){
        for(j = 0; j < p - 1; j++){
            if((int)(text[i + j]) != (int)(pattern[j])){
                break;
            }
            flag ++;
        }
        if (flag == (p - 1)){
            return result = i;
        }
        else{
            flag = 0;
        }
    }
    return result;
}
int main(){
    FILE *fp = NULL;
    setlocale(LC_ALL,"RU");
    char t[2845] = "All societies are faced with the problem of scarcity.They differ considerably,however, in the way they solve the problem. One important difference betweensocieties is the degreee of government control of the economy. At the one extreme lies the completely planned or command economy, where all the economic decisions are taken by the government. At the other extreme lies the completely free-market economy. In this type of economy there is no government intervention at all. All decisions are taken by individuals and firms. Households decide how much labour and other factors to supply, and what goods to consume. Firms decide what goods to produce and what factors to employ. The pattern of production and consumption that results depends on the interactions of all factors of all these individual demand and supply decisions.  In practice all economies are a mixture of the two. It is therefore the degree of government intervention that distinguishes different economic systems. Thus in the former communist countries of eastern Europe, government played a large role whereas in the United States, the government playes a much smaller role. It is nevertheless useful to analyse the extremes in order to put the different mixed economies of the real world into perspective. Let us start by having a look at the command economy. The command economy is usually associated with a socialist or communist economic systems, where land and capital are collectively owned. The state plans the allocation of resources at three important levels:1. It plans the allocation of resources between present consumption and investment for the future. By sacrificing some present consumption and diverting resources into investment, it could increase the economys growth rate. The amount of resources it chooses to invest will depend on its macroeconomic strategy: the importance it attaches to growth as opposed to present consumption. 2. At a microeconomic level it plans the output of each industry and firm, the techniques that will be used and the labour and other resources required by each industry and firm. In order to ensure that the required inputs are available, the state would probably conduct some form of input-output analysis. All industries are seen as users of inputs from other industries and as producers of output for consumers or others industries. Input-output analysis shows, for each industry, the sources of all its inputs and the destination of all its outputs. By its use the state attampts to match up the inputs and outputs of each industry so that the planned demand for each industris product is equal to its planned supply. 3. It plans the distribution of output between consumers. This will depend on the governments aims. It may distribute goods according to its judgement of peoples needs;or it may give more to those.";
    char p1[9] =   "producers";
    int r = hashSearch(t,p1,2847,9);
    printf("\n%d\n",r);
    char p2[4] = "aims";
    r = hashSearch(t,p2,2847,4);
    printf("\n%d\n",r);
    char p3[5] = "needs";
    r = hashSearch(t,p3,2847,5);
    printf("\n%d\n",r);
    system("pause");
    return 0;
}