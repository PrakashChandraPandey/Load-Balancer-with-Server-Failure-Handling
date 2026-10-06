// ROUND ROBIN ALGORITHM
//LoadBalancingAlgorithm base class and Server class

class RoundRobin : public LoadBalancingAlgorithm
{
private:
    int currentIndex;

public:
    RoundRobin()
    {
        currentIndex = 0;
    }

    int selectServer()
    {
        if (servers == nullptr || servers->empty())
            return -1;

        int totalServers = servers->size();

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
