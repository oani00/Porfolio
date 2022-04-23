// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

/* 
clear && cd ~/Dropbox/#BOITUVA/ADS/5ED/URI && gcc 2590.c -o ~/testeC.exe -lm -Wall && ~/testeC.exe
*/

#include <iostream>
#include <cmath>
#include <cctype>
#include <stdio.h>

using namespace std;

//praticamente a mesma de C
//https://www.life2coding.com/uri-online-judge-solution-2630-greyscale-beginner-problem/

int main(){
    string mode;
    int t,r,g,b,i=1,res=0;
    while(scanf("%d",&t)!=EOF){
        while(t--){

            cin>>mode>>r>>g>>b;
            
            if(mode=="eye"){
                res = 0.30*r + 0.59*g + 0.11*b;
            }
            else if(mode=="min"){
                res = min(r,min(g,b));
            }
            else if(mode=="mean"){
                res = (r+g+b)/3;
            }
            else{
                res = max(r,max(g,b));
            }

            printf("Caso #%d: %dn",i++,res);
            res=0;
        }
    }

    return 0;
}