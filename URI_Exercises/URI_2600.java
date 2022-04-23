// ┌───┐
// │┌─┐│      /
// ││ │├──┬─┐┌┐
// ││ ││┌┐│┌┐┼┤
// │└─┘│┌┐│││││
// └───┴┘└┴┘└┴┘

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[6];
        bool dice=true;
        bool Find[7];
        for(int i=0;i<=6;i++)
            Find[i]=false;
        for(int i=0;i<6;i++)
        {
            cin>>a[i];
            if(a[i]<1||a[i]>6)
                dice=false;
            else{
                    if(!Find[a[i]])
                    Find[a[i]]=true;
                    else dice=false;
            }
        }
        if(dice)
        {
            if((a[0]+a[5]==7)&&(a[1]+a[3]==7)&&(a[2]+a[4]==7))
                cout<<"SIMn";
            else cout<<"NAOn";
        }
        else cout<<"NAOn";
    }
}

/* 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//esse lixo de codigo nao funcionou nao sei por que... quando aprender C++ eu converto direito nao aguento mais esse ex.

int main(void)
{
    //     [0]
	// [1] [2] [3] [4]   <- o dado
	//     [5]

	//Inicialmente ia fazer a, b, c... mas um vetor é muito melhor...
	//Estou vendo que vetores e structs (estruturas em geral) sao melhores que variaveis................

    int t;
    scanf("%i", &t);
	
    while(t--)
    {
        int a[6]; //cria o "dado" da vez
        
		for(int i=0;i<6;i++)
        {            
			scanf("%i", &a[i]);
			
            if(a[i]<1||a[i]>6){
				printf("NAO\n");
				break;}
        }

		if((a[0]+a[5]==7)&&(a[1]+a[3]==7)&&(a[2]+a[4]==7))
			printf("SIM\n");
		else 
			printf("NAO\n");
    }
}
*/