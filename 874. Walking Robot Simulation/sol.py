class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs_set = set()

        for obs in obstacles:
            obs_set.add((obs[0], obs[1]))

        rot = {}
        rot['N'] = {}
        rot['E'] = {}
        rot['S'] = {}
        rot['W'] = {}

        rot['N'][-2] = 'W'
        rot['N'][-1] = 'E'
        rot['E'][-2] = 'N'
        rot['E'][-1] = 'S'
        rot['S'][-2] = 'E'
        rot['S'][-1] = 'W'
        rot['W'][-2] = 'S'
        rot['W'][-1] = 'N'

        dirs = {}
        dirs['N'] = (0, 1)
        dirs['S'] = (0, -1)
        dirs['E'] = (1, 0)
        dirs['W'] = (-1, 0)

        cur_dir = 'N'
        cur_pos = [0, 0]
        ans = 0
        
        for command in commands:
            if command == -1 or command == -2:
                cur_dir = rot[cur_dir][command]
            
            else:
                steps = command
                cnt = 0
                while steps:
                    nextx, nexty = cur_pos[0] + dirs[cur_dir][0], cur_pos[1] + dirs[cur_dir][1]

                    if (nextx, nexty) in obs_set:
                        break
                    else:
                        cur_pos[0] = nextx
                        cur_pos[1] = nexty
                        ans = max(ans, nextx * nextx + nexty * nexty)

                    steps -= 1
                    cnt += 1

        return ans
