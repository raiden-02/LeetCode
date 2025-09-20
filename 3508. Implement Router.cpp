struct Packet {
    int source, destination, timestamp;
};

class Router {
private:
    int capacity; // remaining capacity
    queue<Packet> q;
    unordered_set<string> packetSet;
    unordered_map<int, vector<int>> byDest;
    unordered_map<int, int> head; // per-destination head pointer

    string makeKey(int s, int d, int t) {
        return to_string(s) + ":" + to_string(d) + ":" + to_string(t);
    }

    void removeFromIndex(int dest, int ts) {
        auto &vec = byDest[dest];
        int &h = head[dest];
        if (h < (int)vec.size() && vec[h] == ts) {
            h++;
            if (h > 64) { // occasional compaction
                vec.erase(vec.begin(), vec.begin() + h);
                h = 0;
            }
        }
    }

    void evictIfFull() {
        if (capacity > 0) return;
        if (q.empty()) return;
        Packet ev = q.front(); q.pop();
        packetSet.erase(makeKey(ev.source, ev.destination, ev.timestamp));
        removeFromIndex(ev.destination, ev.timestamp);
        capacity++;
    }

public:
    Router(int memoryLimit) {
        capacity = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) return false;

        evictIfFull();

        q.push({source, destination, timestamp});
        packetSet.insert(key);
        byDest[destination].push_back(timestamp);
        capacity--;
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet pkt = q.front(); q.pop();
        packetSet.erase(makeKey(pkt.source, pkt.destination, pkt.timestamp));
        removeFromIndex(pkt.destination, pkt.timestamp);
        capacity++;
        return {pkt.source, pkt.destination, pkt.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!byDest.count(destination)) return 0;
        auto &vec = byDest[destination];
        int h = head[destination];
        if (h >= (int)vec.size()) return 0;

        auto itL = lower_bound(vec.begin() + h, vec.end(), startTime);
        if (itL == vec.end() || *itL > endTime) return 0;
        auto itR = upper_bound(vec.begin() + h, vec.end(), endTime);
        return (int)(itR - itL);
    }
};

/**
 * Example usage:
 * Router router(2);
 * cout << router.addPacket(1, 10, 100) << "\n"; // 1
 * cout << router.addPacket(2, 10, 200) << "\n"; // 1
 * cout << router.addPacket(3, 10, 300) << "\n"; // 1 -> evicts [1,10,100]
 * cout << router.getCount(10, 50, 250) << "\n"; // 1
 * auto fwd = router.forwardPacket();            // [2,10,200]
 * for (int x : fwd) cout << x << " "; cout << "\n";
 */
