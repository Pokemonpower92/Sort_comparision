# Generates the random input files
# for benchmarking

import random

fout = open('io/rand_input.txt', 'w')

for i in range(1, 11):
    for x in range(1, 2):
        for y in range(i*10000):
                if y != i*10000-1:
                    fout.write(str(random.randint(0, 1000)) + ' ')
                else:
                    fout.write(str(random.randint(0, 1000)) + ' \n')

fout.close()
