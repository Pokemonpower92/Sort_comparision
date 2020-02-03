# Generates the random input files
# for benchmarking

import random

fout = open('io/rand_input.txt', 'w')

for i in range(1, 100):
    for x in range(1, 3):
        for y in range(i*10):
                if y != i*10-1:
                    fout.write(str(random.randint(0, 10000)) + ' ')
                else:
                    fout.write(str(random.randint(0, 10000)) + ' \n')

fout.close()
