#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	// int arr[]={1,2,3,4};

	// for(auto i:arr)
	// {
	// 	cout<<i<<" ";
	// }
	// cout<<endl;


	map<string,int>mp;

	mp["apple"]=200;
	mp.insert(make_pair("cherry",100));

	pair<string,int>p=make_pair("orange",400);
	mp.insert(p);


	for(auto m:mp)
	{
		cout<<m.first<<" "<<m.second<<endl;
	}

	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		cout<<itr->first<<" "<<itr->second<<endl;
	}

	map<string,vector<int> >mp2;

	mp2["apple"].push_back(200);
	mp2["apple"].push_back(300);

	for(auto itr=mp2.begin();itr!=mp2.end();itr++)
	{
		cout<<itr->first<<" ";
		for(int i=0;i<itr->second.size();i++)
		{
			cout<<itr->second[i]<<" ";
		}
		cout<<endl;
	}

	for(auto m:mp2)
	{
		cout<<m.first<<" ";
		for(int i=0;i<m.second.size();i++)
		{
			cout<<m.second[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}














