class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;

        // If the number is prime or not ?
        auto isPrime = [](int num)
        {
            if (num < 2)
                return false;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        };

        // traversing and inserting the value if condition is satisfied
        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
            {
                primes.push_back(i);
            }
        }

        // If less than two primes found
        if (primes.size() < 2)
            return {-1, -1};

        // To find the closest pair
        int minDiff = INT_MAX;
        vector<int> result(2, -1);

        for (size_t i = 1; i < primes.size(); i++)
        {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff)
            {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};