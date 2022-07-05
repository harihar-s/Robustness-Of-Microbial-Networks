import networkx as nx
import random

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

G = nx.DiGraph()
H = nx.DiGraph()

for i in range (1, N+1):
    G.add_node(i)

for i in range(0,N):
    for j in range(0,N):
        if adjM[i][j]!=0.0:
            G.add_edge(i+1, j+1, weight = adjM[i][j])

breakdown = []
for num in range (0,10000):
    H = G.copy()
    vertex_set = [x for x in range(1, N+1)]
    while len(vertex_set)>0 and nx.is_weakly_connected(H) :
        u = random.choice(vertex_set)
        vertex_set.remove(u)
        H.remove_node(u)
    breakdown.append(N-len(vertex_set))

print(sum(breakdown)/len(breakdown))
