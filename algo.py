
def swap(index):
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
	if index == 1 or index == 3:
		ferst = stack_a[0]
		stack_a.remove(ferst)
		stack_a.insert(-1, ferst)
	if index == 2 or index == 3:
		ferst = stack_b[0]
		stack_b.remove(ferst)
		stack_b.insert(-1, ferst)
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

def make_operation(index):
	if index == 0:
		push_to(2)
	if index == 1:
		swap(1)
		push_to(2)
	if index == len(stack_a) - 1:
		reverse_rotate(1)
		push_to(2)

def is_in_min_range(number):
	mx = max(stack_a)
	mn = min(stack_a)
	srt = sorted(stack_a)
	mx_dst = abs(srt.index(mx) - srt.index(number))
	mn_dst = abs(srt.index(mn) - srt.index(number))
	if mn_dst > mx_dst :
		return 0
	return 1

def	chose_next_number():
	arr = []
	l = len(stack_a)
	if l > 0 and is_in_min_range(stack_a[0]):
		arr.append(stack_a[0])
	if l > 1 and is_in_min_range(stack_a[1]):
		arr.append(stack_a[1])
	if l > 2 and is_in_min_range(stack_a[-1]):
		arr.append(stack_a[-1])
	if len(arr) == 0:
		return -1;
	return (min(arr))

def push_swap():
	while True:
		next_number = chose_next_number()
		if next_number != -1:
			index = stack_a.index(next_number)
			make_operation(index)

		break

count_operation = 0
stack_a = [4,9,2,5,1]
stack_b = []
push_swap()
print(stack_a)
print(stack_b)
print(count_operation)
'''
reverse_rotate(1)
print(stack_a)
print(stack_b)
push_to(2)
print(stack_a)
print(stack_b)
swap(1)
print(stack_a)
print(stack_b)
reverse_rotate(1)
print(stack_a)
print(stack_b)
push_to(1)
print(stack_a)
print(stack_b)
'''
