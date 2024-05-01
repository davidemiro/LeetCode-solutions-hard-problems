class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        jobs.sort(reverse=True)
        workers.sort(reverse=True)

        min_day = 1

        for job,worker in zip(jobs,workers):
            day = (job // worker)
            if job % worker != 0:
                day += 1
            if min_day < day:
                min_day = day
        
        return min_day

        