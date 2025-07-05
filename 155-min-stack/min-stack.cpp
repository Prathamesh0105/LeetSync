class MinStack {
private:
  stack<int> st, minSt;


public:
  MinStack() {}
  
  void push(int val) {
    if(st.empty()){
      minSt.push(val);
    } 
    else {
      minSt.push(min(minSt.top(), val));
    }
    st.push(val);
  }
  
  void pop() {
    st.pop(); minSt.pop();
  }
  
  int top() {
    return st.top();
  }
  
  int getMin() {
    return minSt.top();
  }
};