// FOR THE  REQUEST PROCESSING
// Put this function inside the Server class.

void processRequest()
{
    if (!active || requestQueue.empty())
        return;

    Request &request = requestQueue.front();

    request.process();

    cout << "Server " << serverID
         << " processing Request "
         << request.getID()
         << " | Remaining Time: "
         << request.getRemainingTime()
         << endl;

    if (request.completed())
    {
        cout << "Request "
             << request.getID()
             << " completed on Server "
             << serverID << endl;

        requestQueue.pop();
    }
}
