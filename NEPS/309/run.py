import os
import subprocess

for i in range(0, 11):
    print(i, end=' ')
    for (dirpath, dirnames, filenames) in os.walk(f'2011f2pj_gincana/{i}'):
        for j in range(0, 11):
            print(filenames)
            if f'in{j}' in filenames:
                os.system(f'g++ main.cpp -o main && ./main < 2011f2pj_gincana/{i}/in{j} > 2011f2pj_gincana/{i}/my-{j}.out')
                os.system(f'diff 2011f2pj_gincana/{i}/out{j} 2011f2pj_gincana/{i}/my-{j}.out > 2011f2pj_gincana/{i}/diff-{j}.out')



