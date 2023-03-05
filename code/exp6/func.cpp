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
    printf("\t\t\txhw-��ѧ����-exp6\n");
    printf("����ѧ������: ");
    scanf("%d", &all_terms);
    printf("������ѧ�ڵ�ѧ������: ");
    scanf("%d", &t_max_xf);
    printf("�������ѧ�ƻ��Ŀγ���: ");
    scanf("%d", &t_V);
    printf("����������γ̵����޿γ̵��ܺ�(������): ");
    scanf("%d", &t_E);
    printf("������%d���γ̵Ŀγ̺�(���30���ַ�,Сд��ĸc+������c10)\n", t_V);
    node data;
    for (i = 1; i <= t_V; i++)
    {
        printf("�������%d��: ", i);
        scanf(" %s", data.name);
        G[i].push_back(data);
        mp[G[i][0].name] = i;
    }
    printf("������%d���γ̷ֱ��Ӧ��ѧ��ֵ:\n", t_V);
    for (i = 1; i <= t_V; i++) scanf("%d", &G[i][0].xf);
    printf("���������пγ̵����޿γ�(������#����)\n");
    char s[33];
    for (i = 1; i <= t_V; i++)
    {
        printf(" %s�����޿γ�: ", G[i][0].name);
        while (true)
        {
            scanf(" %s", s);
            if (s[0] == '#') break;
            G[i].push_back(G[mp[s]][0]);
        }
    }
    printf("\t\t\t¼�����ݳɹ�\n");
}

void display()
{
    int i, j;
    printf("����ͼ\n");
    printf("%d������", t_V);
    for (i = 1; i <= t_V; ++i) printf("%s%c", G[i][0].name, i == t_V ? '\n' : ' ');
    printf("%d������:\n", t_E);
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
        printf("\n��%d��ѧ��Ӧѧ�γ�: ", q);
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
        printf("\n��%d��ѧ��Ӧѧ�γ�: ", q);
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
            printf("\n\t\t\t��ѡ����:\n");
            printf("\t\t\t1.����\n");
            printf("\t\t\t2.����\n");
            printf("\t\t\t3.�˳�\n");
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