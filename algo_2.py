
import copy
import random
find = 0
def	chose_best_one(tab):
	srt = stack_a.copy()
	srt.sort()
	tab_cost = []
	for t in tab:
		stack = t[0]
		cost = 0
		for i in range(len(stack)):                                                 
			num = stack[i]
			ii = srt.index(num)
			cost +=  abs(i - ii)

		tab_cost.append(cost)
		stack.append(cost)
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

def is_in_min_range(number):
	global mx, mn
	
	mx_dst = abs(sorted_stack_a.index(mx) - sorted_stack_a.index(number))
	mn_dst = abs(sorted_stack_a.index(mn) - sorted_stack_a.index(number))
	if mn_dst > mx_dst :
		return 0
	return 1

def get_all_prob(stack, last, dept):
	tab = []
	s = swap(stack.copy())
	tab.append([s, 1, dept + 1])
	if last != 3:
		s = rotate(stack.copy())
		tab.append([s, 2, dept + 1])
	if last != 2:
		s = reverse_rotate(stack.copy())
		tab.append([s, 3, dept + 1])
	return tab



def push_swap(last, next_move):
	stack = next_move[0][0]
	dept = next_move[0][2]
	#print("stack is :", stack)
	next_move.pop(0)
	print(stack)
	get_all_prob(stack, last, dept)
	print(stack)
	return 1
	for s in tab:
		t = s[0]
		mv = s[1]
		d = s[2]
		if is_sorted(t):
			print("HEY I AM HER ",t, d)
			return 1
		next_move.append(s)
	return 0
		




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
t = 5
print("0_0_stack_a", stack_a)
print('-------------------------------------')
move = 0

while len(next_move) and ret == 0:
	t -= 1
	ret = push_swap(0, next_move)
	move += 1
print(move)
	#print("next_stack_move", next_move)
	#print('-------------------------------------')
#print("stack_a", stack_a)

