    #include<bits/stdc++.h>
    using namespace std;

    struct Generator {
        Generator() : m_value( 1 ) { }
        int operator()() { return m_value++; }
        int m_value;
    };

    int main()
    {
        int t;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            int n;
            cin>>n;
            int k=n;
            vector<int> vec;
            generate(vec.begin(),vec.end(),Generator());
            vector<int>::iterator itr=vec.begin();
            for(int j=0;j<n;j++)
                vec.push_back(k--);

            //iota(vec.begin(),vec.end(),1);
            int start=0;
            for(int j=0;j<n;j++)
            {
                int index_s=start;
                do
                {
                    cout<<vec[index_s]<<" ";
                    index_s=((index_s+1)%n);
                }while(index_s!=start);
                cout<<"\n";
                    if(!start)
                        start=n-1;
                    else
                        start--;
            }
            vec.clear();
        }
        return 0;
    }
