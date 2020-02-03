from matplotlib import pyplot as plt

s_file = open('./benchmarking/stl_cpp.txt', 'r')
m_file = open('./benchmarking/merge_cpp.txt', 'r')
i_file = open('./benchmarking/insertion_cpp.txt', 'r')
q_file = open('./benchmarking/quick_cpp.txt', 'r')

stl_cpp = [float(line.rstrip()) for line in s_file]
merge_cpp = [float(line.rstrip()) for line in m_file]
insertion_cpp = [float(line.rstrip()) for line in i_file]
quick_cpp = [float(line.rstrip()) for line in q_file]

# Each input size.
x_axis = [(x*10) for x in range(1, 100)]

plt.figure(figsize=(15, 8))

plt.plot(x_axis, stl_cpp, label='CPP STL')
plt.plot(x_axis, merge_cpp, label='CPP Merge')
plt.plot(x_axis, insertion_cpp, label='CPP Insertion')
plt.plot(x_axis, quick_cpp, label='CPP QUICK')

#plt.axis([0, 400, 0, .1])
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.ylabel('Time (ms)')
plt.xlabel('Input size')
plt.show()
