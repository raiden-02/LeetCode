class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        times = []
        ans = float('inf')
        for timePoint in timePoints:
            hour, mins = timePoint.split(':')
            hour, mins = int(hour), int(mins)
            print(hour, mins)
            totalMins = hour * 60 + mins
            times.append(totalMins)
    
        times.sort()

        for i in range(1, len(times)):
            diff = abs(times[i] - times[i - 1])
            ans = min(ans, min(diff, 1440 - diff))
        
        diff = abs(times[0] - times[-1])

        return min(ans, 1440 - diff)
