import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums.sort()

        count = 1
        pq = []

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                if len(pq) < k:
                    heapq.heappush(pq, (count, nums[i - 1]))
                else:
                    if pq[0][0] < count:
                        heapq.heappop(pq)
                        heapq.heappush(pq, (count, nums[i - 1]))

                count = 1

        if len(pq) < k:
            heapq.heappush(pq, (count, nums[-1]))
        elif pq[0][0] < count:
            heapq.heappop(pq)
            heapq.heappush(pq, (count, nums[-1]))

        ans = []

        while pq:
            count, num = heapq.heappop(pq)
            ans.append(num)

        return ans

