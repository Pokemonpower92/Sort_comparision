import matplotlib.pyplot as plt

s_file = open('./benchmarking/stl_cpp.txt', 'r')
m_file = open('./benchmarking/merge_cpp.txt', 'r')
i_file = open('./benchmarking/insertion_cpp.txt', 'r')

stl_cpp = [float(line.rstrip('\n')) for line in s_file]
merge_cpp = [float(line.rstrip('\n')) for line in m_file]
insertion_cpp = [float(line.rstrip('\n')) for line in i_file]

# Number of elements
x_axis = [(x**2) for x in range(1, 151)]

plt.figure(figsize=(8, 5))

plt.plot(x_axis, stl_cpp, label='C STL')
plt.plot(x_axis, merge_cpp, label='C Merge')
plt.plot(x_axis, insertion_cpp, label='C Insertion')


#plt.axis([0, 151**2, 0, 200000])
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.ylabel('Time (ms)')
plt.xlabel('Input size')
plt.show()

# time (in miliseconds)
