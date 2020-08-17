#include <bits/stdc++.h>

using namespace std;

int main() {

int n;

string sp;

cin>>n>>sp;

vector<pair<int,int>> checker(n,{INT_MAX,INT_MAX});

for(int ms=0;ms<n;ms++)

{

if(sp[ms]=='A')

{

int t=0;

int j=ms-1;

if(j>=0)

{

for(j;j>=0;j--)

{

if(sp[j]=='-')

{

checker[j].first=min(checker[j].first,t);

}

else if(sp[j]=='A'||sp[j]=='B')

{

break;

}

++t;

}

}

}

else if(sp[ms]=='B')

{

int t=0;

int j=ms+1;

if(j<n)

{

for(j;j<n;j++)

{

if(sp[j]=='-')

{

checker[j].second = min(checker[j].second,t);

}

else if(sp[j]=='B'||sp[j]=='A')

{

break;

}

t++;

}

}

}

}

int a_count=0;

int b_count=0;

for(int mt=0;mt<n;mt++)

{

int x = checker[mt].first;

int y = checker[mt].second;

if(sp[mt]=='A')

{

a_count++;

}

else if(sp[mt]=='B')

{

b_count++;

}

if(sp[mt]=='-')

{

if(x>y)

{

b_count++;

}

else if(x<y)

{

a_count++;

}

}

}

if(a_count>b_count)

{

cout<<"A";

}

else if(b_count>a_count)

{

cout<<"B";

}

else

{

cout<<"Coalition government";

}

}