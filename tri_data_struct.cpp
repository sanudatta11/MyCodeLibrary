#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

struct trienode{
map<char,trienode*> mymap;
bool isend;
};

bool insert_tri(trienode *root,char *word)
{
    if(!root)
        return false;
    if(!*(word+1))
    {
      //  cout<<"End"<<*word<<endl;
        root->isend = true;
        if(root->mymap.find(*word)==root->mymap.end())
            root->mymap[*word] = new trienode;
        return true;
    }
    else{
        if(root->mymap.find(*word)==root->mymap.end()){
            trienode *ptr = new trienode;
            root->mymap.insert(make_pair(*word,ptr));
            //cout<<"Data dump="<<*word<<"----"<<root->mymap[*word]<<endl;
            root->isend = false;
        }
        insert_tri(root->mymap[*word],(word+1));
        return true;
    }
}

int search_tri(trienode *root,char *word)
{
    if(!root || !*word)
        return false;
    if(root->mymap.find(*word)!=root->mymap.end())
    {
    //cout<<"here="<<*word<<"Addr="<<root->mymap[*word]<<endl;
        if(!*(word+1) && root->isend)
        {
            return true;
        }else if(!(*(word+1)))
        {
            return false;
        }else{
            return search_tri(root->mymap[*word],word+1);
        }
    }
    else
      return false;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    trienode *root = new trienode;
    root->isend = false;

  /*  char ch1[]="abcabc";
    char ch2[]="abc";
    char ch3[]="cde";
    char ch4[]="abcdef";

    char ch5[]="blabla";
    char ch6[]="abcd";*/
    char *ch1 = new char[20];
    strcpy(ch1,"abcabc");
    char *ch2 = new char[20];
    strcpy(ch2,"abc");
    char *ch3 = new char[20];
    strcpy(ch3,"cde");
    char *ch4 = new char[20];
    strcpy(ch4,"abcdef");

    char *ch5 = new char[20];
    strcpy(ch5,"blabla");
    char *ch6 = new char[20];
    strcpy(ch6,"abcd");

    insert_tri(root,ch1);
    insert_tri(root,ch2);
    insert_tri(root,ch3);
    insert_tri(root,ch4);

    bool ans1 = search_tri(root,ch6);
    cout<<"Ans 1="<<ans1<<endl;
    bool ans2 = search_tri(root,ch5);
    cout<<"Ans 2="<<ans2<<endl;
    bool ans3 = search_tri(root,ch4);
    cout<<"Ans 3 ="<<ans3<<endl;

    delete root;
    delete ch1;
    delete ch2;
    delete ch3;
    delete ch4;
    delete ch5;
    delete ch6;
    return 0;
}
