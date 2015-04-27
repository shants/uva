#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

bool isEscape(char c) {
if(c==' ' || c == ',' || c== '!' || c=='?' || c=='.')
    return true;
else 
    return false;
}

int main() 
{

while(1) 
{
    bool endLoop = false;
    string line = "";
    string done = "done";
    bool isPalin = true;
    while(getline(cin, line)) 
    {
	isPalin = true;
	endLoop = false;
	transform(line.begin(), line.end(), line.begin(), ::tolower);
	if(line.compare(done) == 0) { 
	   endLoop = true;  
	   break;
	}
	else
	{
	    int l = line.length()-1;
	    int i = 0;
	    while(i<=l) 
	    {
		if(isEscape(line[i])) {
		    i++;continue;
		}    
		if(isEscape(line[l])) {
		    --l;continue;
		}
		if(line[i] != line[l]) {
		    isPalin = false;
		     break; 
		}else{
		    ++i;--l;
		}
	    }
	    if(isPalin == false)
		cout<<"Uh oh..\n";  
	    else
		cout<< "You won't be eaten!\n";  
	}

    }

if(endLoop == true)
    break;
}

return 0;
}
