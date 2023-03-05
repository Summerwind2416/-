#include<iostream>
#include<map>
#include<vector>
#include<stack>
#pragma warning(disable:4996)
using namespace std;

struct node
{
    char name[33];
    int xf;
};

int all_terms, t_max_xf, t_V, t_E;
vector<node> G[1009];
map<string, int> mp;

void create_graph()
{
    int i;
    printf("\t\t\txhw-教学编制-exp6\n");
    printf("输入学期总数: ");
    scanf("%d", &all_terms);
    printf("请输入学期的学分上限: ");
    scanf("%d", &t_max_xf);
    printf("请输入教学计划的课程数: ");
    scanf("%d", &t_V);
    printf("请输入各个课程的先修课程的总和(边总数): ");
    scanf("%d", &t_E);
    printf("请输入%d个课程的课程号(最多30个字符,小写字母c+数字如c10)\n", t_V);
    node data;
    for (i = 1; i <= t_V; i++)
    {
        printf("请输入第%d个: ", i);
        scanf(" %s", data.name);
        G[i].push_back(data);
        mp[G[i][0].name] = i;
    }
    printf("请输入%d个课程分别对应的学分值:\n", t_V);
    for (i = 1; i <= t_V; i++) scanf("%d", &G[i][0].xf);
    printf("请输入下列课程的先修课程(输入以#结束)\n");
    char s[33];
    for (i = 1; i <= t_V; i++)
    {
        printf(" %s的先修课程: ", G[i][0].name);
        while (true)
        {
            scanf(" %s", s);
            if (s[0] == '#') break;
            G[i].push_back(G[mp[s]][0]);
        }
    }
    printf("\t\t\t录入数据成功\n");
}

void display()
{
    int i, j;
    printf("有向图\n");
    printf("%d个顶点", t_V);
    for (i = 1; i <= t_V; ++i) printf("%s%c", G[i][0].name, i == t_V ? '\n' : ' ');
    printf("%d条弧边:\n", t_E);
    for (i = 1; i <= t_V; i++)
    {
        int k = G[i].size();
        for (j = 0; j < k; j++)
            printf("%s---->%s\n", G[i][0].name, G[i][j].name);
    }
}

void solve1(int ans[])
{
    int q = 1, cnt = 0;
    while (q <= all_terms)
    {
        int num = t_V / all_terms;
        printf("\n第%d个学期应学课程: ", q);
        while (num--)
        {
            printf("%s%c", G[ans[cnt++]][0].name, num != 0 ? ' ' : '\n');
        }
        if (q == all_terms) printf("OK Over!\n");
        q++;
    }
}

void solve2(int ans[])
{
    int q = 1, cnt = 0;
    while (q <= all_terms)
    {
        int C = G[ans[cnt]][0].xf;
        printf("\n第%d个学期应学课程: ", q);
        while (cnt < t_V && C <= t_max_xf)
        {
            printf("%s ", G[ans[cnt]][0].name);
            if (cnt + 1 < t_V) C = C + G[ans[cnt + 1]][0].xf;
            cnt++;
        }
        if (cnt >= t_V || q == all_terms)
        {
            cout << endl;
            printf("OK Over!\n");
            break;
        }
        q++;
    }
}

void topo_sort()
{
    int i, j, vis[1009];
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= t_V; i++)
    {
        int k = G[i].size();
        for (j = 1; j < k; j++)
            vis[mp[G[i][j].name]]++;
    }
    int ans[1009], cnt = 0;
    memset(ans, 0, sizeof(ans));
    stack<int> s;
    for (i = 1; i <= t_V; i++)
    {
        if (!vis[i]) s.push(i);
    }
    while (!s.empty())
    {
        int cur = s.top(); s.pop();
        ans[cnt++] = cur;
        int k = G[cur].size();
        for (j = 1; j < k; j++)
        {
            int num = mp[G[cur][j].name];
            vis[num]--;
            if (!vis[num]) s.push(num);
        }
    }
    if (cnt != t_V) puts("Error!");
    else
    {
        puts("OK!");
        while (true)
        {
            printf("\n\t\t\t请选择功能:\n");
            printf("\t\t\t1.均匀\n");
            printf("\t\t\t2.集中\n");
            printf("\t\t\t3.退出\n");
            int sel;
            scanf("%d", &sel);
            switch (sel)
            {
            case 1: solve1(ans); break;
            case 2: solve2(ans); break;
            }
            if (sel == 3) break;
        }
    }
}

int main()
{
    create_graph();
    display();
    topo_sort();
    return 0;
}


/*
6
10
12
16
c1
c2
c3
c4
c5
c6
c7
c8
c9
c10
c11
c12
2 3 4 3 2 3 4 4 7 5 2 3
#
c1 #
c1 c2 #
c1 #
c3 #
c11 #
c5 c3 #
c3 c6 #
#
c9 #
c9 #
c9 c10 c1 #
*/