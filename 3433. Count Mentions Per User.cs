public class Solution
{
    public int[] CountMentions(int numberOfUsers, IList<IList<string>> events)
    {
       events = events
            .OrderBy(e => int.Parse(e[1]))
            .ThenBy(e => e[0] == "OFFLINE" ? 0 : 1)
            .ToList();

        var offlineUntil = new Dictionary<int, int>();
        var ans = new int[numberOfUsers];

        foreach (var e in events)
        {
            var eventType = e[0];
            var timestamp = e[1];
            var users = e[2];

            int t = int.Parse(timestamp);

            if (eventType == "MESSAGE")
            {
                if (users == "ALL")
                {
                    for (int i = 0; i < numberOfUsers; i++) ans[i]++;
                }

                else if (users == "HERE")
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        if (!offlineUntil.TryGetValue(i, out var until) || until <= t) {
                            ans[i]++;
                        }
                    }
                }

                else
                {
                    foreach (var token in users.Split(' ', StringSplitOptions.RemoveEmptyEntries))
                    {
                        int id = int.Parse(token.AsSpan(2));
                        ans[id]++;
                    }
                }
            }

            else // OFFLINE
            {
                int id = int.Parse(users);
                offlineUntil[id] = t + 60;
            }
        }

        return ans;
    }
}
