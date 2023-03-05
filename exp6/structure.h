#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#define AVERAGE   1		//���Ȱ��Ų���
#define QUICKLY   0		//���찲�Ų���
#define MaxClass  99		//�γ�����������99
#define MaxTerm   12		//ѧ������������12
#define MaxCredit 30            //ÿѧ��ѧ�ֲ�����30


//   �ڽӱ��ʾ
typedef struct AdjVexNode {
    int AdjVex;			//�ڽӵ�λ��
    AdjVexNode* Next;		//ָ����һ���ڽӵ��ָ��
}AdjVexNode;				//�ڽӱ���


typedef struct {			//�������
    char data[3];			//�γ̱��
    int credit;			//�ڵ�ѧ�֣�ÿ�ſ�ѧ�֣�
    AdjVexNode* FirstArc;		//ָ���ڽӱ��һ���ڱ߽ڵ��ָ����
    int In_degree;			//�γ����
}VexNode;				//ͼ�ڵ�

typedef struct {
    int term_num;			//ѧ����
    int max_credit;			//ÿѧ��ѧ������
}Message;				//ѧ����Ϣ

typedef struct {
    VexNode* Vex;			//�ڵ�������
    int VexNum;			//�ڵ���
    Message* mes;			//ÿѧ�ڵ���Ϣ(�����޸�)
}Class_arrange_Graph;			//ͼ
#endif // STRUCTURE_H_INCLUDED
