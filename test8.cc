//用两个栈实现队列-》牛客网
//用两个栈实现队列，完成队列的push和pop操作。队列中元素为int

class Solution
{
    public:
        void push(int node) 
        {
            while(!stack2.empty())
            {
                int ret = stack2.top();
                stack1.push(ret);
                stack2.pop();
            }
            stack1.push(node);                        
        }

        int pop()
        {
            int res;
            while(!satck1.empty())
            {
                int ret = stack1.top();
                stack2.push(ret);
                stack1.pop();
            }
            if(!stack2.empty())
            {
                res = stack2.top();
                stack2.pop();
            }
            return res;
        }
    private:
        stack<int> stack1;//入队
        stack<int> stack2;//出队
}

