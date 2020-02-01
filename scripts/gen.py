# Generates the random input files
# for benchmarking

import random

j = 1

while j < 151:
    for x in range(1, 3):
        fout = open('io/rand'+str(j)+str(x)+'.txt', 'w')
        for y in range(j**2):
                fout.write(str(random.randint(0, 1000))+'\n')
        fout.close()
    j+=1
