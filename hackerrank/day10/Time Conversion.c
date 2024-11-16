char* timeConversion(char* s) {
    if(s[8]=='P'&&s[9]=='M'){
        int num=((s[0]-'0')*10+(s[1]-'0'));
        if(num!=12){
            num=num+12;
        }
        s[1]=num%10+'0';
        num=num/10;
       s[0]=(num%10)+'0';
    }else{
        int num=((s[0]-'0')*10+(s[1]-'0'));
        if(num>=12){
            num=num-12;
        }
        s[1]=num%10+'0';
        num=num/10;
        s[0]=(num%10)+'0';
    }
    char *c =(char*)malloc(8*sizeof(char));
    strncpy(c,s,8);
    c[8]='\0';
    return c;
}