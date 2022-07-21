import csv

inFile = input()
outFile = inFile[:-3]+"txt"

with open(inFile, 'r') as file:
    reader = csv.reader(file)
    reader = list(reader)
    adj = []
    for i in range(1, len(reader)):
        tmp = []
        for j in range(1, len(reader[i])):
            tmp.append(float(reader[i][j]))
        adj.append(tmp)

with open(outFile, 'w') as file:
    print(len(adj), file = file)
    for row in adj:
        print(*row, file = file)
