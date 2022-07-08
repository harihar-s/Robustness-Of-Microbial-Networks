import networkx as nx
from math import log10

dataFile = input("Enter the data file name: ")

adjM = []

with open(dataFile) as f:
    for line in f:
        row = []
        num = line.split(' ')
        for wt in num:
            row.append(float(wt))
        adjM.append(row)

N = int(adjM[0][0])
del adjM[0]

G = nx.Graph()

for i in range (1, N+1):
    G.add_node(i)

for i in range(0,N):
    for j in range(0,N):
        if adjM[i][j]!=0.0 and  (not G.has_edge(i+1, j+1)):
            G.add_edge(i+1, j+1)

nodes = [x for x in range(1,N+1)]
tmp = list(G.degree(nodes))
deg = [x for (i, x) in tmp]
deg2 = [x*x for x in deg]

pc = 1.0-1.0/(sum(deg2)*len(deg)/(sum(deg)*len(deg2))-1.0)

print("percolation threshold = "+str(pc))

pk = []

for x in range(0, N+1):
    if deg.count(x)!=0:
        pk.append(deg.count(x)/N)

H = 0.0
for x in pk:
    H = H - x*log10(x)

print("entropy = "+str(H))