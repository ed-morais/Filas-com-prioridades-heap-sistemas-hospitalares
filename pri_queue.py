from queue import PriorityQueue
from unicodedata import name
q = PriorityQueue()


name = input("Enter name: ")
priority = int(input("Enter priority: "))
q.put((priority, name))


next = q.get()
print(next)

print(q.empty())
print(q.full())

q.put((3, "Collins"))
print(q.get())

while not q.empty():
     print(q.get())

print(q.empty())