class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour_angle = (((hour % 12) + minutes / 60) / 12) * 360
        minute_angle = (minutes / 60) * 360

        diff = abs(hour_angle - minute_angle)
        return min(diff, 360 - diff)
