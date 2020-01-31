# Generates the random input files
# for benchmarking

import random

j = 1

while j < 8:
    for x in range(1, 4):
        fout = open('io/rand'+str(j)+str(x)+'.txt', 'w')
        for y in range(5**j):
                fout.write(str(random.randint(0, 1000))+'\n')
        fout.close()
    j+=1
