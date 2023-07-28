n = int(input()) #Number of processes
m = int(input()) #Number of resources

maxim = []
for i in range(n):
    a = []
    for j in range(m):
        a.append(int(input()))
    maxim.append(a)

alloc = []
for i in range(n):
    a = []
    for j in range(m):
        a.append(int(input()))
    alloc.append(a)

need = []
for i in range(n):
    a = []
    for j in range(m):
        a.append(maxim[i][j]-alloc[i][j])
    need.append(a)

total = []
for i in range(m):
    total.append(int(input()))

work = []
for i in range(m):
    sum = 0
    for j in range(n):
        sum = sum+alloc[j][i]
    work.append(total[i]-sum)

copyofwork = []
for i in range(m):
    copyofwork.append(work[i])

finish = []
for i in range(n):
    finish.append(0)


pid = 0
seq = []
while(True):
    #Loop Terminating Condition
    finished = True
    for i in range(n):
        if finish[i] == 0:
            finished = False
    if finished == True:
        print("The system is safe.")
        break
    #Select a process that is not finished yet
    else:
        while(True):
            if(finish[pid]==1):
                pid = (pid+1)%n
            else:
                break
        processable = True
        for j in range(m):
            if need[pid][j]>work[j]:
                processable = False
        if processable == True:
            seq.append('P'+str(pid))
            finish[pid] = 1
            for j in range(m):
                work[j] = work[j]+alloc[pid][j]
        pid = (pid+1)%n

print('\nMax      Alloc     Need      Avail')
flag = 1
for i in range(n):
    for j in range(m):
        print(maxim[i][j],end = ' ')
    print('   ',end = '')
    for j in range(m):
        print(alloc[i][j],end = ' ')
    print('    ',end = '')
    for j in range(m):
        print(need[i][j],end = ' ')
    print('    ',end = '')
    if flag==1:
        for j in range(m):
            print(copyofwork[j],end = ' ')
            flag = 0
    print("\n",end='')

print("\nSafe Sequence is : ",tuple(seq))
    