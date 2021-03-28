
import copy
import random
find = 0
def is_in_min_range(number):
	global mx, mn
	
	mx_dst = abs(sorted_stack_a.index(mx) - sorted_stack_a.index(number))
	mn_dst = abs(sorted_stack_a.index(mn) - sorted_stack_a.index(number))
	if mn_dst > mx_dst :
		return 0
	return 1


def	push_to(index, stack_1, stack_2):
	global count_operation

	if index == 1:
		value = stack_2[0]
		stack_1.insert(0, value)
		stack_2.remove(value)
	if index == 2:
		value = stack_1[0]
		stack_2.insert(0, value)
		stack_1.remove(value)
	count_operation += 1


def make_operation(index, number, stack_1, stack_2):
	global find
	mid = len(stack_1) / 2
	srt = stack_1.copy()
	srt.sort()
	find = 1
	while index != 0:
		if index <= mid:
			rotate(stack_1)
		else:
			reverse_rotate(stack_1) 
		index = stack_1.index(number)
	push_to(2, stack_1, stack_2)


'''def is_sorted(stack):
	arr = stack.copy()
	arr.sort()
	l = len(stack)
	for i in range(l):
		if arr[i] != stack[i]:
			return 0
	return 1'''
		
def swap(stack):
	global count_operation
	save = stack[0]
	stack[0] = stack[1]
	stack[1] = save
	count_operation += 1
	return stack

def rotate(stack):
	global count_operation
	l = len(stack) - 1
	ferst = stack[0]
	stack.remove(ferst)
	stack.insert(l, ferst)
	count_operation += 1
	return stack

def reverse_rotate(stack):
	global count_operation
	last = stack[-1]
	stack.remove(last)
	stack.insert(0, last)
	count_operation += 1
	return stack





def push_swap(last, next_move):
	stack_1 = stack_a.copy()
	stack_2 = stack_b.copy()
	while(len(stack_1)):
		mn = min(stack_1)
		make_operation(stack_1.index(mn), mn, stack_1, stack_2)
	print(stack_2)


		




count_operation = 0
range_number = 5
stack_a = random.sample(range(range_number), range_number)
#stack_a = [10, 7, 5, 8, 4, 11, 3, 6, 1, 9, 2, 0]
sorted_stack_a = stack_a.copy()
sorted_stack_a.sort()
stack_b = []
mx = max(sorted_stack_a)
mn = min(sorted_stack_a)
#print("stack_a", stack_a)
#print('-----------------------------------------')
#print("stack_b", stack_b)
next_move = []
visited = []
next_move.append([stack_a, 0, 0])
ret = 0

print("0_0_stack_a", stack_a)
print('-------------------------------------')
move = 0

while len(next_move):
	ret = push_swap(0, next_move)
	move += 1
print(count_operation)

