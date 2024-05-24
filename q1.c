#include <stdio.h>
// 2480*22
int main(){
    char a[1000];
    char b[1000];
    scanf("%s",a);
    scanf("%s",b);
    int len1=0;
    int len2=0;
    while(a[len1]>='0'&& a[len1]<='9'){
        len1++;
    }
    while(b[len2]>='0'&& b[len2]<='9'){
        len2++;
    }
    char add[len2][len1+len2];
    for(int i=0;i<len2;i++){
        for(int j=0;j<len1+len2;j++){
            add[i][j] = '0';
        }
    }
    int num1 = len1 +len2-1;
    int k = 0;
    for(int i=len2-1;i>=0;i--){
        int carry = 0;
        int num2 = num1;
        for(int j=len1-1;j>=0;j--){
            int val = (b[i]-'0')*(a[j]-'0') +carry;
            add[k][num2--] = val%10 +'0';
            carry = val/10;
        }
        while(carry>0){
            add[k][num2--] = carry%10 +'0';
            carry=carry/10;
        }
        k++;
        num1--;
    }
    char sum[len1+len2];
    int carry = 0;
    int t = len1+len2-1;
    for(int i=len1+len2-1;i>=0;i--){
        int sum1 = 0;
        for(int j=0;j<len2;j++){
            sum1+= add[j][i]-'0';
        }
        sum1+= carry;
        sum[t--] = sum1%10 +'0';
        carry = sum1/10;
    }
    while(carry>0){
        sum[t--] = carry%10 +'0';
        carry = carry/10;
    }
    t++;
    while(t<len1+len2-1 && sum[t]=='0')t++;
    for(int i=t;i<len1+len2;i++){
        printf("%c",sum[i]);
    }
}

