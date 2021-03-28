
import copy
import random
find = 0


def is_sorted(stack):
	arr = stack.copy()
	arr.sort()
	l = len(stack)
	for i in range(l):
		if arr[i] != stack[i]:
			return 0
	return 1


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


def get_all_prob(stack, last, dept, stack_list):
	tab = []
	if last != 1:
		s = swap(stack.copy())
		if s not in stack_list:
			tab.append([s, 1, dept + 1, 0])
			stack_list.append(s)
	if last != 3:
		s = rotate(stack.copy())
		if s not in stack_list:
			tab.append([s, 2, dept + 1, 0])
			stack_list.append(s)

	if last != 2:
		s = reverse_rotate(stack.copy())
		if s not in stack_list:
			tab.append([s, 3, dept + 1,0])
			stack_list.append(s)

	return tab



def push_swap(last, next_move, visited, stack_list):
	stack = next_move[0][0]
	dept = next_move[0][2]
	next_move.pop(0)
	tab = get_all_prob(stack, last, dept, stack_list)
	for s in tab:
		t = s[0]
		mv = s[1]
		d = s[2]
		if is_sorted(t):
			print("HEY I AM HER ",t, d)
			return 1
		next_move.append(s)
	return 0


range_number = 5
count_operation = 0
stack_a = random.sample(range(range_number), range_number)
stack_b = []
next_move = []
visited = []
next_move.append([stack_a, 0, 0, 0])
ret = 0
print("0_0_stack_a", stack_a)
print('-------------------------------------')
move = 0
t = 0
stack_list = []
stack_list.append(stack_a)
time_to_evaluate = 2  * range_number
while len(next_move) and ret == 0:
	ret = push_swap(0, next_move, visited, stack_list)
