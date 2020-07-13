#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,done=0;
        cin>>n;
        ll a[n], b[n];
        map<long long, int> mpboth;
        for(int i=0 ; i<n ; i++)
        {
            cin>>a[i];
            mpboth[a[i]]++;
        }
        for(int i=0 ; i<n ; i++)
        {
            cin>>b[i];
            mpboth[b[i]]++;
        }
        map<long long, int>::iterator i;
        for(i=mpboth.begin() ; i!=mpboth.end() ; i++)
        {
            if((i->second) % 2 == 1)
            {
                cout<<"-1"<<"\n";
                done = 1;
                break;
            }  
        }
        if(!done)
        {
            sort(a, a+n);
            sort(b, b+n);
            ll minnum = (a[0] > b[0]) ? b[0] : a[0];
            int ifirst = 0;
            int jsec = 0;
            for( ; (ifirst<n && jsec<n) ; )
            {
                if(a[ifirst] == b[jsec])
                {
                    a[ifirst] = -a[ifirst];
                    b[jsec] = -b[jsec];
                    ifirst++;
                    jsec++;
                }
                else if(a[ifirst] > b[jsec])
                {
                    jsec++;
                }
                else
                {
                    ifirst++;
                } 
            }
            /*for(int i=0 ; i<n ; i++)
            cout<<a[i]<<" ";
            cout<<"\n";
            for(int i=0 ; i<n ; i++)
            cout<<b[i]<<" ";
            cout<<"\n";*/
            if(ifirst == n-1 && jsec == n-1)
            {
                cout<<"0"<<"\n";
                continue;           //check 
            }
            ll ans = 0,pairs=0;
            for(int i=0 ; i<n ; i++)
            if(a[i] > 0)
            pairs++;
            ifirst = 0;
            jsec = n-1;
            //cout<<minnum<<"minum\n";
            //cout<<pairs<<"pairs\n";
            while(jsec > 0 && ifirst < n)            //check
            {
                if(a[ifirst] < 0)
                {
                    ifirst++;
                    continue;
                }
                if(b[jsec] < 0)
                {
                    jsec--;
                    continue;
                }
                ans += min( min(a[ifirst], b[jsec]), (2*minnum));
                //cout<<ans<<"<-ans";
                ifirst = ifirst + 2;
                jsec = jsec - 2;
            }
            //ans = (pairs/2)*minnum*2;
            cout<<ans<<"\n";
            
        }
    }
    return 0;
}