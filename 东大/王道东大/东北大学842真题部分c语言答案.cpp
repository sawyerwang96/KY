#include <iostream>
#include<stdio.h>
using namespace std;
#define MAX 50
/*�����Ĵ�����ѭ��ʽ������ָ������*/
/*�ļ������ǹر�*/
//2011c���Բ���
void fun1()
{
    struct num
    {
        int x,y;
    }a[]={{2,32},{8,16},(4,48)};
    struct num*p=a+1;
    cout<<p->y/a[0].x*++p->x<<endl;
}
int search(int*a,int n,int x)
{
    int i=0;
    while(i<n&&*(a+i++)!=x)
		;
    if(i<n)
		return i;
    else return -1;
}
void fun2()
{
    int i,a[]={34,67,13,778,443,53,2,56};
    for(i=0;i<5;i++)
    {
        if(search(a+i,5,i)>=0)
            cout<<i<<endl;
    }
}
int doc(int a[],int n)
{
	if(n<=1)return 1;
	if(a[0]<a[1])return 0;
	else return doc(a+1,n-1);
}
void fun5()
{
	int a[5]={5,4,3,2,1};
	cout<<doc(a,5)<<endl;
}
void fun3()
{
	union
	{
		char s[2];
		int i;
	}a;
	a.i=0x1234;
	printf("%x,%x\n",a.s[0],a.s[1]);
}
void showfile(char *p)
{
	FILE *fp;
	if(NULL==(fp=fopen(p,"r")))
	{
		printf("%s���ܴ򿪣�\n",p);
		exit(0);
	}
	char ch;
	int i=0;
	while((ch=getc(fp))!=EOF)
	{
		putchar(ch);
		i++;
		if(i>=30)
		{
			i=0;
			printf("\n");
		}
	}
	printf("\n");
	fclose(fp);
}
//��str1�ĵ�i��j���ַ��滻Ϊstr2
char* stuff(char*str1,char*str2,int i ,int j)
{
	if(i<=0||j<=0||i>j)return NULL;
	int len1,len2,k,m;
	len1=strlen(str1);
	len2=strlen(str2);
	char*temp=(char*)malloc(len1+len2+1);
	for(k=0,m=0;k<i-1;k++)
		temp[m++]=str1[k];
	for(k=0;str2[k]!='\0';k++)
		temp[m++]=str2[k];
	for(k=j;str1[k]!='\0';k++)
		temp[m++]=str1[k];
	temp[m]='\0';
	return temp;
}
//�������⣨�ԣ�


//2007
int f(int *a)
{
	return (*a)++;
}
void fun071()
{
	int a=2,s=0;
	{
		int a=5;
		s+=f(&a);
	}
	s+=f(&a);
	printf("%d\n",s);
}
void f2(int y,int*x)
{
	y=y+*x;
	*x=*x+y;
}
void fun072()
{
	int x=2,y=4;
	f2(y,&x);
	cout<<x<<" "<<y<<endl;
}
void fun074()
{
	char*p[2][3]={"Hello","world","student","computer","end","the"};
	printf("%c\n",***(p+1));
	printf("%c\n",**p[0]);
	printf("%c\n",(*(*(p+1)+1))[2]);
	printf("%c\n",*(p[1][2]+1));
	printf("%c\n",*(*(p+1)+0));//���
	
}
void setmemory(char**p,int num)
{
	*p=(char*)malloc(num);
}
void fun0722()
{
	char *str;
	setmemory(&str,100);
	strcpy(str,"hello");
	printf("%s",str);
}
//2013���
//�ַ�������
void sortstr(char str[][100],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[j],str[min])<0)
			{
				min=j;
			}
		}
		if(min!=i)
		{
			char temp[100];
			strcpy(temp,str[min]);
			strcpy(str[min],str[i]);
			strcpy(str[i],temp);
		}
	}
}
//���ļ��е�������ת��
void sortfile(char*p ,char*q)
{
	FILE *fp,*fq;
	if(NULL==(fp=fopen(p,"r")))
	{
		printf("%s ���ܴ�!\n",p);
		exit(0);
	}
	if(NULL==(fq=fopen(q,"w")))
	{
		printf("%s ���ܴ�!\n",q);
		exit(0);
	}
	char ch,str[50][100];
	int flag=0,i=0,j=0;
	while(EOF!=(ch=getc(fp)))
	{
		if(ch!=' ')
		{
			flag=1;				//��ʾ�����ǵ���ʱ��
			str[i][j++]=ch;
		}
		else
		{
			if(flag)
			{
				str[i++][j]='\0';
				flag=0;
				j=0;
			}
		}
	}
	if(flag==1)//���һ������
	{
		str[i++][j]='\0';
		flag=0;
		j=0;
	}
	sortstr(str,i);				//��i����������
	for(j=0;j<i;j++)
	{
		fprintf(fq,"%s ",str[j]);
		printf("%s ",str[j]);
	}
	printf("\n");
	fclose(fp);
	fclose(fq);
}
//2006
void f061(int i,char(*p)[4])
{
	for(;i;i--)
		printf("%s",p++);
}
void fun061()
{
	char a[][4]={"abc","ABC","DE"};
	char (*p)[4];
	p=a;
	f061(2,p++);
	f061(1,p++);
	printf("\n");
}
void f062(char*p1,char*p2)
{
	while(*p2++);
	p2--;
	while(*p2++=*p1++);
}
void fun062()
{
	char a[30]="I am a teacher.";
	char b[30]="OK.";
	f062(a,b);
	printf("%s %s\n",a,b);
}
void fun063()
{
	int a[10]={0,56,34,0,7,45,0,43,9,13},x,n=1;
	while(n)
	{
		if((x=a[n])&&n++)
		{
			printf("%d",x);
		}
		else
			printf("%d",-1);
	}
}
void fun064()
{
	struct num
	{
		int x,y;
	}a[]={{2,32},{16,8},{18,48}};
	struct num* ptr=a+1;
	int x;
	x=(ptr->y/a[0].x)*(++ptr->x);
	printf("x=%d ptr->x=%d\n",x,ptr->x);
}
//�鿴ǰn���ַ����Ƿ�����
void issort(int n)
{
	char str[50][100];
	int i,j,flag=1;
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	for(j=0;j<n-1;j++)
	{
		if(strcmp(str[j],str[j+1])>0)
		{
			flag=0;break;
		}
	}
	if(flag)printf("YES!\n");
	else printf("NO!\n");
}
//���ļ��в���ĳ������ļ������ڣ������ļ���д�롣����ļ������������ڣ���д��
void search()
{
	puts("input a num");
	int num;
	scanf("%d",&num);
	FILE *fp;
	char *p="D:\\test\\a.txt";
	if(NULL==(fp=fopen(p,"r+")))				//w+��r+��������w+��д�������ٶ��������д�޷�������r+���ȶ���д
	{
		printf("%s �����ڣ�������д��!\n",p);	//���ؿ����ļ������ڴ�ʱֱ��д�룬����
		fp=fopen(p,"w");
		fprintf(fp," %d ",num);					//д��ʱ��ǰ�����һ���ո�
		fclose(fp);
		return;
	}
	int temp;
	while(EOF!=(fscanf(fp,"%d",&temp)))
	{
		if(temp==num)
		{
			printf("%d is found\n",num);
			fclose(fp);
			return;
		}
	}
	fprintf(fp," %d ",num);						//����ʱǰ�����һ���ո���д�뱣��һ��
	fclose(fp);
}
//2005
void fun051()
{
	char*s="121";
	int k=0,a=0,b=0;
	do{
		k++;
		if(k%2==0)
		{
			a=a+s[k]-'0';
			continue;
		}
		b=b+s[k]-'0';
		a=a+s[k]-'0';
	}while(s[k+1]);
	printf("k=%d,a=%d,b=%d",k,a,b);
}
void fun057()
{
	static char a[]="language",b[]="program";
	char *p=a,*q=b;
	for(int k=0;k<7;k++)
	{
		if(*(p+k)==*(q+k))
			printf("%c",*(p+k));
	}
}
void fun058()
{
	struct st
	{
		int n;
		struct st *next;
	};
	static struct st a[3]={5,&a[1],7,&a[2],9,NULL},*p=&a[0];
	int x=++p->n;
	printf("%d\n",x);
}
void fun059()//�ļ�����
{
	FILE *in,*out;
	char infile[30],outfile[30];
	scanf("%s",infile);
	scanf("%s",outfile);
	if(NULL==(in=fopen(infile,"r")))
	{
		exit(0);
	}
	if(NULL==(out=fopen(outfile,"w")))
	{
		exit(0);
	}
	while(!feof(in))
	{
		fputc(getc(in),out);
	}
	fclose(in);
	fclose(out);
}
f0510(int n)
{
	if(n>0)
		return (n*f0510(n-2));
	else return 1;
}
void fun0510()
{
	int x=f0510(5);
	printf("%d\n",x);
}
//05��̷�����
void showres()
{
	int i,j,k,m,count=0;
	char str[15],res[15];
	for(i=1;i<=2050;i++)
	{
		j=i;k=0;
		while(j>0)
		{
			res[k++]=(1&j)+'0';			//&�������ȼ�����+�ʼӣ���
			j>>=1;
		}
		res[k]='\0';
		
		for(j=k-1,m=0;j>=0;j--,m++)		//res�д���ַ����������ڴ���ַ����෴
		{
			str[m]=res[j];				//���򿽱���str��
		}
		str[m]='\0';
		if(strcmp(str,res)==0)
		{
			printf("%d=%s �Ƿ�����\n",i,str);
			count++;
		}
		
	}
	printf("%d��\n",count);
}
//ɾ���ַ���
void delstring(char *str1,char *str2)
{
	int i,j,m,k;
	int len1,len2;
	puts(str1);
	puts(str2);
	for(i=0;str1[i]!='\0';i++);
	for(j=0;str2[j]!='\0';j++);
	len1=i,len2=j;m=0;				//mΪƫ����
	for(i=0;i<len1;)
	{
		for(k=i,j=0;str1[k]&&str2[j]&&(str1[k]==str2[j]);k++,j++);
		if(str2[j]!='\0')			//������ѵ�i���ַ�ƫ��
		{
			str1[i-m]=str1[i];
			i=i+1;
		}
		else						//������޸�ƫ����
		{
			i=i+len2;
			m+=len2;
			
		}
	}
	str1[len1-m]='\0';				//�����ӽ�����־
	puts(str1);
}
//��Ʊ��ֵ����
void poster(int m,int n)
{
	int i,value;
	if(m>0&&n>0)
	{
		puts("����Ϊ��");
		for(i=0;i<n-1;i++)	//ǰn-1����ֵΪi*m+1,���һ����ǰһ����1
		{
			value=i*m+1;
			printf("%d ",value);
		}
		printf("%d\n",value+1);
		puts("�����ֵΪ��");
		printf("%d\n",(value+1)*m);
	}
}
//04��c����
int f041(int *x,int y)
{
	if(*x<y)*x+=y;
	else y+=*x;
	return (*x+y);
}
void fun041()
{
	int a[3]={5,3,8},*p=a;
	*p=f041(&a[1],a[2]);
	*p+=f041(&a[1],a[2]);
	printf("%d %d %d \n",a[0],a[1],a[2]);
}
//��f1�ļ�׷�ӵ�f2��
void add(char *p,char *q)
{
	FILE *fp,*fq;
	if(NULL==(fp=fopen(p,"r")))
	{
		printf("%s ���ܴ�\n",p);
		exit(0);
	}
	if(NULL==(fq=fopen(q,"a+")))
	{
		printf("%s���ܴ�\n",q);
		exit(0);
	}
	int c;
	c=fseek(fq,0L,2);
	while(EOF!=(c=fgetc(fp)))fputc(c,fq);
	fclose(fp);
	fclose(fq);
}
void fun043()
{
	int a[10],*p;
	for(p=a;p<(a+10);p++)
	{
		scanf("%d",p);
	}
	for(p=a;p<(a+10);p++)
	{
		printf("%d",*p);
	}
}
void fun044()
{
	int i=9,j=0;
	char str[3]="*#",ch=str[0];
	do{
		printf("%c",ch);
		if(i%5==0)j++;
	}
	while((ch=str[j])||i--);
}
void fun046()
{
	char str[5][20]={"follow me","BASIC","Great Wall","FORTRAN","Computer Design"};
	char (*name)[20];
	int i;
	name=str;
	for(i=0;i<5;i++,name++)
		name=str+i;
	name=str;
	for(i=0;i<5;i++,name++)
	{
		if(strchr((char*)name,' '))
			puts((char*)name);
	}
}
//04���
int  checkChar(char p[])
{
	puts(p);
	char stack[100],ch;
	int top=-1,i=0;
	while(p[i]!='\0')
	{
		switch(p[i])
		{
		case '{':stack[++top]='{';break;
		case '[':stack[++top]='[';break;
		case '(':stack[++top]='(';break;
		case '}':ch=stack[top--];if(ch!='{')return false;break;
		case ']':ch=stack[top--];if(ch!='[')return false;break;
		case ')':ch=stack[top--];if(ch!='(')return false;break;
		default:break;
		}
		i++;
	}
	if(top>-1)return false;
	else return true;
}
//ɾ���ظ��������������������λ��
void delAndPut(int n)
{
	printf("input %d num",n);
	int arr[100];
	int i,j,k,m;	//m��ǰ�������ظ�
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	puts("\nall num is:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	for(i=0,m=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[j]==arr[i])break;
		}
		if(j==m)arr[m++]=arr[i];	
	}
	puts("\nafter del is:");
	for(i=0;i<m;i++)
		printf("%d ",arr[i]);
	puts("\nposition is");
	for(i=0;i<m;i++)
	{
		k=0;
		for(j=0;j<m;j++)
		{
			if(arr[j]<=arr[i])k++;				
		}
		printf("%d ",k);
	}
}
//һ������һ����������ϲ�Ϊ����
typedef struct Node
{
	int data;
	struct Node*next;
}Node,*Linklist;
Linklist creatList()
{
	int num;
	Linklist head=(Linklist)malloc(sizeof(Node));
	head->next=NULL;
	Node *p,*r=head;
	scanf("%d",&num);
	while(num!=-1)
	{
		p=(Node*)malloc(sizeof(Node));
		p->data=num;
		p->next=r->next;
		r->next=p;
		r=p;
		scanf("%d",&num);
	}
	return head;
}
void sortList(Linklist la)
{
	puts("\npre sort is");
	Node*p=la,*q,*min;
	while(p->next)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	p=la->next;
	while(p)
	{
		min=p;
		q=p->next;
		while(q)
		{
			if(q->data<min->data)min=q;
			q=q->next;
		}
		if(p!=q)
		{
			int temp=p->data;
			p->data=min->data;
			min->data=temp;
		}
		p=p->next;
	}
	puts("\nafter sort is");
	p=la;
	while(p->next)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
}
void Merge(Linklist la,Linklist lb)
{
	//����la����,�ϲ�Ϊ����
	Node *p,*q,*head;
	p=la->next,q=lb->next;
	puts("\nla is");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	puts("\nlb is ");
	while(q)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	head=lb->next;
	while(head)
	{
		q=head;
		head=head->next;
		p=la;
		while(p->next&&p->next->data <q->data)p=p->next;
		q->next=p->next;
		p->next=q;
	}
	puts("\n la+lb is");
	p=la->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
//2000��1��1��Ϊ����������������������1��1�����ܼ�
void computeDate(int n)
{
	int y,day;
	if(n>2000)
	{
		y=n-2000;
		day=(6+(y+1+(y-1)/4-(y-1)/100+(y-1)/400))%7;
		if(day==0)day=7;
		printf("%d ��1��1��������%d\n",n,day);
	}
	else
	{
		y=2000-n;
		day=6-(y+(y/4)-(y/100)+y/400)%7;
		if(day==0)day=7;
		printf("%d ��1��1��������%d\n",n,day);
	}
}
//������д
int arr[MAX][MAX]={0};
int visited[MAX]={0};
int total=0;
int isequal(int n)
{
	int i,j,num=0,sum=0;
	for(i=0;i<n;i++)num+=arr[0][i];
	for(i=1;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=arr[i][j];
		}
		if(sum!=num)return 0;
	}
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=arr[j][i];
		}
		if(sum!=num)return 0;
	}
	return 1;
}

void Find(int i,int j,int v,int num,int n)
{
	int w,k,count=0;
	int nextv[MAX]={0};
	if(i<n&&j<n&&v<num&&visited[v]==0)
	{
		arr[i][j]=v;
		visited[v]=1;
		for(k=0;k<num;k++)
		{
			//v��Ҫ̽������������
			if(visited[k]==0)nextv[count++]=k;
		}
		if(i==n-1&&j==n-1)
		{
			if(isequal(n))
			{
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%d ",arr[i][j]);
					}
					printf("\n");
				}
				puts("");
				total++;
			}
			//getchar();
			return;
		}
		//��һ��λ��
		if(j<n-1)j++;
		else 
		{
			j=0;i++;
		}
		//��һ����
		k=0;
		while(k<count)
		{
			Find(i,j,nextv[k],num,n);
			k++;
		}
		visited[v]=0;
		for(k=0;k<count;k++)visited[nextv[k]]=0;
	}
}
void Fill(int num,int n)
{
	int i,j;
	if(num<n*n)return;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
			visited[j]=0;
		if(visited[i]==0)
			Find(0,0,i,num,n);
	}
	printf("\ntotal is %d\n",total);
}
int main()
{
    //cout << "Hello world!" << endl;
    //fun1();
    //fun2();
    //fun3();
	//fun5();
	//showfile("D:\\test\\1.txt");
	//char str1[10]="china is";
	//char str2[20]="12 3445466 7 5867";
	//puts(stuff(str1,str2,4,4));
	//fun071();//7
	//fun072();//8  4
	//fun074();//c  H   d  h  ���
	//fun0722();
	//char *p="D:\\test\\word.txt",*q="D:\\test\\wordsorted.txt";
	//sortfile(p,q);
	//fun061();
	//fun062();
	//fun063();
	//fun064();
	//issort(5);
	//search();
	//fun057();
	//fun051();
	//fun058();
	//fun0510();
	//showres();
	//char str1[]="abacabcab",str2[]="bc";
	//delstring(str1,str2);
	//poster(3,4);
	//fun041();
	//char *p="D:\\test\\addtest.txt",*q="D:\\test\\addtested.txt";
	//add(p,q);
	//fun043();
	//fun044();
	//fun046();
	//char str[20]={"(){{[]}}"};
	//if(checkChar(str))puts("YES");
	//else puts("NO");
	//delAndPut(9);
	//Linklist la=creatList(),lb=creatList(),p;
	//sortList(la);
	//Merge(la,lb);//�ββ���Ҫ����������
	//p=la->next;
	Fill(10,3);
	//computeDate(1900);
    return 0;
}
