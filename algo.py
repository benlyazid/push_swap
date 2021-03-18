
import copy
import random
find = 0
def is_sorted():
	arr = stack_a.copy()
	arr.sort()
	l = len(stack_a)
	for i in range(l):
		if arr[i] != stack_a[i]:
			return 0
	return 1
		
def swap(index):
	global count_operation
	if index == 1 or  index == 3:
		save = stack_a[0]
		stack_a[0] = stack_a[1]
		stack_a[1] = save
	if index == 2 or index == 3:
		save = stack_b[0]
		stack_b[0] = stack_b[1]
		stack_b[1] = save
	count_operation += 1

def rotate(index):
	global count_operation
	l = len(stack_a) - 1
	if index == 1 or index == 3:
		ferst = stack_a[0]
		stack_a.remove(ferst)
		stack_a.insert(l, ferst)
	if index == 2 or index == 3:
		ferst = stack_b[0]
		stack_b.remove(ferst)
		stack_b.insert(l, ferst)
	count_operation += 1

def reverse_rotate(index):
	global count_operation
	if index == 1 or index == 3:
		last = stack_a[-1]
		stack_a.remove(last)
		stack_a.insert(0, last)
	if index == 2 or index == 3:
		last = stack_b[-1]
		stack_b.remove(last)
		stack_b.insert(0, last)
	count_operation += 1

def	push_to(index):
	global count_operation

	if index == 1:
		value = stack_b[0]
		stack_a.insert(0, value)
		stack_b.remove(value)
	if index == 2:
		value = stack_a[0]
		stack_b.insert(0, value)
		stack_a.remove(value)
	count_operation += 1


def make_operation(index, number):
	global find
	mid = len(stack_a) / 2
	srt = stack_a.copy()
	srt.sort()
	index_0 = stack_a.index(srt[0])
	index_1 = stack_a.index(srt[1])
	if (abs(mid - index_0) > abs(mid - index_1)) or find == 1:
		index = index_0
		find  = 0
	else:
		index = index_1
		find = 1
	while index != 0:
		if index <= mid:
			rotate(1)
		else:
			reverse_rotate(1) 
		index = stack_a.index(number)
	push_to(2)



def is_in_min_range(number):
	global mx, mn
	
	mx_dst = abs(sorted_stack_a.index(mx) - sorted_stack_a.index(number))
	mn_dst = abs(sorted_stack_a.index(mn) - sorted_stack_a.index(number))
	if mn_dst > mx_dst :
		return 0
	return 1

def	chose_next_number(search_range):
	arr = []
	l = len(stack_a)
	a = search_range[0]
	if l > a and is_in_min_range(stack_a[a]):
		arr.append(stack_a[0])

	a = search_range[1]
	if l > a and is_in_min_range(stack_a[a]):
		arr.append(stack_a[1])

	a = search_range[2]
	a = len(stack_a) + a

	if l > a and is_in_min_range(stack_a[a]):
		arr.append(stack_a[a])
	if len(arr) == 0:
		return -1;
	return (min(arr))


def push_swap():
	while len(stack_a):
		if  is_sorted():
				break
		next_index = stack_a.index(min(stack_a))
		make_operation(next_index, stack_a[next_index])
		if  len(stack_b) > 1 and stack_b[0] < stack_b[1]:
			if len(stack_a) > 1 and  stack_a[0] > stack_a[1]:
				swap(3)
			else:
				swap(2)
	while(len(stack_b)):
		push_to(1)

reapet = 10
average = 0
for i in range(reapet):
	count_operation = 0
	range_number = 5
	stack_a = random.sample(range(range_number), range_number)
	#stack_a = [5, 2, 4, 1, 7, 3, 9, 6, 8]
	sorted_stack_a = stack_a.copy()
	sorted_stack_a.sort()
	stack_b = []
	mx = max(sorted_stack_a)
	mn = min(sorted_stack_a)
	print("stack_a", stack_a)
	#print('-----------------------------------------')
	#print("stack_b", stack_b)
	push_swap()
	print("stack_a", stack_a)

	print(count_operation)

	average += count_operation
print("average = {}", average / reapet)