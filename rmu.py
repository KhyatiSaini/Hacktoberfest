# rate monotonic is for giving weekly goals to be scheduled 

class Process:
	def __init__(self,process_id,capacity, period = 24, arrival_time = 0, deadline=24):
		self.process_id = process_id
		self.capacity = capacity
		self.period = period
		self.arrival_time = arrival_time
		self.deadline = deadline


class Scheduler:
	def schedule(self,list_process):
		pass

class RMU_Scheduler(Scheduler):
	def __init__(self):
		self.name = "RMU_Scheduler"
	def schedule(self,list_process, total_slots):
		# list_process.sort(key = lambda x: x.period)
		# list_process.sort(key = lambda x: x.capacity)

		# for x in list_process:
			# print(x.id, x.capacity, x.period)
		week_schedule = []
		for available_slot in total_slots:
			sum_slots = sum(total_slots[available_slot])
			schedule = []

			for p in list_process:
				capacity = p.capacity
				process_id = p.process_id
				if sum_slots>0 and sum_slots>=capacity:
					sum_slots-=capacity
					while capacity>0:
						schedule.append(process_id)
						capacity -= 0.5
					# capacity = 0


				elif sum_slots>0 and sum_slots<capacity:
					capacity -= sum_slots
					while sum_slots>0:
						schedule.append(process_id)
						sum_slots -= 0.5

				if sum_slots==0:
					break

			week_schedule.append(schedule)
			# return schedule
		return week_schedule


# obj = RM_Scheduler()
# process1 = Process(1,2)
# process2 = Process(2,2)
# process3 = Process(3,3)
# slots = [[1,1,2,1,3],[.5, 1, 2.5, 1.5, 2], [1.5,1.5,1.5,1.5], [2,3,1], [1,1], [6], [7]]
# # slots = [1,1,2,1]
# list_process = [process1, process2, process3]
# final_schedule = obj.schedule(list_process, slots)
# print(final_schedule)
