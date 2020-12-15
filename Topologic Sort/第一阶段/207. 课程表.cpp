/*
    BFS: 越早被访问到的顶点，其邻居越优先被选用
		
    先考虑没有入边其入度为０的节点，在这里相当于没有先修课程的课程．将它们先放入队列中，然后一个一个考虑它们的邻居，访问一次就将邻居的一个入度减１，表示与本节点毫无关系
    在这里就相当与，邻居少了一门先修课程的要求．如果邻居这时入度为０则表示这门课程也可以开始学习了，将其放入队列里．每一次出队列就相当与学了一门新课程visitednum++
    最后只要比较：visitednum和numcourses是否一样就行，如果不一样，则代表肯定是有环产生，因为不是所有的节点都访问到了．

    在广度优先搜索的每一步中，我们取出队首的节点 u：

	我们将 u 放入答案中；

	我们移除 u 的所有出边，也就是将 uu 的所有相邻节点的入度减少 1。如果某个相邻节点 v 的入度变为 0，那么我们就将 v 放入队列中。

	在广度优先搜索的过程结束后。如果答案中包含了这 n 个节点，那么我们就找到了一种拓扑排序，否则说明图中存在环，也就不存在拓扑排序了。

*/
class Solution
{
private:
	vector<vector<int>> edges;
	vector<int> indeg;

public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		//定义边和入度的初始容量有numcourses,因为最大的值就是numcourses,而顶点肯定有numcourses个，但并不是每个顶点之间都有关系
		edges.resize(numCourses);
		indeg.resize(numCourses);
		//将边的信息填入到edges　也就是关系，即u->v   就表示为　edges[u] = v,v可以有好几个如，１对２，３，４
		//将每个点的入度定义好
		for (auto p : prerequisites)
		{
			//p[1]指向p[0]
			edges[p[1]].push_back(p[0]);
			indeg[p[0]]++;
		}
		queue<int> q;
		//将入度为０的顶点加入到队列中
		for (int i = 0; i < indeg.size(); i++)
		{
			if (indeg[i] == 0)
				q.push(i);
		}
		int visitednum = 0;
		while (!q.empty())
		{
			visitednum++;
			int u = q.front();
			q.pop();
			for (int i = 0; i < edges[u].size(); i++)
			{
				int v = edges[u][i];
				indeg[v]--;
				if (indeg[v] == 0)
					q.push(v);
			}
		}
		if (visitednum == numCourses)
			return true;
		else
			return false;
	}
};
/*
	DFS:
*/

class Solution
{
private:
	vector<vector<int>> edges;
	//visited ０：未搜索．１：正在搜索．２：搜索完毕三种状态,默认初始值为０未搜索状态
	vector<int> visited;
	//valid表示当前图中是否有环，如果有环为false，默认初始值为true表示无环
	bool valid = true;

public:
	void dfs(int u)
	{
		visited[u] = 1;
		for (auto v : edges[u])
		{
			if (visited[v] == 0)
				dfs(v);
			if (!valid)
				return;
			else if (visited[v] == 1)
			{
				valid = false;
				return;
			}
		}
		visited[u] = 2;
		return;
	}

	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		edges.resize(numCourses);
		visited.resize(numCourses);
		for (auto p : prerequisites)
		{
			edges[p[1]].push_back(p[0]);
		}

		for (int i = 0; i < numCourses && valid; i++)
		{
			if (visited[i] == 0)
			{
				dfs(i);
			}
		}
		return valid;
	}
};