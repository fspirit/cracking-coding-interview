### Topological sort

Key ideas:

- Use DFS
- Put processed nodes into stack once all children are processed
- As an output you will get stack with items to begin with on top and last to do items on bottom


```
dfs(graph g, vertex s, stack result) {
	mark s as explored
	for every edge outgoing from s {s, v} {
		if v not explored {
			dfs(g, v)
		}
	}
	result.push(s);
}

dfs-loop(graph g) {
	mark all nodes as unexplored
	stack result
	for each v in g {
		if v not explored {
			dfs(g, v, result)
		}
	}
}
```
