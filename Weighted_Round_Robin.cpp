//WEIGHTED ROUND ROBIN ALGORITHM
//LoadBalancingAlgorithm base class and Server class

class WeightedRoundRobin : public LoadBalancingAlgorithm
{
private:
    int currentIndex;

public:
    WeightedRoundRobin()
    {
        currentIndex = 0;
    }

    int selectServer()
    {
        if (servers == nullptr || servers->empty())
            return -1;

        int totalServers = servers->size();

        for (int round = 0; round < totalServers; round++)
        {
            int index = (currentIndex + round) % totalServers;
            Server *server = (*servers)[index];

            if (!server->isActive() || server->isFull())
                continue;

            int weight = server->getWeight();

            int randomValue = rand() % 10 + 1;

            if (randomValue <= weight * 2)
            {
                currentIndex = (index + 1) % totalServers;
                return index;
            }
        }

        // Fallback: select any available server
        for (int i = 0; i < totalServers; i++)
        {
            int index = (currentIndex + i) % totalServers;
            Server *server = (*servers)[index];

            if (server->isActive() && !server->isFull())
            {
                currentIndex = (index + 1) % totalServers;
                return index;
            }
        }

        return -1;
    }
};
