#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;

int main (){
	
	srand(time(NULL));
	
	int jogadas=0, linha, coluna;
	int bomba, erro, i,j;
	int x, y, xb, yb;
					  
	int campo [10][10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	
	for(bomba=0;bomba<15;bomba++){
		do{
			xb=rand()%10;
			yb=rand()%10;
			erro=0;
			
			if(campo[xb][yb]==9){
				erro=1; 
			}
		
			//cout<<"x: "<<xb<<" \nY: "<<yb<<"\nerro: "<<erro<<"\n";  //cout  para testar onde as bombas estão sendo geradas
			
			
		}
		while(erro==1);
		campo[xb][yb]=9; //erro do codigo
		for(i=-1;i<2;i++){
			for(j=-1;j<2;j++){
				if(campo[xb+i][yb+j]!=9 && xb+i>=0 && yb+j>=0){
					campo[xb+i][yb+j]=campo[xb+i][yb+j]+1;
				}
			}
		}
	}
	
	/*for(linha=0;linha<10;linha++){
		for(coluna=0;coluna<10;coluna++){
			cout<<campo[linha][coluna]<<" ";               //For para testar o valor de cada campo do mapa
		}
		cout<<"\n";
	}*/
	
	while(1){
		for(linha=0;linha<10;linha++){
			if(linha==0){
				cout<<"   0 1 2 3 4 5 6 7 8 9 \n ";
			}
			if(linha>=0 and linha<1){
				cout<<0+linha<<" ";
			}
			if(linha>=1 and linha<=10){
				cout<< " "<<0+linha<<" ";
			}
			else{
				cout<<"";
			}
			for(coluna=0; coluna<10; coluna++){
				if(campo[linha][coluna]==0){
					cout<<"* ";
				}
				if(campo[linha][coluna]==9){
					cout<<"* ";
				}
				if(campo[linha][coluna]==8){
					cout<<"* ";
				}
				if(campo[linha][coluna]==7){
					cout<<"* ";
				}
				if(campo[linha][coluna]==6){
					cout<<"* ";
				}
				if(campo[linha][coluna]==5){
					cout<<"* ";
				}
				if(campo[linha][coluna]==4){
					cout<<"* ";
				}
				if(campo[linha][coluna]==3){
					cout<<"* ";
				}
				if(campo[linha][coluna]==2){
					cout<<"* ";
				}
				if(campo[linha][coluna]==1){
					cout<<"* ";
				}
				if(campo[linha][coluna]==10){
					cout<<"0 ";
				}
				if(campo[linha][coluna]==19){
					cout<<"b ";
				}
				if(campo[linha][coluna]==11){
					cout<<"1 ";
				}
				if(campo[linha][coluna]==12){
					cout<<"2 ";
				}
				if(campo[linha][coluna]==13){
					cout<<"3 ";
				}
				if(campo[linha][coluna]==14){
					cout<<"4 ";
				}
				if(campo[linha][coluna]==15){
					cout<<"5 ";
				}
				if(campo[linha][coluna]==16){
					cout<<"6 ";
				}
				if(campo[linha][coluna]==17){
					cout<<"7 ";
				}
				if(campo[linha][coluna]==18){
					cout<<"8 ";
				}
				else{
					cout<<"";
				}
			}
			cout<<"\n";
		}
		cout<<"Digite uma linha: \n";
		cin>>x;
		cout<<"Digite uma coluna: \n";
		cin>>y;
		cout<<endl;
		
		if(campo[x][y]==0){
			campo[x][y]=10;
		}
		if(campo[x][y]==1){
			campo[x][y]=11;
		}
		if(campo[x][y]==2){
			campo[x][y]=12;
		}
		if(campo[x][y]==3){
			campo[x][y]=13;
		}
		if(campo[x][y]==4){
			campo[x][y]=14;
		}
		if(campo[x][y]==5){
			campo[x][y]=15;
		}
		if(campo[x][y]==6){
			campo[x][y]=16;
		}
		if(campo[x][y]==7){
			campo[x][y]=17;
		}
		if(campo[x][y]==8){
			campo[x][y]=18;
		}
		if(campo[x][y]==9){
			campo[x][y]=19;
			cout<<"Uma bomba foi selecionada, voce perdeu.";
			cout<<"\n     FIM DE JOGO "<<endl<<endl;
			exit(0);
		}
		jogadas++;
		cout<<"jogada: "<<jogadas<<endl<<endl;
		
		if(campo[x][y]!=9 && (jogadas==93)){
			cout<<" Voce venceu, FIM DE JOGO."<<endl<<endl;
			exit(0);
		}
	}
	return(0);
}
