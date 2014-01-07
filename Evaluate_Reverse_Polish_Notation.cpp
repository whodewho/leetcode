class Solution {
	public:
		int evalRPN(vector<string> &tokens) {
			stack<int> stk;
			int result = 0;
			for(int i=0;i<tokens.size();i++)
			{
				if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
				{
					int num2 = stk.top();
					stk.pop();
					int num1 = stk.top();
					stk.pop();
					int result;
					if(tokens[i]=="+")result=num1+num2;
					else if(tokens[i]=="-")result=num1-num2;
					else if(tokens[i]=="*")result=num1*num2;
					else result=num1/num2;
					stk.push(result);
				}
				else
				{
					stk.push(stoi(tokens[i]));   
				}
			}

			return stk.top();
		}
};
