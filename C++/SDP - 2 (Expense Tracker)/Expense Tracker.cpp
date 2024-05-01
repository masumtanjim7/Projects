#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<stdio.h>
#include<windows.h>
using namespace std;
float spend;
float bud;
float lmoney;
time_t now = time(0);
static char* dt = ctime(&now);
int l = strlen(dt);
void newf();
float income();
void intro();
void review();
void next();
bool flag=0;
inline void back()
{
    cout<<"\nPress b to back";
    char ch=getch();
    if(ch=='b'||ch=='B')
        intro();
}
class expense
{
public:
    float ifood(float a);
    float icloth(float a);
    float iliving(float a);
    float itrans(float a);
    float ieduc(float a);
    float imed(float a);
} e;

float cloth()
{
    float b,c=0;
    FILE *fp=fopen("Cloth.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float med()
{
    float b,c=0;
    FILE *fp=fopen("Medical.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float trans()
{
    float b,c=0;
    FILE *fp=fopen("Transport.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float food()
{
    float b,c=0;
    FILE *fp=fopen("Food.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float educ()
{
    float b,c=0;
    FILE *fp=fopen("Education.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float liv()
{
    float b,c=0;
    FILE *fp=fopen("Living.txt","r");
    if(fp==NULL)
        return c;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    return c;
}
float expense::icloth(float a)
{
    float b;
    system("CLS");
    cout<<"\n\t\t\tIN CLOTH\n";
    cout<<"Transaction Time\n";
    fstream data("Cloth1.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Cloth1.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Cloth.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Cloth.txt","r");
    float c=0;
    char *k;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"Total\t\t\t  "<<c;
    fclose(fp);
    FILE *kp;
    kp=fopen("Bidget Remains.txt","w");
    fprintf(kp,"%f ", lmoney);
    fclose(kp);
    back();
    return c;
}
float expense::itrans(float a)
{
    float b;
    system("CLS");
    cout<<"\n\t\t\tIN TRANSPORTATION\n";
    cout<<"Transaction Time\n";
    fstream data("Transport1.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Transport1.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Transport.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Transport.txt","r");
    float c=0;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"Total\t\t\t   "<<c;
    fclose(fp);
    FILE *k;
    k=fopen("Bidget.txt","w");
    fprintf(k,"%f ", lmoney);
    fclose(k);
    back();
    return c;
}
float expense::ifood(float a)
{
    float b;
    system("CLS");
    cout<<"\n\t\t\tIN FOOD\n";
    cout<<"Transaction Time\n";
    cout<<"Previous data  \n";
    fstream data("Food1.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Food1.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Food.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Food.txt","r");
    float c=0;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"total\t\t\t  "<<c;
    fclose(fp);
    FILE *kp;
    kp=fopen("Bidget.txt","w");
    fprintf(kp,"%f ", lmoney);
    fclose(kp);;
    back();
    return c;
}
float expense::ieduc(float a)
{
    float b;
    system("CLS");
    cout<<"\t\t\tIN EDUCATION\n";
    cout<<"Transaction Time\n";
    fstream data("Education1.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Education1.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Education.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Education.txt","r");
    float c=0;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"Total\t\t\t  "<<c;
    fclose(fp);
    FILE *kp;
    kp=fopen("Bidget.txt","w");
    fprintf(kp,"%f ", lmoney);
    fclose(kp);;
    back();
    return c;
}
float expense::imed(float a)
{
    float b;
    system("CLS");
    cout<<"\t\t\tIN MEDICAL\n";
    cout<<"Transaction Time\t\t Money Left\n"<<lmoney;
    fstream data("Medical1.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Medical1.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Medical.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Medical.txt","r");
    float c=0;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"Total\t\t\t  "<<c;
    fclose(fp);
    FILE *kp;
    kp=fopen("Bidget.txt","w");
    fprintf(kp,"%f ", lmoney);
    fclose(kp);;
    back();
    return c;
}
float expense::iliving(float a)
{
    float b;
    system("CLS");
    cout<<"\t\t\tIN Living\n";
    cout<<"Transaction Time\t\t Money left\n"<<lmoney;
    fstream data("Living.txt",ios::in|ios::app);
    data<<dt<<"  "<<a<<"\n";
    data.close();
    data.open("Living.txt",ios::in);
    char str[40];
    while(!data.eof())
    {
        data.getline(str,40);
        cout<<str<<endl;
    }
    data.close();
    FILE *fp;
    fp=fopen("Living.txt","a");
    fprintf(fp,"%f ", a);
    fclose(fp);
    fp=fopen("Living.txt","r");
    float c=0;
    while(!feof(fp))
    {
        fscanf(fp,"%f ", &b);
        c=c+b;
    }
    cout<<"Total\t\t\t  "<<c;
    fclose(fp);
    FILE *kp;
    kp=fopen("Bidget.txt","w");
    fprintf(kp,"%f ", lmoney);
    fclose(kp);;
    back();
    return c;
}
int main(void );
void intro()
{
    system("CLS");
    cout<<dt<<endl;
label:
    cout<<"\nMoney spend in\t\t Money left:"<<lmoney;
    cout<<"\n1. Food\n2. Cloth\n3. Living\n4. Tranportion\n5. Education\n6. Medical \n Press b to back";
    char ch=getch();
    switch (ch)
    {
    case '1':
    {
y:
        cout<<"\n Enter the amount:";
        cin>>spend;
        if(spend>lmoney||spend<0)
        {
            cout<<"Wrong Input";
            goto y;
        }
        lmoney-=spend;
        e.ifood(spend);
        break;
    }
    case '2':
    {
        cout<<"\n Enter the amount:";
x:
        cin>>spend;
        if(spend>lmoney||spend<0)
        {
            cout<<"Wrong Input";
            goto x;
        }
        lmoney-=spend;
        e.icloth(spend);
        break;
    }
    case '3':
    {
c:
        cout<<"\n Enter the amount:";
        cin>>spend;
        if(spend>lmoney||spend<0)
        {
            cout<<"Wrong Input";
            goto c;
        }
        lmoney-=spend;
        e.iliving(spend);
        break;
    }
    case'4':{
            d:
        cout<<"\n Enter the amount:";
        cin>>spend;
        if(spend>lmoney||spend<0)
        {
            cout<<"Wrong Input";
            goto d;
        }
        else
        {
            lmoney-=spend;
            e.itrans(spend);
        }
    }
    break;
    case'5':{
        e:
    cout<<"\n Enter the amount:";
    cin>>spend;
    if(spend>lmoney||spend<0)
    {
        cout<<"Wrong Input";
        goto e;
    }
    else
    {
        lmoney-=spend;
        e.ieduc(spend);
    }
    break;
}
    case '6':
{
f:
    cout<<"\n Enter the amount:";
    cin>>spend;
    if(spend>lmoney||spend<0)
    {
        cout<<"Wrong Input";
        goto f;
    }
    lmoney-=spend;
    e.imed(spend);
    break;
}
case 'b':
next();
default :
system("cls");
cout<<"Wrong Key\n";
goto label;
break;
}
}
void review()
{
    system("cls");
    cout<<"\nFood\tCloth\tLiving\tTransportation\tEducation\tMedical\t\tMoney left in Budget\n";
    cout<<food()<<"\t"<<cloth()<<"\t"<<liv()<<"\t"<<trans()<<"\t\t"<<educ()<<"\t\t"<<med()<<"\t\t"<<lmoney<<endl;
    cout<<"\n\nPress b to back";
    char ch=getch();
    if(ch=='b'||ch=='B')
        next();
}
void next()
{
    system("CLS");
xyz:
    cout<<"\n1. Money Review\n2. Spend Amount\n3. Change in Budget\n ";
    char k=getch();
    if(k=='1')
        review();
    else if(k=='2')
        intro();
    else if
    (k=='3')
        income();
    else
        system("cls");
    cout<<"Wrong Key\n";
    goto xyz;
}
float income()
{
label:
    cout<<"\n1. Subtract Money\n2. Add More Money\t\t\t\t Money left: "<<lmoney<<endl;
    int a;
    char ch=getch();
    switch(ch)
    {
case '1':
        {
x:
            cout<<"\nEnter  Amount";
            cin>>a;
            if(a<0)
            {
                cout<<"\nWrong Input";
                goto x;
            }
            else if (a>lmoney)
            {
                cout<<"Your subtracted amount must be less than the budget";
                goto x;
            }
            else
                lmoney-=a;
            break;
        }
case '2':
        {
y:
            cout<<"\nEnter Amount";
            cin>>a;
            if(a<0)
            {
                cout<<"\nWrong Input";
                goto y;
            }
            else
                lmoney=lmoney+a;
            break;
        }
    default :
        system("cls");
        cout<<"Wrong Key\n";
        goto label;
        break;
    }
    cout<<"\nNew Budget :"<<lmoney;
    Sleep(1500);
    FILE *fp;
    fp=fopen("Bidget.txt","w");
    fprintf(fp,"%f ", lmoney);
    fclose(fp);
    next();
}
void newf()
{
    cout<<"\nEnter your Budget:";
    cin>>lmoney;
    FILE *fp;
    fp=fopen("Bidget.txt","w");
    fprintf(fp,"%f ",lmoney);
    fclose(fp);
    next();
}

int main()
{
    system("cls");
    dt[--l]= {' '};
    char title[]="\t\t\t\t*********************\n\t\t\t\t    WELCOME TO\n\t\t\t\t EXPENSE TRACKER APP\n\t\t\t\t*********************";
    char *ptr=&title[0];
    for(int i=0; i<sizeof(title); i++)
    {
        cout << *(ptr+i);
        Sleep(40);
    }
    cout<<"\n\n\t\t\t     Press space bar to continue";
    getch();
    FILE *fp;
    cloth();
    fp=fopen("Bidget.txt","r");
    if (fp==NULL)
        newf();
    while(!feof(fp))
    {
        flag=1;
        fscanf(fp,"%f ", &lmoney);
    }
    fclose(fp);
    next();
    return 0;
}
