#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
int main()
{
	cout << "!!!!! All Rihgts Reserved By NgX" << endl
		 << "!!!!! Welcome !!!" << endl;

int i,j;
int const k=50;
int fans,dim,counter,ntry;
int acounter[k],bcounter[k],guess[k];
int *ans,*gue;
int tmp,tmp2;
char yn;
// generating the number to guess !
	getdim:
	cout << " 請輸入所要猜數字之位數..." << endl;
	cin >> dim ;
	if(dim >=11)
	{
		cout << " 位數過大，請重新輸入..." << endl;
		goto getdim;
	}
	cout << " 產生" << dim << "位數字中..." << endl;
	ans = new int[dim];
	gue = new int[dim];
	srand(time(NULL));
	for(i=0;i<=dim-1;i++)
	{
		gennum:
		
		if(i == 0)
			ans[i]=int((rand()%9)+1);
		else
			ans[i]=int((rand()%10));
		counter=0;

// check for the repeated num
		for(j=0;j<i;j++)
		{
			if(ans[i] == ans[j])
				counter=counter+1;
			if(counter >= 1)
				goto gennum;
		}
	}

	// get the ANS
		fans=0;
	for(i=0;i<=dim-1;i++)
	{
		tmp=dim-1-i;
		fans=fans+int(ans[i]*pow(10.,tmp));
	}

//	cout << fans << endl;
//  generating posible ans

	
	
//	cout << ans[i] << endl;
	
	ntry=1;	
	guessnum:
	cout << " ______________________________________ "<< endl;
	cout << "    此 " << dim << " 位數為何？ 不想猜請輸入 777 " << endl ;
	cin >> guess[ntry] ;
	if(guess[ntry] == 777)
			goto showans;
	if(guess[ntry] >= pow(10.,dim) || guess[ntry] <= pow(10.,dim-1))
	{
		cout << " 輸入數字位數錯誤，請重新輸入" << endl;
		goto guessnum;
	}
		

	// start 
	tmp2 = guess[ntry];
	for(i=dim-1;i>0-1;i--)
	{
		tmp=dim-1-i;
		gue[tmp]=int(tmp2/int(pow(10.,i)));
		tmp2=int(tmp2-gue[tmp]*pow(10.,i));
			
	}

	tmp=0;
	for(i=0;i<=dim-1;i++)
		for(j=1;j<=dim-1;j++)
			if(i != j && gue[i] == gue[j])
				tmp=tmp+1;
	if(tmp >=1)
	{
		cout << " 有重複數字，請重新輸入...." << endl;
		goto guessnum;
	}

//	for(i=0;i<=dim-1;i++)
//		cout << gue[i] ;

	// XAXB
	
	acounter[ntry]=0;
	for(i=0;i<=dim-1;i++)
	{
		if(gue[i] == ans[i])
 			acounter[ntry]=acounter[ntry]+1;
 
	}
	bcounter[ntry]=0;
// 	cout << acounter[ntry] << "A" << endl;
	for(i=0;i<=dim-1;i++)
	{
		for(j=0;j<=dim-1;j++)
		{
			if(i != j && ans[i] == gue[j])
				bcounter[ntry]=bcounter[ntry]+1;
		}
	}
//	cout << bcounter[ntry] ;

	cout << " ______________________________________ "<< endl;

	if(acounter[ntry] != dim)
	{
		
		for(i=1;i<=ntry;i++)
			cout << i << ") " << guess[i] << " → " << acounter[i] << "A " << bcounter[i] << "B "<< endl;
		ntry=ntry+1;
		goto guessnum;
	}

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << " Congratulations !! GREAT !! 你使用了 " << ntry << " 次猜到^_^！" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	showans:
	cout << "  答案為 < " << fans << " > "<< endl;

	cout << "  再玩一次嗎 A_A  (y/n) ？" << endl;
	cin >> yn ;
		if( yn == 'y'|| yn == 'Y')
			goto getdim;

//	system("pause");
	return 0;
 }