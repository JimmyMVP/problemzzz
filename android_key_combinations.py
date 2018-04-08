#Find number of combinations on android phone

#Define adjacency list for the lock screen



#   0   1   2
#   
#   3   4   5
#
#   6   7   8
#
adj_lists = [

    [1,4,3,5,7],
    [0,2,3,4,5,6,8],
    [1,3,4,5,7],
    [0,1,2,4,7,8,6],
    [0,1,2,3,5,6,7,8],
    [1,2,4,7,8,6,0],
    [3,4,7,1,5],
    [6,3,4,5,8,2,0],
    [7,4,5,1,3]

]

# Do depth first search

visited = [False]*9
def compute_combinations(node):

    if visited[node]:
        return 0

    visited[node] = True

    counter = 0
    for n in adj_lists[node]:
        counter += 1 + compute_combinations(n)

    visited[node] = False
    return counter





counter = compute_combinations(0)*4 + compute_combinations(1)*4 + compute_combinations(4)

print('Number of combinations on android lock screeen: ', counter)








