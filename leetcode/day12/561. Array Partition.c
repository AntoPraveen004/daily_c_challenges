int compare(const void* a,const void*b){
    return(*(int*)a-*(int*)b);
}
int min(int a,int b){
    return((a<b)?a:b);
}
int arrayPairSum(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),compare);
    int sum=0;
    for(int i=0;i<numsSize-1;i=i+2){
        sum=sum+min(nums[i],nums[i+1]);
    }
    return sum;
}