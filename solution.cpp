//�˻ʺ�ά������
#include<iostream>
using namespace std;
int cheese_table[8][8];
int queen[8];//��¼����ʺ������
int lastqueen=-1;
int solution=0;
int search_line(int i,int j){//��Ѱ��һ����û�ɷŵ�λ��
	for(;j<8;j++)
		if(cheese_table[i][j]==0)
			return j;
	return -1;
}
void set_queen(int i,int j){//�ڿɷŵ�λ���Ϸ��ϻʺ��¼�����������̽��в���
	cheese_table[i][j]=-1;
	queen[i]=j;
	for(int temp=0;temp<8;temp++)//�в���
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]++;
	for(int temp=0;temp<8;temp++)//�в���
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]++;
	int tempj=j+1;
	for(int tempi=i+1;tempi<8&&tempj<8;tempi++)//���϶Խ��߲���
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(int tempi=i+1;tempi<8&&tempj>=0;tempi++)//�����Խ��߲���
		cheese_table[tempi][tempj--]++;
	tempj=j+1;
	for(int tempi=i-1;tempi>=0&&tempj<8;tempi--)//���϶Խ��߲���
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(int tempi=i-1;tempi>=0&&tempj>=0;tempi--)//�����Խ��߲���
		cheese_table[tempi][tempj--]++;
	return;
}
void uptake_queen(int i){
	int j=queen[i];
	for(int temp=0;temp<8;temp++)//�в���
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]--;
	for(int temp=0;temp<8;temp++)//�в���
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]--;
	int tempj=j+1;
	for(int tempi=i+1;tempi<8&&tempj<8;tempi++)//���϶Խ��߲���
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(int tempi=i+1;tempi<8&&tempj>=0;tempi++)//�����Խ��߲���
		cheese_table[tempi][tempj--]--;
	tempj=j+1;
	for(int tempi=i-1;tempi>=0&&tempj<8;tempi--)//���϶Խ��߲���
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(int tempi=i-1;tempi>=0&&tempj>=0;tempi--)//�����Խ��߲���
		cheese_table[tempi][tempj--]--;
	cheese_table[i][j]=0;
	return;
}
int main(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			cheese_table[i][j]=0;
	//��ʼ������
	for(int i=0;;i++){//һ��һ�в���
		int	j=search_line(i,lastqueen+1);
		if(j==-1){//û�зŻʺ��λ���ˣ���ͷ
			if(i==0)break;//��������λ��
			uptake_queen(i-1);
			lastqueen=queen[i-1];//����һ�е�queen��λ�ü�¼���������ڻ�ͷ��ʱ������λ��֮��Ѱ�ҿɷ�λ��
			i-=2;
		}
		else{//�����̶�Ӧλ�÷��ϻʺ󣬶�����ʺ��Ӱ��������в���
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





////�˻ʺ�����ⷨ
//#include<iostream>
//using namespace std;
//int count=0;
//int queen[8]={-1,-1,-1,-1,-1,-1,-1,-1};
//bool available(int pointi,int pointj){//�ж�ĳ���ʺ��Ƿ������лʺ��ͻ
//	for(int i=0;i<pointi;i++){
//		if(pointi==i)return false;//ͬһ�оܾ�
//		if(pointj==queen[i])return false;//ͬһ�оܾ�
//		if((pointi-i)==(pointj-queen[i]))return false;//ͬһ���Խ��߾ܾ�
//		if((pointi-i)+(pointj-queen[i])==0)return false;//ͬһ���Խ��߾ܾ�
//	}
//	return true;
//}
//int main(){
//	int j=0;
//	for(int i=0;i<8;i++){//����ÿһ��
//		if(i==-1)break;//����������˳�ѭ���ĳ���
//		for(;j<8;j++){
//			if(available(i,j)){
//				queen[i]=j;
//				if(i==7){
//					count++;
//					if(j==7){//������һ�����һ���������ǰ����
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



////�˻ʺ�ݹ�ⷨ
//#include<iostream>
//using namespace std;
//int queen[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
//int count=0;
//bool available(int pointi,int pointj){//�ж�ĳ���ʺ��Ƿ������лʺ��ͻ
//	for(int i=1;i<pointi;i++){
//		if(pointj==queen[i])return false;//ͬһ�оܾ�
//		if((pointi-i)==(pointj-queen[i]))return false;//ͬһ���Խ��߾ܾ�
//		if((pointi-i)+(pointj-queen[i])==0)return false;//ͬһ���Խ��߾ܾ�
//	}
//	return true;
//}
//void findSpace(int queenNumber){//�ڵ�queenNumber�����ܷŻʺ��λ��
//	for(int i=1;i<9;i++){//��1~8������һ�еİ˸���λ
//		if(available(queenNumber,i)){//������Է����λ�þͼ�¼�µ�queenNumber���ʺ��λ��
//			queen[queenNumber]=i;
//			if(queenNumber==8){//����˸��ʺ󶼷�����ͳ��һ��
//				count++;
//				return;
//			}
//			int nextNumber=queenNumber+1;//���лʺ�û�ŵݹ����һ���ʺ�
//			findSpace(nextNumber);
//		}
//	}
//	queen[--queenNumber]=-1;//�����һ��û�пɷŵ�λ��˵����һ�лʺ�ŵ�λ�ò��У�ҪΪ��һ���ʺ�Ѱ���µĿɷ�λ��
//	return;
//}
//int main(){
//	findSpace(1);//�ӣ�1��1����ʼ�ݹ�����
//	cout<<count<<endl;
//	return 0;
//}


////�˻ʺ��ֶ�ά����ջ�ⷨ
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
//	//�ӣ�0��0�����ӿ�ʼ�ݹ�
//	refresh(0,0);
//	cout<<solutionCount<<endl;
//	return 0;
//}
//bool available(int pointi,int pointj){
//	for(int i=0;i<QueenNumber;i++){
//		if(pointi==queenPoint[i].pointi)return false;//ͬһ�оܾ�
//		if(pointj==queenPoint[i].pointj)return false;//ͬһ�оܾ�
//		if((pointi-queenPoint[i].pointi)==(pointj-queenPoint[i].pointj))return false;
//		//ͬһ���Խ��߾ܾ�
//		if((pointi-queenPoint[i].pointi)+(pointj-queenPoint[i].pointj)==0)return false;
//		//ͬһ���Խ��߾ܾ�
//	}
//	//��û���ⷵ�ؿ���
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
//	//������������������ж�
//	if(stopflag==1)return;
//	if(pointj==8)
//		backward();
//	//ĳһ��ɷž͸�����Ϣ�����еݹ�
//	if(available(pointi,pointj)){
//		queenPoint[QueenNumber].pointi=pointi;
//		queenPoint[QueenNumber].pointj=pointj;
//		QueenNumber++;
//		//����˸��ʺ󶼷���ͼ�������
//		if(QueenNumber==8){
//			solutionCount++;
//			backward();
//		}
//		//�������µݹ�
//		else
//			refresh(++pointi,0);
//	}
//	//ĳһ�񲻿ɷž�����һ�����ӵݹ�
//	else{
//		//���ĳһ�ж����оͻ���
//		if(pointj==7)
//			backward();
//		else
//			refresh(pointi,++pointj);
//	}
//}