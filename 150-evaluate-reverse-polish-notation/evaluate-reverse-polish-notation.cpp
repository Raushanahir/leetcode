class Solution {
public:
    int evalRPN(vector<string>& arr) {

        stack<double>st;
        int n=arr.size();
        double k;
        
        for(auto it:arr){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                
                if(it=="+") k=a+b;
                else if(it=="-") k=b-a;
                else if(it=="*") k=a*b;
                else k=b/a;
                st.push(k);
                continue;
            }
            
            st.push(stoi(it));
        }

        return st.top();
    }
};