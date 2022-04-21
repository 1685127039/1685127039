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
		cout<<"请输入需要查看的商品的种类或商品名：电子数码、外设、生活用品、图书：";
		cin>>k;
		if(k=="电子数码"){j=1;
		cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"
			<<left<<setw(12)<<"内存(运存)"<<left<<setw(12)<<"处理器"<<left<<setw(12)<<"系统"<<endl;}
		else if(k=="外设"){j=1;
		cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"
			<<left<<setw(12)<<"颜色"<<left<<setw(12)<<"类型"<<endl;}
		else if(k=="生活用品"){j=1;
		cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"<<endl;}
		else if(k=="图书"){j=1;
		cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"
			<<left<<setw(12)<<"作者"<<endl;}
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
				if(p[i]->getkind()=="电子数码")
					cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"
					<<left<<setw(12)<<"价钱"<<left<<setw(12)<<"内存(运存)"<<left<<setw(12)<<"处理器"<<"系统"<<endl;
				else if(p[i]->getkind()=="外设")
					cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"
					<<left<<setw(12)<<"颜色"<<left<<setw(12)<<"类型"<<endl;
				else if(p[i]->getkind()=="生活用品")
					cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"<<endl;
				else if(p[i]->getkind()=="图书")
					cout<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(12)<<"数量"<<left<<setw(12)<<"价钱"
					<<left<<setw(12)<<"作者"<<endl;
				p[i]->show();
			}
		}
		if(check==0&&j==1)
			cout<<"商城无此类型商品"<<endl;
		else if(check==0&&j==0)
			cout<<"商城暂无此商品"<<endl;
		cout<<"继续查询请输入1,退出请输入0"<<endl;
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
	ifstream infile("商品资料.txt",ios::in);
	if(!infile)
		cout<<"打开文件失败"<<endl;
	getline(infile,choose,'\n');
	Goods *p[300];
	while(infile>>kind_)
	{
		flag=1;
		leng++;
		if(kind_=="电子数码")
		{
			infile>>name_>>num>>pri>>mem>>pro>>sys;
			p[i]=new Digital(kind_,name_,num,pri,mem,pro,sys);
		}
		else if(kind_=="外设")
		{
			infile>>name_>>num>>pri>>co>>sty;
			p[i]=new Per(kind_,name_,num,pri,co,sty);
		}
		else if(kind_=="生活用品")
		{
			infile>>name_>>num>>pri;
			p[i]=new Life(kind_,name_,num,pri);
		}
		else if(kind_=="图书")
		{
			infile>>name_>>num>>pri>>au;
			p[i]=new Book(kind_,name_,num,pri,au);
		}
		i++;
	}
	if(!flag)
		cout<<"文件中无商品信息，请添加"<<endl;
	infile.close();
	while(true)
	{
		cout<<"请输入需要进行的操作:展示、增加、保存：";
		cin>>choose;
		if(choose=="展示")
			Show(p,leng);
		else if(choose=="增加")
		{
			while(true)
			{
				cout<<"请输入需要增加的商品的类型:";cin>>kind_;
				cout<<"商品名:";cin>>name_;
				cout<<"商品数量:";cin>>num;
				cout<<"商品价格:";cin>>pri;
				if(kind_=="电子数码")
				{
					cout<<"产品内存(运存):";cin>>mem;
					cout<<"产品处理器:";cin>>pro;
					cout<<"产品系统:";cin>>sys;
					p[leng]=new Digital(kind_,name_,num,pri,mem,pro,sys);
					leng++;
				}
				else if(kind_=="外设")
				{
					cout<<"产品颜色:";cin>>co;
					cout<<"产品类型:";cin>>sty;
					p[leng]=new Per(kind_,name_,num,pri,co,sty);
					leng++;
				}
				else if(kind_=="图书")
				{
					cout<<"图书作者:";cin>>au;
					p[leng]=new Book(kind_,name_,num,pri,au);
					leng++;
				}
				else if(kind_=="生活用品")
				{
					p[leng]=new Life(kind_,name_,num,pri);
					leng++;
				}
				cout<<"继续添加请输入1，退出请输入0"<<endl;cin>>conti;
				if(conti==0)
					break;
			}
		}
		else if(choose=="保存")
		{
			bflag=1;
			ofstream desfile("商品资料.txt",ios::out);
			desfile<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(6)<<"数量"<<left<<setw(6)<<"价格"
				<<"其他"<<endl;
			for(i=0;i<leng;i++)
			{
				desfile<<left<<setw(12)<<p[i]->getkind()<<left<<setw(12)<<p[i]->getname()<<left<<setw(6)<<p[i]->getnum()<<left<<setw(6)<<p[i]->getpri();
				if(p[i]->getkind()=="电子数码")
					desfile<<p[i]->getmem()<<" "<<p[i]->getpro()<<" "<<p[i]->getsys()<<endl;
				else if(p[i]->getkind()=="外设")
					desfile<<p[i]->getco()<<" "<<p[i]->getsty()<<endl;
				else if(p[i]->getkind()=="图书")
					desfile<<p[i]->getau()<<endl;
				else if(p[i]->getkind()=="生活用品")
					desfile<<endl;
			}
			desfile.close();
		}
		cout<<"继续操作请输入1，退出请输入0"<<endl;
		cin>>conti;
		if(conti==0)
			break;
		}
		if(bflag==0)
		{
			cout<<"是否保存您操作后的数据(是:1  否:0)：";
			cin>>bflag;
			if(bflag==1)
			{
				ofstream desfile("商品资料.txt",ios::out);
				desfile<<left<<setw(12)<<"种类"<<left<<setw(12)<<"商品"<<left<<setw(6)<<"数量"<<left<<setw(6)<<"价格"
				<<"其他"<<endl;
			for(i=0;i<leng;i++)
			{
				desfile<<left<<setw(12)<<p[i]->getkind()<<left<<setw(12)<<p[i]->getname()<<left<<setw(6)<<p[i]->getnum()<<left<<setw(6)<<p[i]->getpri();
				if(p[i]->getkind()=="电子数码")
					desfile<<p[i]->getmem()<<" "<<p[i]->getpro()<<" "<<p[i]->getsys()<<endl;
				else if(p[i]->getkind()=="外设")
					desfile<<p[i]->getco()<<" "<<p[i]->getsty()<<endl;
				else if(p[i]->getkind()=="图书")
					desfile<<p[i]->getau()<<endl;
				else if(p[i]->getkind()=="生活用品")
					desfile<<endl;
			}
			desfile.close();
			}
		}
	return 0;
}