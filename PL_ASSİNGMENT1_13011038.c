#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int passArea(char areaMtr[10][100],int racerNum,int areaSize,char siralama[]);
int raceTour(int racerNum,int areaSize,char areaMtr[10][100],int waitingTime,char siralama[]);


int main(){
	
	int racerNum=5;			
	int areaSize=50;		
	char areaMtr[10][100];		
	int waitingTime=1;
	int menuCont=5,i,j;
	char siralama[]={' ',' ',' ',' ',' ',' ',' ',' '};
	srand(time(NULL));
	for(i=0;i<10;i++){
		for(j=0;j<100;j++){		
			areaMtr[i][j]='_';
		}
	}
	do{
	printf("----MENU----\n");
	printf("0-Yarisi Baslatmak icin basiniz\n");
	printf("1-Yarisci sayisini girmek icin basiniz\n");
	printf("2-Parkur uzunlugunu girmek icin basiniz\n");
	printf("3-Bekleme süresini girmek icin basiniz\n\n");
	scanf("%d",&menuCont);
	if (menuCont==1){
		printf("Yarisci sayisini giriniz:");
		scanf("%d",&racerNum);
	}
	else if (menuCont==2){
		printf("\nParkur uzunlugunu giriniz:");
		scanf("%d",&areaSize);
	}
	else if (menuCont==3){
		printf("\nBekleme suresini giriniz:");
		scanf("%d",&waitingTime);
	}
	else{}
	}while(menuCont!=0);
	
	for(i=0;i<racerNum;i++){
		areaMtr[i][0]='A'+i;	
	}
	raceTour(racerNum,areaSize,areaMtr,waitingTime,siralama);	


return 0;
}
int raceTour(int racerNum,int areaSize,char areaMtr[10][100],int waitingTime,char siralama[]){
	int i,j,counter;
	int lastSit[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int sira=0;
	int tmp=0;
	int find=0;	
	do{
	counter=0;		
 						     			   		  
	for(i=0;i<racerNum;i++){		
		tmp=0;
		find=0;
		do{
			if(siralama[tmp]=='A'+i){		// Yarışcının yarışı bitirip bitirmedigi kontrolu
				find=1;}			
			else{
			tmp=tmp+1;}	
		}while(find!=0 || tmp!=racerNum);		// find daha önceden yarısı bitirmis mi onu tutan degisken
		printf("tmp=%d------\n",tmp);			// tmp ise yarışcı yarışı bitirmediyse for döngüsüne girmemizi saglayan 								//degisken
		printf("find=%d---------\n",find);
		if(tmp=racerNum){		
			areaMtr[i][lastSit[i]]='_';
			int speed=1+rand()%5;				     
			int move=lastSit[i]+speed;		//yarış esnasında ilerlemeleri kaydeden bölüm 		      
			areaMtr[i][move]='A'+i;		
			lastSit[i]=move;				
		if (lastSit[i]>=areaSize){			//yarış bitti ise bitiren yarışcıyı kaydettigimiz bölüm
			areaMtr[i][areaSize-1]='A'+i;			
			siralama[sira]='A'+i;
			sira=sira+1;
			}				
		}
			
	}
	for(j=0;j<racerNum;j++){
		if(lastSit[j]>areaSize)
			counter=counter+1;	 	
	}
	passArea(areaMtr,racerNum,areaSize,siralama);					
	
	}while(counter!=racerNum);

}

int passArea(char areaMtr[10][100],int racerNum,int areaSize,char siralama[]){
	int i,j;

	for(i=0;i<racerNum;i++){
		for(j=0;j<areaSize;j++){
			printf("%c",areaMtr[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<racerNum;i++){
		printf("\n%d .= %c\n",i+1,siralama[i]);
	}
	
}







