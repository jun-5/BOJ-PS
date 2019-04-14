#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
int result;

int main(void) {

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ')') {

			st.pop();
			if (s[i-1] == '(') {
				result += st.size();
			
			}
			else if(s[i-1]==')'){
				result++;
			}
	
		}
		else {
		
			st.push(s[i]);
		
		}
		


	}
	printf("%d", result);
}