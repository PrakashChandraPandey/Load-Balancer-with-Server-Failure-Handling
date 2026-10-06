// LEAST CONNECTIONS ALGORITHM
// LoadBalancingAlgorithm base class and Server class


class LeastConnections : public LoadBalancingAlgorithm
{
public:
    int selectServer()
    {
        if (servers == nullptr)
            return -1;

        int selectedServer = -1;
        int minimumLoad = INT_MAX;

        for (int i = 0; i < servers->size(); i++)
        {
            Server *server = (*servers)[i];

            if (!server->isActive())
                continue;

            if (server->isFull())
                continue;

            int currentLoad = server->getLoad();

            if (currentLoad < minimumLoad)
            {
                minimumLoad = currentLoad;
                selectedServer = i;
            }
        }

        return selectedServer;
    }
};
