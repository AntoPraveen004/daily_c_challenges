/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct{
    int score;
    int index;
 }athlet;
 int compare(const void*a,const void*b){
    return ((athlet*)b)->score-((athlet*)a)->score;
 }
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    athlet* a=(athlet*)malloc(scoreSize*sizeof(athlet));
    for(int i=0;i<scoreSize;i++){
        a[i].score=score[i];
        a[i].index=i;
    }
    qsort(a,scoreSize,sizeof(athlet),compare);
    char** res=(char**)malloc(scoreSize*sizeof(char*));
    for(int i=0;i<scoreSize;i++){
       res[i]=(char*)malloc(15*sizeof(char));
    }
    for(int i=0;i<scoreSize;i++){
        int ind=a[i].index;
        if(i==0){
            strcpy(res[ind],"Gold Medal");
        }else if(i==1){
            strcpy(res[ind],"Silver Medal");
        }else if(i==2){
            strcpy(res[ind],"Bronze Medal");
        }else{
            sprintf(res[ind],"%d",i+1);
        }
    }
    free(score);
    free(a);
    *returnSize=scoreSize;
    return res;
}