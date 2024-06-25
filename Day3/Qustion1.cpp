#include <iostream>
using namespace std;
#include <stack>

int main()
{

    string raj = "rajkumar";

    stack<char> temp;

    for (int i = 0; i < raj.length(); i++)
    {

        temp.push(raj[i]);
    }

    string ans = "";

    while (!temp.empty())
    {
        char ch = temp.top();
        cout << ch << " ";
        ans.push_back(ch);
        temp.pop();
    }

    cout << "answer is this " << ans;

    return 0;
}
