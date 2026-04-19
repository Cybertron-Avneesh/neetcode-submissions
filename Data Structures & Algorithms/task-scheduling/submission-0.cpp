class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i=0; i<tasks.size(); i++){
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end());
        int mxFq = count[25];
        int idleSlots = (mxFq - 1) * n;
        // try to fill these idle slots with remaining tasks
        // if idle<=0 that means all idle spaces were covered -> not extra idle time needed,
        // else add this extra idle time in total number of tasks
        for(int i=0; i<=24; i++){
            // if task i has frequency of c
            // we only assign it to mxFq-1 places
            // so we can only assign maximum of mxFq-1 slots to this tasks
            idleSlots -= min(count[i], mxFq - 1);
        }
        return max(0, idleSlots) + tasks.size();
    }
};
