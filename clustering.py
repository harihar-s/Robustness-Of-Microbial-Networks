import networkx as nx

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

for i in range (1, N+1):
    G.add_node(i)

for i in range(0,N):
    for j in range(0,N):
        if adjM[i][j]!=0.0:
            G.add_edge(i+1, j+1, weight = adjM[i][j])

print("Transitivity Coefficient")
print(nx.transitivity(G))
print("Clustering Coefficient Of Each Node")
print(nx.clustering(G, weight = "weight"))
print("\n\n Average Clustering Coefficient: ")
print(nx.average_clustering(G, weight = "weight"))

