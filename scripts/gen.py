fout = open('io/rand31.txt', 'w')

for i in range(10000, 0, -1):
    fout.write(str(i)+'\n')

fout.close()
