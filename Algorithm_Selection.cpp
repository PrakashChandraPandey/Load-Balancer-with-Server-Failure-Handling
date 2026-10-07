//ALGORITHM SELECTION

void selectAlgorithm(LoadBalancer &loadBalancer)
{
    int choice;

    cout << "\n========================================\n";
    cout << "       SELECT LOAD BALANCING ALGORITHM\n";
    cout << "========================================\n";
    cout << "1. Round Robin\n";
    cout << "2. Weighted Round Robin\n";
    cout << "3. Least Connections\n";
    cout << "4. Resource Based Algorithm\n";

    cout << "\nEnter choice: ";
    cin >> choice;

    loadBalancer.setAlgorithm(choice);
}
