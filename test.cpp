#include <iostream>
using namespace std;

typedef pair<int, int> p; // 定义 pair 类型，表示 <边权, 节点>

struct node {
	int w, v; // w 表示目标节点，v 表示边权
};

int n, m, ans; // n: 节点数, m: 边数, ans: 最小生成树的总权值
vector<node> g[5100]; // 使用vector存储图，每个节点存储若干边
int vis[5100]; // 标记节点是否已访问，1 表示访问过，0 表示未访问

int prim()
{
	priority_queue<p, vector<p>, greater<p>> q; // 最小堆，存储 <边权, 节点>
	q.push({0, 1});  // 从节点 1 开始，初始边权为 0
	int num = 0; // 记录已访问节点的数量
	while (q.empty() == false and num < n) // 当队列非空且未访问完所有节点时循环
	{
		p t = q.top(); // 取出最小边权对应的节点
		q.pop();
		int edge = t.first, to = t.second; // edge 表示边权, to 表示目标节点
		if (vis[to] == 0) // 如果目标节点未被访问
		{
			vis[to] = 1; // 标记目标节点为已访问
			num++; // 已访问节点数加 1
			ans += edge; // 累加边权到总权值
			for (auto i : g[to]) // 遍历目标节点的所有邻接边
				if (vis[i.w] == 0) // 如果邻接节点未访问
					q.push({i.v, i.w}); // 将邻接边的边权和目标节点加入优先队列
		}
	}
	if (num != n) // 如果已访问节点数不等于总节点数，说明图不连通
		cout << "orz"; // 输出 "orz" 表示无法构造最小生成树
	else
		cout << ans; // 输出最小生成树的总权值
	return 0;
}

int main()
{
    cin >> n >> m; // 输入节点数和边数
	for (int i = 1; i <= m; i++) // 读取所有边的信息
	{
		int x, y, z; // x 和 y 表示两个节点，z 表示边权
		cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z}); // 无向图存储
	}
	prim(); 
	return 0; 
}
