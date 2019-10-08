//八皇后维护矩阵法
#include<iostream>
using namespace std;
int cheese_table[8][8];
int queen[8];//记录五个皇后的列数
int lastqueen=-1;
int solution=0;
int search_line(int i,int j){//搜寻这一行有没可放的位置
	for(;j<8;j++)
		if(cheese_table[i][j]==0)
			return j;
	return -1;
}
void set_queen(int i,int j){//在可放的位置上放上皇后记录下来并对棋盘进行操作
	cheese_table[i][j]=-1;
	queen[i]=j;
	for(int temp=0;temp<8;temp++)//列操作
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]++;
	for(int temp=0;temp<8;temp++)//行操作
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]++;
	int tempj=j+1;
	for(int tempi=i+1;tempi<8&&tempj<8;tempi++)//东南对角线操作
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(int tempi=i+1;tempi<8&&tempj>=0;tempi++)//东北对角线操作
		cheese_table[tempi][tempj--]++;
	tempj=j+1;
	for(int tempi=i-1;tempi>=0&&tempj<8;tempi--)//西南对角线操作
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(int tempi=i-1;tempi>=0&&tempj>=0;tempi--)//西北对角线操作
		cheese_table[tempi][tempj--]++;
	return;
}
void uptake_queen(int i){
	int j=queen[i];
	for(int temp=0;temp<8;temp++)//列操作
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]--;
	for(int temp=0;temp<8;temp++)//行操作
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]--;
	int tempj=j+1;
	for(int tempi=i+1;tempi<8&&tempj<8;tempi++)//东南对角线操作
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(int tempi=i+1;tempi<8&&tempj>=0;tempi++)//东北对角线操作
		cheese_table[tempi][tempj--]--;
	tempj=j+1;
	for(int tempi=i-1;tempi>=0&&tempj<8;tempi--)//西南对角线操作
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(int tempi=i-1;tempi>=0&&tempj>=0;tempi--)//西北对角线操作
		cheese_table[tempi][tempj--]--;
	cheese_table[i][j]=0;
	return;
}
int main(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			cheese_table[i][j]=0;
	//初始化棋盘
	for(int i=0;;i++){//一行一行操作
		int	j=search_line(i,lastqueen+1);
		if(j==-1){//没有放皇后的位置了，回头
			if(i==0)break;//真正结束位置
			uptake_queen(i-1);
			lastqueen=queen[i-1];//把上一行的queen的位置记录下来，便于回头的时候从这个位置之后寻找可放位置
			i-=2;
		}
		else{//把棋盘对应位置放上皇后，对这个皇后会影响的棋格进行操作
			lastqueen=-1;
			set_queen(i,j);
			if(i==7){
				for(int i=0;i<8;i++){
					for(int j=0;j<8;j++)
						cout<<cheese_table[i][j]<<"	";
					cout<<endl;	
				}
				solution++;
				cout<<endl<<endl;
				uptake_queen(7);
				lastqueen=j;
				i--;

			}
		}
	}
	cout<<solution<<endl;
	
	return 0;
}





////八皇后迭代解法
//#include<iostream>
//using namespace std;
//int count=0;
//int queen[8]={-1,-1,-1,-1,-1,-1,-1,-1};
//bool available(int pointi,int pointj){//判断某个皇后是否与已有皇后冲突
//	for(int i=0;i<pointi;i++){
//		if(pointi==i)return false;//同一行拒绝
//		if(pointj==queen[i])return false;//同一列拒绝
//		if((pointi-i)==(pointj-queen[i]))return false;//同一主对角线拒绝
//		if((pointi-i)+(pointj-queen[i])==0)return false;//同一副对角线拒绝
//	}
//	return true;
//}
//int main(){
//	int j=0;
//	for(int i=0;i<8;i++){//对于每一行
//		if(i==-1)break;//这才是真正退出循环的出口
//		for(;j<8;j++){
//			if(available(i,j)){
//				queen[i]=j;
//				if(i==7){
//					count++;
//					if(j==7){//如果最后一行最后一格试完就往前回溯
//						j=queen[--i];
//						j++;
//						queen[i]=-1;
//						i--;
//						break;
//					}
//					else
//						continue;
//				}
//				j=0;
//				break;
//			}
//			else
//				if(i==7&&j==7){
//					j=queen[--i];
//					j++;
//					queen[i]=-1;
//					i--;
//					break;
//				}
//		}
//		if(j==8){
//				j=queen[--i];
//				j++;
//				queen[i]=-1;
//				i--;
//		}
//	}
//	cout<<count<<endl;
//	return 0;
//}



////八皇后递归解法
//#include<iostream>
//using namespace std;
//int queen[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
//int count=0;
//bool available(int pointi,int pointj){//判断某个皇后是否与已有皇后冲突
//	for(int i=1;i<pointi;i++){
//		if(pointj==queen[i])return false;//同一列拒绝
//		if((pointi-i)==(pointj-queen[i]))return false;//同一主对角线拒绝
//		if((pointi-i)+(pointj-queen[i])==0)return false;//同一副对角线拒绝
//	}
//	return true;
//}
//void findSpace(int queenNumber){//在第queenNumber行找能放皇后的位置
//	for(int i=1;i<9;i++){//从1~8遍历这一行的八个空位
//		if(available(queenNumber,i)){//如果可以放这个位置就记录下第queenNumber个皇后的位置
//			queen[queenNumber]=i;
//			if(queenNumber==8){//如果八个皇后都放满了统计一下
//				count++;
//				return;
//			}
//			int nextNumber=queenNumber+1;//还有皇后没放递归放下一个皇后
//			findSpace(nextNumber);
//		}
//	}
//	queen[--queenNumber]=-1;//如果这一行没有可放的位置说明上一行皇后放的位置不行，要为上一个皇后寻找新的可放位置
//	return;
//}
//int main(){
//	findSpace(1);//从（1，1）开始递归好理解
//	cout<<count<<endl;
//	return 0;
//}


////八皇后手动维护堆栈解法
//#include<iostream>
//using namespace std;
//int QueenNumber=0;
//int solutionCount=0;
//int stopflag=0;
//struct point{
//	int pointi;
//	int pointj;
//}queenPoint[8];
//bool available(int pointi,int pointj);
//void backward();
//void refresh(int pointi,int pointj);
//int main(){
//	for(int i=0;i<8;i++)
//		queenPoint[i].pointi=queenPoint[i].pointj=-1;
//	//从（0，0）格子开始递归
//	refresh(0,0);
//	cout<<solutionCount<<endl;
//	return 0;
//}
//bool available(int pointi,int pointj){
//	for(int i=0;i<QueenNumber;i++){
//		if(pointi==queenPoint[i].pointi)return false;//同一行拒绝
//		if(pointj==queenPoint[i].pointj)return false;//同一列拒绝
//		if((pointi-queenPoint[i].pointi)==(pointj-queenPoint[i].pointj))return false;
//		//同一主对角线拒绝
//		if((pointi-queenPoint[i].pointi)+(pointj-queenPoint[i].pointj)==0)return false;
//		//同一副对角线拒绝
//	}
//	//都没问题返回可以
//	return true;
//}
//void backward(){
//	QueenNumber--;
//	int tempi=queenPoint[QueenNumber].pointi;
//	int tempj=queenPoint[QueenNumber].pointj;
//	queenPoint[QueenNumber].pointi=queenPoint[QueenNumber].pointj=-1;
//	if(QueenNumber<0)stopflag=1;;
//	refresh(tempi,++tempj);
//}
//void refresh(int pointi,int pointj){
//	//先是两种特殊情况的判断
//	if(stopflag==1)return;
//	if(pointj==8)
//		backward();
//	//某一格可放就更新信息往下行递归
//	if(available(pointi,pointj)){
//		queenPoint[QueenNumber].pointi=pointi;
//		queenPoint[QueenNumber].pointj=pointj;
//		QueenNumber++;
//		//如果八个皇后都放完就计数回溯
//		if(QueenNumber==8){
//			solutionCount++;
//			backward();
//		}
//		//否则往下递归
//		else
//			refresh(++pointi,0);
//	}
//	//某一格不可放就往下一个格子递归
//	else{
//		//如果某一行都不行就回溯
//		if(pointj==7)
//			backward();
//		else
//			refresh(pointi,++pointj);
//	}
//}