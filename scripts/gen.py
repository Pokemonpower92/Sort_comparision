# Generates the random input files
# for benchmarking

import random

j = 1

fout = open('io/rand_input.txt', 'w')

while j < 701:
    for x in range(1, 3):
        for y in range(j*10):
                if y != j*10 - 1:
                    fout.write(str(random.randint(0, 1000))+' ')
                else:
                    fout.write(str(random.randint(0, 1000))+' \n')
    j+=1

fout.close()
