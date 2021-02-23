#include<iostream>
using namespace std;


// in ra cac hoan vi cua xau con
void inhoanvi(string s,string a)
{
//s: xau lap vao a
//a: xau duoc lap

	// neu xau s da duoc lap het -> xau a da du ki tu
	if(s==""){
		cout<<a<<endl;
		return;
	}
	string b=s;
	string c=a;
	for(int i=0;i<s.size();i++)
	{
		b=s;
		c=a;
		c+=b[i];
		b.erase(i,1);
		inhoanvi(b,c);
	}
}

// in ra de bai
void layxau(string &s, string a, int k, int dem, int kytu)

//s: xau co n ky tu
//a: xau lay k ki tu cua xau s
//kytu: danh dau chu cai se lay
// dem: dem so ki tu da lay
{
	//in xau neu thoa man de bai
	if(dem==k) {
		inhoanvi(a,"");
		cout<<endl;
		return;
	}
	// lay 1 ki tu danh dau boi kytu
	for(int i=kytu;i<s.size();i++)
	{
		a+=s[i];
		// de quy
		layxau(s,a,k,dem+1,i+1);
		a.erase(dem,1);
	}
}

int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	for(int i=0;i<n;i++){
		s+=char('a'+i);
	}
	int dem=0;
	int kytu=0;
	string a="";
	layxau(s,a,k,dem,kytu);
	return 0;
}
