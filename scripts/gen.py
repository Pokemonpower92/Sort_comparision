import random

fout = open('io/rand31.txt', 'w')
for i in range(0, 30000):
    fout.write(str(random.randint(0, 1000))+'\n')

fout.close()
