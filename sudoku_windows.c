#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
int nn = 9;
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;


void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}


void generate_tab(int t[nn]){
	srand((int) time(NULL));
	int p,k,t1[nn],i,u,j;
	for (i=0;i<nn;i++)
		t[i] = (rand() % nn) + 1;
		
	do{
	p=0;
	k=0;
	
		
		for(j=0;j < nn;j++){
		
			t1[p] = t[j];
		
				for(u=0;u<p;u++){
				if(t[j] == t1[u])
				k++;
				}
				if(k>=1){
					t[j] = (rand() % nn) + 1;
				}
				p++;
	}
}while(k != 0);
}




int player_check_colone(int m[nn][nn],int p){
	int t[nn],i,j,l,k;
	p = 0;
	for(i=0;i<nn;i++){
	k=0;
		for(j=0;j<nn;j++){
			if(m[j][i] > 0){
			t[k] = m[j][i];
			for(l=0;l<k;l++){
				if(t[l] == t[k]){
					printf("error : Number: %d in column %d	",t[k],i+1);
					printf("\n");
					p = 1;
			}
			}
			k++;
		}
	}
}
return p;
}

int player_check_ligne(int m[nn][nn],int p){
	int t[nn],i,j,l,k;
	p = 0;
	for(i=0;i<nn;i++){
	k=0;
		for(j=0;j<nn;j++){
			if(m[i][j] > 0){
			t[k] = m[i][j];
			for(l=0;l<k;l++){
				if(t[l] == t[k]){
						printf("error : Number: %d in line %d	",t[k],i+1);
						printf("\n");
					p = 1;
			}
			}
			k++;
		}
	}
}
return p;
}

int player_check_mat(int m[nn][nn],int yyy){
	int t[100];	
	int k,p,j,i,v,l,c,b,kk,ll;
	yyy = 0;int box = 0;
	p = 0 ; i = 3;
	for (b = 0 ;b  < 3 ; b ++){
		k = 0 ; j = 3;
		for(v = 0 ; v < 3 ; v++){
				kk=0;box++;
			for(l = p; l < i; l++){
				for(c=k;c<j;c++){
					if(m[l][c] > 0){
						t[kk] = m[l][c];
						for(ll=0;ll<kk;ll++){
							if(t[ll] == t[kk]){
									printf("error : Number: %d in box %d	",t[kk],box);
									printf("\n");
								yyy = 1;								
							}
						}
						kk++;
					}
				}
			}
			k = k+3;j=j+3;
		}
	p=p+3;i=i+3;	 
	}
	return yyy;
}


void check(int m[nn][nn]){
	int checker=0,cm=0,cl=0,cc=0;
	cm=player_check_mat(m,cm);
	cl=player_check_ligne(m,cl);
	cc=player_check_colone(m,cc);
	if((cm == 1) || (cl == 1) || (cc == 1))
	checker = 1;
	if(checker == 1)
	printf("WRONG!\n");
	if (checker == 0)
	printf("ALL GOOD!\n");
	}
	
	
	
void generate_f(int m[nn][nn],int t[nn]){
	int i,j,jj,k,p,l,v,c;
	int b,kk,kkk;
	k = 0 ; j = 3;
	for (b = 0 ;b  < 3 ; b ++){
		p = 0 ; i = 3;
		for(v = 0 ; v < 3 ; v++){
			kk=0;
			for(l = p; l < i; l++){
				for(c=k;c<j;c++){
					m[l][c] = t[kk];
					kk++;
				}
			}
			p=p+3;i=i+3;
			jj=t[8];
				for(kkk=8;kkk>0;kkk--){
				t[kkk] = t[kkk-1];
			}
			t[0]=jj;
		}k = k+3;j=j+3;
	}
	
}

void generate(int mm[nn][nn],int m[nn][nn],int mn[nn][nn]){
	int l,c,i,j,tl[43],tc[43],p=0;
	srand((int) time(NULL));
	for(i=0;i<nn;i++){
		for(j=0;j<nn;j++){
			mm[i][j] = m[i][j];
		}
	}
	int checkl;
	for(i=0;i<43;i++){
		l=rand() % nn;
		tl[p] = l;
		c=rand() % nn;
		tc[p] = c;
		do{
			checkl=0;
			for(j=0;j<p;j++){
				if(tl[j] == l && tc[j] == c){
					checkl=1;
					l=rand() % nn;
					c=rand() % nn;
					break;
				}
				
			}
		}while(checkl == 1);
		p++;
		mm[l][c] = 0;
	}
for(i=0;i<nn;i++){
		for(j=0;j<nn;j++){
			mn[i][j] = mm[i][j];
		}
	}
}


void affiche(int m[nn][nn],int mm[nn][nn],int mn[nn][nn],int n){
	int i,j,l;
	setTextColor(stdout,TC_RED);
	printf("     1  2  3   4  5  6   7  8  9  ");
		if (n == 1){
			setTextColor(stdout,TC_BLUE);
			printf("\tSOLUTION: ");
			setTextColor(stdout,TC_WHITE);
		}
		printf("\n");
	setTextColor(stdout,TC_WHITE);
	printf("\n");
	
	for(i=0;i<nn;i++){
		for(j=0;j<nn;j++){
			if(j == 0){
				setTextColor(stdout,TC_RED);
			printf("%d   ",i+1);
			setTextColor(stdout,TC_WHITE);
			printf("|");
		}
			if(m[i][j] > 0){
				if(mm[i][j] > 0)
			setTextColor(stdout,TC_GREEN);
			printf("%d ",m[i][j]);
			setTextColor(stdout,TC_WHITE);
			printf("|");
			}else{
			setTextColor(stdout,TC_WHITE);
			printf("  |");
		}
			if(j == 2 || j == 5 )
			printf("|");
			
				
		}
		if(n==1){
		printf("\t");
		for(l=0;l<nn;l++){
				if(mm[i][l] > 0)
			setTextColor(stdout,TC_GREEN);
			printf("%d ",mn[i][l]);
			setTextColor(stdout,TC_WHITE);
			printf("|");
		
	}
}
		printf("\n");
	
		if( i == 5 || i == 2 )
		    printf("   -----------------------------\n");
	}
	
}


void player_insert(int mn[nn][nn],int mm[nn][nn]){
	int c,l,rep;
	a:
	do{
		printf("insert line number 1 ~ %d: ",nn);scanf("%d",&l);
		if( l == 0)
		goto d;
	}while((l < 0) || (l > nn));
	do{
		printf("insert column number 1 ~ %d: ",nn);scanf("%d",&c);
		if( c == 0)
		goto d;
	}while((c < 0) || (c > nn));
	if (mm[l-1][c-1] > 0){
		printf("invalid position\n");
		goto a;
	}
	do{
		printf("insert number 1 ~ %d: ",nn);scanf("%d",&rep);
		if (rep == 0)
		goto d;
	}while((rep < 0) || (rep > nn));
mn[l-1][c-1] = rep;
d:
	l = 0;
}


void player_delete(int mn[nn][nn],int mm[nn][nn]){
	int c,l;
	a:
	do{
		printf("insert line number 1 ~ %d: ",nn);scanf("%d",&l);
		if(l == 0)
		goto d;
	}while((l < 0) || (l > nn));
	do{
		printf("insert column number 1 ~ %d: ",nn);scanf("%d",&c);
		if(c == 0)
		goto d;
	}while((c < 0) || (c > nn));
	if (mm[l-1][c-1] > 0){
		printf("invalid position\n");
		goto a;
	}
	if (mn[l-1][c-1] < 0){
		printf("invalid position\n");
		goto a;
	}
	
mn[l-1][c-1] = -1;
 d:
 	l = 0;
}

void reset(int mn[nn][nn],int mm[nn][nn]){
	int i,j;
	for(i=0;i<nn;i++){
		for(j=0;j<nn;j++){
			mn[i][j] = mm[i][j] ;
		}
	}
}


	

	
int main(){
int t[nn],m[nn][nn];int mm[nn][nn];int mn[nn][nn];	
int rep;
int n;

printf("this is a simple sudoku game, you can generate boards, insert numbers,delete numbers,reset board and check ur board\n");
system("pause");
system("cls");

a:
	generate_tab(t);
	generate_f(m,t);
	generate(mm,m,mn);
	affiche(mm,mn,m,n);
	n=0;
b:	
	printf("\nwhat u gonna do ? \n");
	printf("0_generate_new_board  \n");
	printf("1_insert(enter 0 to cancel)  \n");
	printf("2_check  \n");
	printf("3_delete(enter 0 to cancel)  \n");
	printf("4_reset  \n");
	if(n==0)
	printf("5_show solution\n");
	if(n==1)
	printf("5_hide solution\n");
	printf("7_quit  \n");
	scanf("%d",&rep);
	switch(rep){
		case 0:system("cls");goto a;break;
		case 1:player_insert(mm,mn);system("cls");affiche(mm,mn,m,n);goto b;break;
		case 2:check(mm);system("pause");system("cls");affiche(mm,mn,m,n);goto b;break;
		case 3:player_delete(mm,mn);system("cls");affiche(mm,mn,m,n);goto b;break;
		case 4:reset(mm,mn);system("cls");affiche(mm,mn,m,n);goto b;break;
		case 5:if (n==0) n = 1;else n = 0;system("cls");affiche(mm,mn,m,n);goto b;break;
		case 6:break;
		default:printf("invalid choice\n");goto b;break;
	}
	system("pause");
return 0;	
}


