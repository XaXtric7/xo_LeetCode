class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time}); // from this start point it will take this much time to reach the target
        }
        sort(cars.begin(), cars.end(), greater<>()); // descending

        int fleets = 0;
        double prevTime = 0;
        for (auto &car : cars)
        {
            double currTime = car.second;
            if (currTime > prevTime)
            {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};