class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 1) {
            return 1;
        }

        // translate to pairs
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i] = { position[i], speed[i] };
        }

        // sort pairs based on starting position
        sort(cars.begin(), cars.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });

        // get expected end times
        vector<double> dest(position.size());
        for (int i = 0; i < position.size(); i++) {

        }

        // iterate backwards, counting 'groups'
        int groups = 0;
        double fleetTime = 0;
        for (int i = 0; i < dest.size(); i++) {
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
