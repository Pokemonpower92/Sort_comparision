from matplotlib import pyplot as plt

s_file = open('./benchmarking/stl_cpp.txt', 'r')
m_file = open('./benchmarking/merge_cpp.txt', 'r')
i_file = open('./benchmarking/insertion_cpp.txt', 'r')
sl_file = open('./benchmarking/selction_cpp.txt', 'r')

stl_cpp = [float(line.rstrip()) for line in s_file]
merge_cpp = [float(line.rstrip()) for line in m_file]
insertion_cpp = [float(line.rstrip()) for line in i_file]
selection_cpp = [float(line.rstrip()) for line in sl_file]

# Each input size.
x_axis = [(x*10) for x in range(1, 701)]

plt.figure(figsize=(15, 8))

plt.plot(x_axis, stl_cpp, label='CPP STL')
plt.plot(x_axis, merge_cpp, label='CPP Merge')
plt.plot(x_axis, insertion_cpp, label='CPP Insertion')
plt.plot(x_axis, selection_cpp, label='CPP Selection')

#plt.axis([0, 2000, 0, 1])
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.ylabel('Time (ms)')
plt.xlabel('Input size')
plt.show()
