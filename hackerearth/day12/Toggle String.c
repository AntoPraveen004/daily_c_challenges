#include <stdio.h>
#include<string.h>
int main(){
	char num[101];
	scanf("%s", num);              	                  // Reading input from STDIN
	for(int i=0;i<strlen(num);i++){
		if(isupper(num[i])){
			num[i]=tolower(num[i]);
		}else if(islower(num[i])){
			num[i]=toupper(num[i]);
		}
	}
	printf("%s",num);
	return 0;
}
