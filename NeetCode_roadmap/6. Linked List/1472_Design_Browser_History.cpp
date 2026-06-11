class BrowserHistory
{
public:
    stack<string> history;
    stack<string> future;

    BrowserHistory(string homepage)
    {
        history.push(homepage);
        // future stack is implicitly empty
    }

    void visit(string url)
    {
        history.push(url);
        // Clear the forward history
        future = stack<string>();
    }

    string back(int steps)
    {
        while (steps > 0 && history.size() > 1)
        {
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }

    string forward(int steps)
    {
        while (steps > 0 && !future.empty())
        {
            history.push(future.top());
            future.pop();
            steps--;
        }
        // Return the current page (top of history)
        return history.top();
    }
};