class MinStack {
public:
stack<pair<int,int>>st;
int top_stack;
    MinStack() {
     top_stack=-1;   
    }
    
    void push(int val) {
        if(st.empty()){
        st.push({val,val});
     }
     else if(!st.empty() && st.top().second>val){
        st.push({val,val});
      }  
     else{
st.push({val,st.top().second});
     }
        
     
    }
    
    void pop() {
       if(st.empty())return;

       st.pop(); 
    }
    
    int top() {
         if(st.empty())return 0;
      return st.top().first;  
    }
    
    int getMin() {
         if(st.empty())return 0;
       return st.top().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */