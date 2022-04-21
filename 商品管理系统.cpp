#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Goods
{
protected:
	string kind;
	string name;
	int number;
	int price;
public:
	Goods(){}
	Goods(string kind_,string name_,int num,int price_):kind(kind_),name(name_),number(num),price(price_){}
   virtual void show() 
	{
		cout<<left<<setw(12)<<this->kind<<left<<setw(12)<<this->name<<left<<setw(12)<<this->number
		<<left<<setw(12)<<this->price;
	}
	virtual string getkind(){return kind;}
	virtual string getname(){return name;}
	int getnum(){return number;}
	int getpri(){return price;}
	virtual string getmem(){return 0;}
	virtual string getpro(){return 0;}
	virtual string getsys(){return 0;}
	virtual string getco(){return 0;}
	virtual string getsty(){return 0;}
	virtual string getau(){return 0;}
};
class Digital:public Goods
{
private:
	string memory;
	string processor;
	string system;
public:
	Digital(string k,string n,int num,int p,string m,string pr,string sy):memory(m),processor(pr),system(sy),Goods(k,n,num,p){}
	virtual void show()
	{Goods::show();
	cout<<left<<setw(12)<<this->memory<<left<<setw(12)<<this->processor<<left<<setw(12)<<this->system<<endl;
	}
	virtual string getname(){return this->name;}
	virtual string getkind(){return this->kind;}
	virtual string getmem(){return this->memory;}
	virtual string getpro(){return this->processor;}
	virtual string getsys(){return this->system;}
};
class Per:public Goods
{
private:
	string color;
	string style;
public:
	Per(string k,string n,int num,int p,string c,string s):Goods(k,n,num,p),color(c),style(s){}
	virtual void show()
	{
	Goods::show();
	cout<<left<<setw(12)<<this->color<<left<<setw(12)<<this->style<<endl;
}
	virtual string getkind(){return this->kind;}
	virtual string getname(){return this->name;}
	virtual string getco(){return this->color;}
	virtual string getsty(){return this->style;}
};	
class Life:public Goods
{
public:
	Life(string k,string n,int num,int p):Goods(k,n,num,p){}
	virtual void show(){Goods::show();cout<<endl;}
	virtual string getkind(){return this->kind;}
	virtual string getname(){return this->name;}
};
class Book:public Goods
{
private:
	string auther;
public:
	Book(string k,string n,int num,int p,string a):Goods(k,n,num,p),auther(a){}
	virtual void show()
	{
		Goods::show();
	cout<<left<<setw(12)<<this->auther<<endl;
	}
	virtual string getkind(){return this->kind;}
	virtual string getname(){return this->name;}
	virtual string getau(){return this->auther;}
};
void Show(Goods *p[],int n)
{
	string k;
	int m=1;
	while(true)
	{
		int j=0,check=0;
		cout<<"��������Ҫ�鿴����Ʒ���������Ʒ�����������롢���衢������Ʒ��ͼ�飺";
		cin>>k;
		if(k=="��������"){j=1;
		cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"
			<<left<<setw(12)<<"�ڴ�(�˴�)"<<left<<setw(12)<<"������"<<left<<setw(12)<<"ϵͳ"<<endl;}
		else if(k=="����"){j=1;
		cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"
			<<left<<setw(12)<<"��ɫ"<<left<<setw(12)<<"����"<<endl;}
		else if(k=="������Ʒ"){j=1;
		cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"<<endl;}
		else if(k=="ͼ��"){j=1;
		cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"
			<<left<<setw(12)<<"����"<<endl;}
		int i=0;
		for(;i<n;i++)
		{
			if(p[i]->getkind()==k&&j==1)
			{
				check=1;
				p[i]->show();
			}
			else if(p[i]->getname()==k&&j==0)
			{
				check=1;
				if(p[i]->getkind()=="��������")
					cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"
					<<left<<setw(12)<<"��Ǯ"<<left<<setw(12)<<"�ڴ�(�˴�)"<<left<<setw(12)<<"������"<<"ϵͳ"<<endl;
				else if(p[i]->getkind()=="����")
					cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"
					<<left<<setw(12)<<"��ɫ"<<left<<setw(12)<<"����"<<endl;
				else if(p[i]->getkind()=="������Ʒ")
					cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"<<endl;
				else if(p[i]->getkind()=="ͼ��")
					cout<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ǯ"
					<<left<<setw(12)<<"����"<<endl;
				p[i]->show();
			}
		}
		if(check==0&&j==1)
			cout<<"�̳��޴�������Ʒ"<<endl;
		else if(check==0&&j==0)
			cout<<"�̳����޴���Ʒ"<<endl;
		cout<<"������ѯ������1,�˳�������0"<<endl;
		cin>>m;
		if(m==0)
			break;
	}
}
int main()
{
	string choose;
	string kind_,name_,mem,pro,sys,co,sty,au;
	int num,pri;
	int leng=0,i=0,flag=0,conti;
	int bflag=0;
	ifstream infile("��Ʒ����.txt",ios::in);
	if(!infile)
		cout<<"���ļ�ʧ��"<<endl;
	getline(infile,choose,'\n');
	Goods *p[300];
	while(infile>>kind_)
	{
		flag=1;
		leng++;
		if(kind_=="��������")
		{
			infile>>name_>>num>>pri>>mem>>pro>>sys;
			p[i]=new Digital(kind_,name_,num,pri,mem,pro,sys);
		}
		else if(kind_=="����")
		{
			infile>>name_>>num>>pri>>co>>sty;
			p[i]=new Per(kind_,name_,num,pri,co,sty);
		}
		else if(kind_=="������Ʒ")
		{
			infile>>name_>>num>>pri;
			p[i]=new Life(kind_,name_,num,pri);
		}
		else if(kind_=="ͼ��")
		{
			infile>>name_>>num>>pri>>au;
			p[i]=new Book(kind_,name_,num,pri,au);
		}
		i++;
	}
	if(!flag)
		cout<<"�ļ�������Ʒ��Ϣ�������"<<endl;
	infile.close();
	while(true)
	{
		cout<<"��������Ҫ���еĲ���:չʾ�����ӡ����棺";
		cin>>choose;
		if(choose=="չʾ")
			Show(p,leng);
		else if(choose=="����")
		{
			while(true)
			{
				cout<<"��������Ҫ���ӵ���Ʒ������:";cin>>kind_;
				cout<<"��Ʒ��:";cin>>name_;
				cout<<"��Ʒ����:";cin>>num;
				cout<<"��Ʒ�۸�:";cin>>pri;
				if(kind_=="��������")
				{
					cout<<"��Ʒ�ڴ�(�˴�):";cin>>mem;
					cout<<"��Ʒ������:";cin>>pro;
					cout<<"��Ʒϵͳ:";cin>>sys;
					p[leng]=new Digital(kind_,name_,num,pri,mem,pro,sys);
					leng++;
				}
				else if(kind_=="����")
				{
					cout<<"��Ʒ��ɫ:";cin>>co;
					cout<<"��Ʒ����:";cin>>sty;
					p[leng]=new Per(kind_,name_,num,pri,co,sty);
					leng++;
				}
				else if(kind_=="ͼ��")
				{
					cout<<"ͼ������:";cin>>au;
					p[leng]=new Book(kind_,name_,num,pri,au);
					leng++;
				}
				else if(kind_=="������Ʒ")
				{
					p[leng]=new Life(kind_,name_,num,pri);
					leng++;
				}
				cout<<"�������������1���˳�������0"<<endl;cin>>conti;
				if(conti==0)
					break;
			}
		}
		else if(choose=="����")
		{
			bflag=1;
			ofstream desfile("��Ʒ����.txt",ios::out);
			desfile<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(6)<<"����"<<left<<setw(6)<<"�۸�"
				<<"����"<<endl;
			for(i=0;i<leng;i++)
			{
				desfile<<left<<setw(12)<<p[i]->getkind()<<left<<setw(12)<<p[i]->getname()<<left<<setw(6)<<p[i]->getnum()<<left<<setw(6)<<p[i]->getpri();
				if(p[i]->getkind()=="��������")
					desfile<<p[i]->getmem()<<" "<<p[i]->getpro()<<" "<<p[i]->getsys()<<endl;
				else if(p[i]->getkind()=="����")
					desfile<<p[i]->getco()<<" "<<p[i]->getsty()<<endl;
				else if(p[i]->getkind()=="ͼ��")
					desfile<<p[i]->getau()<<endl;
				else if(p[i]->getkind()=="������Ʒ")
					desfile<<endl;
			}
			desfile.close();
		}
		cout<<"��������������1���˳�������0"<<endl;
		cin>>conti;
		if(conti==0)
			break;
		}
		if(bflag==0)
		{
			cout<<"�Ƿ񱣴��������������(��:1  ��:0)��";
			cin>>bflag;
			if(bflag==1)
			{
				ofstream desfile("��Ʒ����.txt",ios::out);
				desfile<<left<<setw(12)<<"����"<<left<<setw(12)<<"��Ʒ"<<left<<setw(6)<<"����"<<left<<setw(6)<<"�۸�"
				<<"����"<<endl;
			for(i=0;i<leng;i++)
			{
				desfile<<left<<setw(12)<<p[i]->getkind()<<left<<setw(12)<<p[i]->getname()<<left<<setw(6)<<p[i]->getnum()<<left<<setw(6)<<p[i]->getpri();
				if(p[i]->getkind()=="��������")
					desfile<<p[i]->getmem()<<" "<<p[i]->getpro()<<" "<<p[i]->getsys()<<endl;
				else if(p[i]->getkind()=="����")
					desfile<<p[i]->getco()<<" "<<p[i]->getsty()<<endl;
				else if(p[i]->getkind()=="ͼ��")
					desfile<<p[i]->getau()<<endl;
				else if(p[i]->getkind()=="������Ʒ")
					desfile<<endl;
			}
			desfile.close();
			}
		}
	return 0;
}