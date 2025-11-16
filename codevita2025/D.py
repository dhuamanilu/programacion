
import sys
from collections import defaultdict, deque

data = [line.strip() for line in sys.stdin.read().splitlines() if line.strip() != ""]
n = int(data[0]); 
i = 1
adj = defaultdict(set)
for _ in range(n):
    parts = data[i].split(); 
    i += 1
    
    a, *neigh = parts
    for b in neigh:
        adj[a].add(b)
        adj[b].add(a)

q = int(data[i]); 
i += 1
queries = []
for _ in range(q):
    parts = data[i].split(); 
    i += 1
    queries.append((parts[0], parts[1], parts[2]))

r = int(data[i]); 
i += 1
banned = defaultdict(set)
for _ in range(r):
    parts = data[i].split(); 
    i += 1
    if not parts:
        continue
    src, *blocked = parts
    for b in blocked:
        banned[src].add(b)

def reachable(src, dst):
    if src == dst:
        return True
    forb = banned.get(src, set())
    if dst in forb:
        return False
    seen = {src}
    dq = deque([src])
    while dq:
        u = dq.popleft()
        for v in adj.get(u, ()):
            if v in seen: 
                continue
            if v in forb:
                continue
            if v == dst:
                return True
            seen.add(v)
            dq.append(v)
    return False

out = []
for a, typ, b in queries:
    if typ == "to":
        out.append("yes" if reachable(a, b) else "no")
    elif typ == "connects":
        adj[a].add(b)
        adj[b].add(a)
    elif typ == "disconnects":
        adj[a].discard(b)
        adj[b].discard(a)
    else:
        pass

sys.stdout.write("\n".join(out))

