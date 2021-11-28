#include <iostream>
using namespace std;
class cnode
{
public:
	char s1[8][8];
	
	int place;
	cnode *pnext;
};
class clist
{
public:
	cnode * phead;
	cnode * ptail;
	clist()
	{
		phead = '\0';
		ptail = '\0';
	}
	~clist()
	{
		cnode *ptrav;
		ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void attach(cnode *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};
class cstack
{
public:
	cnode*phead;
	cstack()
	{
		phead = NULL;
	}
	void push(cnode*pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}
	cnode* pop()
	{
		if (phead == NULL)
		{
			return NULL;
		}
		cnode*ptrav = phead;
		phead = phead->pnext;
		ptrav->pnext = NULL;
		return ptrav;
	}
};
void expandchild(cnode * pcur,cstack & s,int& cts)
{
	for (int k = 0; k < 8; k++)
	{
		cnode* pchild = new cnode;
		int flag = 0,i,j;
		for(int i=0;i<8;i++)
		{
			for (int j = 0;j<8;j++)
			{
				pchild->s1[i][j] = pcur->s1[i][j];
			}
		}
		pchild->place = pcur->place + 1;
		pchild->s1[pcur->place][k] = 'q';
		for (i = pcur->place + 1; i < 8; i++)
		{
			if (pchild->s1[i][k] == pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
		}
		for(i= pcur->place - 1;i>-1;i--)
		{
			if (pchild->s1[i][k] == pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
		}



		int v = pcur->place;
		v++;
		for(i=k+1;i<(8- pcur->place+1);i++)
		{	if(pchild->s1[v][i]== pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
		v++;
		}
		 v = pcur->place;
		v--;
		for (i = k -1; i > -1; i--)
		{
			if (pchild->s1[v][i] == pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
			v--;
		}


		 v = pcur->place;
		v++;
		for (i = k-1; i >-1; i--)
		{
			if (pchild->s1[v][i] == pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
			v++;
		}
		 v = pcur->place;
		v--;
		for (i = k + 1; i < 8; i++)
		{
			if (pchild->s1[v][i] == pchild->s1[pcur->place][k])
			{
				flag = 1;
			}
			v--;
		}
		if(flag==0)
		{
			int ct = 0;
			/*for(i=0;i<8;i++)
			{
				for (j = 0; j <8 ; j++)
				{
					cout << pchild->s1[i][j] << "|";
				}
				cout << endl;
			}
			cout << endl;
			cout << "------------------------------"<<endl;*/

			for(i=0;i<8;i++)
			{
				for (j = 0;j<8;j++)
				{	if(pchild->s1[i][j]=='q')
					{
						ct++;
					}
				}
			}
			if(ct==8)
			{
				cts++;
				cout << "the one of solution"<<endl;
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j++)
					{
						cout << pchild->s1[i][j] << "|";
					}
					cout << endl;
				}
				cout << endl;
				cout << "------------------------------" << endl;
			}

			s.push(pchild);
		}


		





	}










}
int main()
{
	cstack s;
	clist v;
	int cts = 0;
	cnode* pcur;


	pcur = new cnode;
	for(int i =0; i<8;i++)
	{
		for (int j = 0;j<8;j++)
		{
			pcur->s1[i][j] = ' ';
		}
	}
	
	
	pcur->pnext = NULL;
	pcur->place = 0;


	s.push(pcur);
	while (s.phead != NULL)
	{
		pcur = s.pop();
		expandchild(pcur,  s,cts);
	}
	cout << "number of solutions" << endl;
	cout << cts<<endl;
	system("pause");

}