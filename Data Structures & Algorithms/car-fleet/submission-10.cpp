class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        if (size == 1) {
            return 1;
        }

        // translate to pairs
        vector<pair<int, int>> cars(size);
        for (int i = 0; i < size; i++) {
            cars[i] = { position[i], speed[i] };
        }

        // sort pairs based on starting position -> end to front
        sort(cars.rbegin(), cars.rend());

        // iterate forwards, counting 'groups'
        int groups = 0;
        double fleetTime = 0;
        for (int i = 0; i < size; i++) {
            double endTime = (double)(target - cars[i].first) / cars[i].second;

            if (endTime <= fleetTime) {
                continue;
            }

            groups++;
            fleetTime = endTime;
        }

        return groups;

    }
};
