#include "knight.h"

int trip[101],mushtype[101],mushrom[101],dmush[101],musx[101];
int a=0,n=0,k=0,n2=0,ii=0,levelx;
float monsterdamge[10]={0,1,1.5,4.5,7.5,9.5};
string fileNames[5];

//input display.........................................................................................
void docevent13()
{
	//<file_mush_ghost>=fileName
	ifstream f(fileNames[0].c_str());
	f>>n2;
	string str; f>>str;
	int post=0,npost=0,k=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==',')
		{
			stringstream ss;
			npost=i;
			string q=str.substr(post,npost-post);
			ss.str(q);
			ss>>mushrom[k];
			k++;
			post=i+1;
		}
		if(i==str.length()-1)
		{
			stringstream ss;
			npost=i+1;
			string q=str.substr(post,npost-post);
			ss.str(q);
			ss>>mushrom[k];
			k++;
		}
		if(k>=n2) break;
	}
	f.close();
}

void xulixau(string s)
{
	int post=0; int npost=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==',')
		{
			npost=i-1;
			fileNames[k]=s.substr(post,npost-post+1);
			k++;
			post=i+1;
		}
		if(i==s.length()-1)
		{
			npost=i;
			fileNames[k]=s.substr(post,npost-post+1);
			k++;
		}
	}
}

void doc(string file_input,int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown)
{
	dmush[-1]=0;
	ifstream f(file_input.c_str());
	f>>HP>>level>>remedy>>maidenkiss>>phoenixdown;
	string s;
	f.ignore();
	f>>s;
	while(s[0]>='0'&&s[0]<='9')
		{
			f.ignore();
			int tmp=s.length();
			if(tmp==1)
			{
				trip[n]=(int)(s[0]-'0');
				n++;
			}
			if(tmp==2)
			{
				trip[n]=(int)(s[0]-'0')*10+(int)(s[1]-'0');
				n++;
			}
			if(tmp>2)
			{
				trip[n]=13;
				n++;
				dmush[ii]=0;
				for(int i=2;i<tmp;i++)
				{
					dmush[ii]++;
					mushtype[a]=(int)(s[i]-'0');
					a++;
				}
				ii++;
			}
			f>>s;
		}
	f>>s;
	xulixau(s);
	f.close();
}
//.......................................................................................................
//output display.........................................................................................
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
//.............................................................................................................
//others function..............................................................................................
bool isprime(int n0)
{
	if(n0<2) return false;
	if(n0==2) return true;
	for(int i=2;i<=n0/2;i++)
	{
		if(n0%i==0) return false;
	}
	return true;
}
int fibonanci(int n0)
{
	int x1=1,x2=1;
	while(x1+x2<n0)
	{
		int tmp=x1+x2;
		x1=x2;
		x2=tmp;
	}	
	return x2;
}
void mountain13(int &mtx,int &mti)
{
	int i=0;
	while(i<n2 && mushrom[i]<mushrom[i+1]) i++;
	mti=i; i++;
	while(i<n2 && mushrom[i]<mushrom[i-1]) i++;
	if(i==n2) mtx=mushrom[mti];
	else{
		mtx=-2;
		mti=-3;
	}
}
//............................................................................................................................................
//event function..............................................................................................................................

//3 sukien combat.............................................................................................................................
int event1to5(int HP,int &phoenixdown,float baseDamage,int &level,int i)
{
	int b = i%10;
	int levelo = i > 6?(b > 5?b : 5) : b;	
	if(level>levelo)
	{
		if(level<10) level++;
	}
	if(level<levelo)
	{
		float damage = baseDamage * levelo * 10;
		HP = HP - damage;
	}
	return HP;
}
int event6(int HP,int &remedy,int &level,int i,int &small)
{
	int b = i%10;
	int levelo = i > 6?(b > 5?b : 5) : b;
	
	if(level==levelo) return HP;
	
	if(level>levelo)  
	{
		level=min(level+2,10);
		return HP;
	}
	if(remedy>0) 
	{
		remedy--;
		return HP;
	}
	if(HP<5) HP=1;
	else HP=HP/5;
	small=1;
	return HP;
}
int event7(int &maidenkiss,int level,int i,int &frog)
{
	int b = i%10;
	int levelo = i > 6?(b > 5?b : 5) : b;
	if(level==levelo) return level;
	if(level>levelo)
	{
		level=min(level+2,10);
		return level;
	}
	if(maidenkiss>0)
	{
		maidenkiss--;
		return level;
	}
	levelx=level;
	level=1;
	frog=1;
	return level;
}
//................................................................................................................................
int event11(int HP,int level,int phoenixdown)
{
	int n1 = ((level + phoenixdown)%5 + 1) * 3;
	int k=99,s1=0;
	for(int i=1;i<=n1;i++)
	{
		s1+=k;
		k-=2;
	}
	HP = HP + (s1%100);
	while(1)
	{
		HP++;
		if(isprime(HP)&&(HP<=999)) return HP;
		if(HP>999) {HP=999;return HP;} 
	}
}
int event12(int HP)
{
	if(HP>1) return fibonanci(HP);
	else return HP;
}
//.................................................................................................................................
int event15(int remedy)
{
	if(remedy<0) remedy=0;
	return min(remedy+1,99);
}
int event16(int maidenkiss)
{
	if(maidenkiss<0) maidenkiss=0;
	return min(maidenkiss+1,99);
}
int event17(int phoenixdown)
{
	if(phoenixdown<0) phoenixdown=0;
	return min(phoenixdown+1,99);
}
//..................................................................................................................................
void event19(string fileName,int &phoenixdown,int &remedy,int &maidenkiss)
{
	int r1,c1;
	ifstream f(fileName.c_str());
	f>>r1>>c1;
	for(int i=1;i<=r1;i++)
	{
		int p=0,a;
		for(int j=1;j<=c1;j++)
		{
			f>>a;
			if(a==16 && p<3)
			{
				remedy++;
				if(remedy>99) remedy=99;
				p++;
			}
			if(a==17 && p<3)
			{
				maidenkiss++;
				if(maidenkiss>99) maidenkiss=99;
				p++;
			}
			if(a==18 && p<3)
			{
				phoenixdown++;
				if(phoenixdown>99) phoenixdown=99;
				p++;
			}
		}
	}
	f.close();
}
int event18(string fileName,int HP)
{
	ifstream f(fileName.c_str());
	int n9;
	string s;
	int ddi[256];
	f>>n9;
	for(int i=0;i<n9;i++)
	{
		bool ck=false;
		string s1="Merlin",s2="merlin",s3;
		f>>s;
		for(int i='A';i<='z';i++) ddi[i]=0;
		for(int i=0;i<s.length();i++)
		{
			ddi[s[i]]++;
			s3=s.substr(i,6);
			if(s3==s1||s3==s2) 
			{
				HP+=3;
				ck=true;
				break;
			}
		}
		if((ddi['M']!=0||ddi['m']!=0)&&ck==false)
			if(ddi['E']!=0||ddi['e']!=0)
				if(ddi['R']!=0||ddi['r']!=0)
					if(ddi['L']!=0||ddi['l']!=0)
						if(ddi['I']!=0||ddi['i']!=0)
							if(ddi['N']!=0||ddi['n']!=0)
							{
								HP+=2;
							}
	}
	return min(HP,999);
	f.close();
}
//..................................................................................................................................
//event13 mushrom

int event13(int j, int HP)
{
    docevent13();
    int must[101];
    int maxi = 0, mini = 0;
    int gtln = mushrom[0], gtnn = mushrom[0];

    switch (j)
    {
        case 1:
        {
            for (int i = 0; i < n2; i++)
            {
                if (gtln <= mushrom[i])
                {
                    gtln = mushrom[i];
                    maxi = i;
                }
                if (gtnn >= mushrom[i])
                {
                    gtnn = mushrom[i];
                    mini = i;
                }
            }
            return HP - (maxi + mini);
        }
        case 2:
        {
            int mtx, mti;
            mountain13(mtx, mti);
            return HP - (mtx + mti);
        }
        case 3:
        {
            for (int i = 0; i < n2; i++)
            {
                must[i] = abs(mushrom[i]);
                must[i] = (17 * must[i] + 9) % 257;
            }
            gtln = must[0], gtnn = must[0];
            for (int i = 0; i < n2; i++)
            {
                if (gtln < must[i])
                {
                    gtln = must[i];
                    maxi = i;
                }
                if (gtnn > must[i])
                {
                    gtnn = must[i];
                    mini = i;
                }
            }
            return HP - (maxi + mini);
        }
        case 4:
        {
            for (int i = 0; i < n2; i++)
            {
                must[i] = abs(mushrom[i]);
                must[i] = (17 * must[i] + 9) % 257;
            }
            gtln = must[0], gtnn = must[0];

            for (int i = 0; i < min(n2, 3); i++)
            {
                gtln = max(gtln, must[i]);
            }

            int gtln2 = -1;
            int gti2 = -1;
            for (int i = 0; i < min(n2, 3); i++)
            {
                if (gtln2 < must[i] && must[i] < gtln)
                {
                    gtln2 = must[i];
                    gti2 = i;
                }
            }
            if (gtln2 == -1 && gti2 == -1)
            {
                gtln2 = -5;
                gti2 = -7;
            }
            return HP - (gtln2 + gti2);
        }
        default:
            return 0;
    }
}

//main function
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) 
{
	rescue=-1;
	
	int tmux=0,frog=0,small=0,ix=0,role=2,merlin=0,asclepius=0,maxHP;
	
	doc(file_input,HP,level,remedy,maidenkiss,phoenixdown);
	
	
	if(isprime(HP)) role=2;
	else role=3;
	if(HP==999) role=1;
	maxHP=HP;
	for(int i=0;i<n;i++)
	{
		if(trip[i]==0)
		{
			rescue=1;
			display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
			break;
		}
		//....................................................................................................................................
		if(role==1)
		{
			if(trip[i]>=1&&trip[i]<=5)  level=min(level+1,10);
			if(trip[i]>=6&&trip[i]<=7)  level=min(level+2,10);
			if(trip[i]==99) level=10;
		}
		else if(role==2)
		{
			if(trip[i]>=1&&trip[i]<=5)  level=min(1+level,10);
			if(trip[i]>=6&&trip[i]<=7)  level=min(2+level,10);
			if(trip[i]==99)
			{
				if(level<8)
				{
					rescue=0;
					display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
					break;
				}
				else level=10;
			}
		}
		else if(role==3)
		{
			switch(trip[i])
			{
				case 1 :
					HP=event1to5(HP,phoenixdown,monsterdamge[1],level,i+1);
					break;
				case 2 :
					HP=event1to5(HP,phoenixdown,monsterdamge[2],level,i+1);
					break;
				case 3 :
					HP=event1to5(HP,phoenixdown,monsterdamge[3],level,i+1);
					break;
				case 4 :
					HP=event1to5(HP,phoenixdown,monsterdamge[4],level,i+1);
					break;
				case 5 :
					HP=event1to5(HP,phoenixdown,monsterdamge[5],level,i+1);
					break;
				default : break;
			}
			if(small>0) small++;
			if(frog>0) frog++;
			if(small==0&&frog==0)
			{
				if(trip[i]==6) HP=event6(HP,remedy,level,i+1,small);
				if(trip[i]==7) level=event7(maidenkiss,level,i+1,frog);
			}
			if(trip[i]==99)
			{
				if(level<10)
				{
					rescue=0;
					display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
					break;
				}
				else level=10;
			}
		}
		//.......................................................................................................................................
		if(trip[i]==13)
		{
			while(dmush[ix]--)
			{
				HP=event13(mushtype[tmux],HP);
				tmux++;
				HP=min(HP,maxHP);
				if(HP<=0&&phoenixdown>0)
				{
					phoenixdown--;
					HP=maxHP;
				}
				if(HP<=0&&phoenixdown<=0)
				{
					rescue=0;
					break;
				}
			}
			ix++;
		}
		//.........................................................................................................................................
		if(trip[i]==11)
		{
			HP=event11(HP,level,phoenixdown);
			HP=min(HP,maxHP);
		}
		if(trip[i]==12) HP=event12(HP);
		if(trip[i]==15) 
		{
			remedy=event15(remedy);
			if(small>0)
			{
				remedy--;
				HP=HP*5;
				small=0;
			}
			HP=min(HP,maxHP);
		}
		if(trip[i]==16)
		{
			maidenkiss=event16(maidenkiss);
			if(frog>0)
			{
				maidenkiss--;
				level=levelx;
				frog=0;
			}
		}
		if(trip[i]==17) phoenixdown=event17(phoenixdown);
		if(trip[i]==18&&merlin==0)
		{
			HP=event18(fileNames[2],HP);
			merlin=1;
		}
		if(trip[i]==19&&asclepius==0) 
		{
			event19(fileNames[1],phoenixdown,remedy,maidenkiss);
			asclepius=1;
		}
		//......................................................................................................................................
		if(HP<=0)
		{
			if(phoenixdown>0)
			{
				phoenixdown--;
				HP=maxHP;
			}
			else
			{
				rescue=0;
				display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
				break;
			}
		}
		if(small>3) HP=HP*5;
		if(frog>3) level=levelx;
		
		if(HP>maxHP) HP=maxHP;
		if(i==n-1) rescue=1;
		//.......................................................................................................................................
		display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
		}
}
